#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QRandomGenerator>
#include <QSettings>
#include <QColorDialog>

namespace {
    // Indian palette
    const QColor TILE_LIGHT(170, 215, 81);    // lush green
    const QColor TILE_DARK(162, 209, 73);     // deeper green
    const QColor DEFAULT_SNAKE_BODY(69, 115, 232);   // bulu (used until the player picks a color)
    const QColor SNAKE_HEAD(128, 0, 32);     // maroon
    const QColor FOOD(226, 18, 126);         // rani pink

    const int TICK_START_MS = 400;           // delay per move at the start of a game
    const int TICK_STEP_MS  = 4;             // delay removed for every food eaten
    const int TICK_MIN_MS   = 50;            // fastest the snake can get

    // Saved preferences (like SharedPreferences in Java)
    const char *const PREFS_ORG   = "Takshak";
    const char *const PREFS_APP   = "SnakeGame";
    const char *const KEY_BEST    = "bestScore";
    const char *const KEY_COLOR   = "snakeBodyColor";
}

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    switchToScreen(Screen::MainMenu);

    ui->field->setSquareSize(32);
    ui->field->setDefaultColors(TILE_LIGHT, TILE_DARK);

    connect(&m_timer, &QTimer::timeout, this, &MainWindow::gameTick);

    loadPreferences();
    updateColorPreview();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::switchToScreen(Screen screen)
{
    ui->stackedWidget->setCurrentIndex(static_cast<int>(screen));
}

void MainWindow::on_pushButton_clicked()
{
    startGame();
}

void MainWindow::on_pushButton_2_clicked()
{
    switchToScreen(Screen::Settings);
}

void MainWindow::on_buttonBack_clicked()
{
    switchToScreen(Screen::MainMenu);
}

void MainWindow::on_buttonPickColor_clicked()
{
    const QColor chosen = QColorDialog::getColor(m_snakeBody, this, "Choose snake body color");
    if (!chosen.isValid())
        return;                          // dialog cancelled

    m_snakeBody = chosen;
    saveSnakeColor();
    updateColorPreview();
}

void MainWindow::on_buttonResetColor_clicked()
{
    m_snakeBody = DEFAULT_SNAKE_BODY;
    saveSnakeColor();
    updateColorPreview();
}

// ---------------------------------------------------------------- saved preferences

void MainWindow::loadPreferences()
{
    QSettings prefs(PREFS_ORG, PREFS_APP);

    m_bestScore = prefs.value(KEY_BEST, 0).toInt();

    const QColor saved(prefs.value(KEY_COLOR, DEFAULT_SNAKE_BODY.name()).toString());
    m_snakeBody = saved.isValid() ? saved : DEFAULT_SNAKE_BODY;

    ui->labelBest->setText(QString::number(m_bestScore));
}

void MainWindow::saveBestScore()
{
    QSettings prefs(PREFS_ORG, PREFS_APP);
    prefs.setValue(KEY_BEST, m_bestScore);
}

void MainWindow::saveSnakeColor()
{
    QSettings prefs(PREFS_ORG, PREFS_APP);
    prefs.setValue(KEY_COLOR, m_snakeBody.name());
}

void MainWindow::updateColorPreview()
{
    ui->labelColorPreview->setStyleSheet(
        QString("background-color: %1; border: 3px solid rgb(255, 153, 51); border-radius: 10px;")
            .arg(m_snakeBody.name()));
}

void MainWindow::on_buttonPlayAgain_clicked()
{
    startGame();
}

void MainWindow::on_buttonMenu_clicked()
{
    switchToScreen(Screen::MainMenu);
}

// ---------------------------------------------------------------- game logic

