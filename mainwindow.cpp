#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QRandomGenerator>

namespace {
    // Indian palette
    const QColor TILE_LIGHT(60, 150, 60);    // lush green
    const QColor TILE_DARK(40, 125, 50);     // deeper green
    const QColor SNAKE_BODY(255, 153, 51);   // kesari / saffron
    const QColor SNAKE_HEAD(128, 0, 32);     // maroon
    const QColor FOOD(226, 18, 126);         // rani pink

    const int TICK_MS = 500;                 // lower = faster snake
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    switchToScreen(Screen::MainMenu);

    ui->field->setSquareSize(32);
    ui->field->setDefaultColors(TILE_LIGHT, TILE_DARK);

    connect(&m_timer, &QTimer::timeout, this, &MainWindow::gameTick);
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

// ---------------------------------------------------------------- game logic

void MainWindow::startGame()
{
    int cols = ui->field->getCols();
    int rows = ui->field->getRows();

    // 3 cells long, in the middle, heading right
    m_snake.clear();
    for (int i = 0; i < 3; ++i)
        m_snake.append(QPoint(cols / 2 - i, rows / 2));

    m_dir = m_nextDir = QPoint(1, 0);
    m_score = 0;

    spawnFood();
    switchToScreen(Screen::Gameplay);
    setFocus();              // so the window gets the arrow keys, not a button
    render();
    m_timer.start(TICK_MS);
}

void MainWindow::endGame()
{
    m_timer.stop();
    ui->label->setText(QString("Game Over\nScore: %1\n\nEnter = Play again    Esc = Menu").arg(m_score));
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

    if (hitWall || m_snake.contains(head)) {
        endGame();
        return;
    }

    m_snake.prepend(head);
    if (head == m_food) {
        ++m_score;
        spawnFood();
    } else {
        m_snake.removeLast();
    }

    render();
}

void MainWindow::render()
{
    ui->field->resetBoard();   // back to the plain checkerboard

    ui->field->setCellColor(m_food.y(), m_food.x(), FOOD);

    for (int i = 0; i < m_snake.size(); ++i)
        ui->field->setCellColor(m_snake[i].y(), m_snake[i].x(),
                                i == 0 ? SNAKE_HEAD : SNAKE_BODY);

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