void MainWindow::startGame()
{
    int cols = ui->field->getCols();
    int rows = ui->field->getRows();

    // 3 cells long, in the middle, heading right
    m_snake.clear();
    for (int i = 0; i < 3; ++i)
        m_snake.append(QPoint(cols / 2 - i, rows / 2));

    m_dir = m_nextDir = QPoint(1, 0); // means x+1 , y unchanged (movement)
    m_score = 0;
    m_newBest = false;
    m_tickMs = TICK_START_MS;                          // every new game starts at normal speed
    ui->labelScore->setText(QString::number(m_score)); // reset score display for new game

    spawnFood();
    switchToScreen(Screen::Gameplay);
    setFocus();              // so the window gets the arrow keys, not a button
    render();
    m_timer.start(m_tickMs);
}

void MainWindow::endGame()
{
    m_timer.stop();
    // m_bestScore is already updated live while eating (see gameTick)
    ui->label->setText(QString("Score: %1\nBest: %2").arg(m_score).arg(m_bestScore));
    ui->labelGameOverSub->setText(m_newBest ? "New high score!"
                                            : "The snake has met its end");
    switchToScreen(Screen::GameOver);
}

void MainWindow::spawnFood()
{
    int cols = ui->field->getCols();
    int rows = ui->field->getRows();

    do {
        m_food = QPoint(QRandomGenerator::global()->bounded(cols),
                        QRandomGenerator::global()->bounded(rows));
    } while (m_snake.contains(m_food));
}

void MainWindow::gameTick()
{
    m_dir = m_nextDir;
    QPoint head = m_snake.first() + m_dir;

    bool hitWall = head.x() < 0 || head.y() < 0
                   || head.x() >= ui->field->getCols()
                   || head.y() >= ui->field->getRows();

    if (hitWall || m_snake.contains(head)) {//(hit wall || hit your own body)
        endGame();
        return;
    }

    m_snake.prepend(head);
    if (head == m_food) {
        ++m_score;
        //here update score show in labelScore
        ui->labelScore->setText(QString::number(m_score));

        // new max score: show it right away and remember it for the next run
        if (m_score > m_bestScore) {
            m_bestScore = m_score;
            m_newBest = true;
            ui->labelBest->setText(QString::number(m_bestScore));
            saveBestScore();
        }

        // speed up: each food removes 2 ms from the delay (never below the minimum)
        m_tickMs = qMax(TICK_MIN_MS, m_tickMs - TICK_STEP_MS);
        m_timer.setInterval(m_tickMs);

        spawnFood();
    } else {
        m_snake.removeLast();
    }

    render();
}

void MainWindow::render()
{
    ui->field->resetBoard();   // back to the plain checkerboard

    ui->field->setCellColor(m_food.y(), m_food.x(), FOOD);//draw fllod

    for (int i = 0; i < m_snake.size(); ++i) //draw snake
        ui->field->setCellColor(m_snake[i].y(), m_snake[i].x(),
                                i == 0 ? SNAKE_HEAD : m_snakeBody);

    ui->statusbar->showMessage(QString("Score: %1").arg(m_score));
}

// ---------------------------------------------------------------- input

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    int screen = ui->stackedWidget->currentIndex();

    // Esc: go back to menu from anywhere
    if (event->key() == Qt::Key_Escape) {
        m_timer.stop();
        ui->statusbar->clearMessage();
        switchToScreen(Screen::MainMenu);
        return;
    }

    if (screen == static_cast<int>(Screen::GameOver)) {
        if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter)
            startGame();
        return;
    }

    if (screen == static_cast<int>(Screen::Gameplay)) {
        QPoint want = m_dir;
        switch (event->key()) {
            case Qt::Key_Up:    case Qt::Key_W: want = QPoint(0, -1); break;
            case Qt::Key_Down:  case Qt::Key_S: want = QPoint(0,  1); break;
            case Qt::Key_Left:  case Qt::Key_A: want = QPoint(-1, 0); break;
            case Qt::Key_Right: case Qt::Key_D: want = QPoint(1,  0); break;
            default: QMainWindow::keyPressEvent(event); return;
        }
        // no instant U-turns
        if (want != -m_dir)
            m_nextDir = want;
    }
}
