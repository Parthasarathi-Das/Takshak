#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QKeyEvent>
#include <QPoint>
#include <QList>
#include "groundlabel.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

    enum class Screen {
        MainMenu = 2,
        Gameplay = 3,
        Settings = 0,
        GameOver = 1
    };

    // Helper method to change screens
    void switchToScreen(Screen screen);

protected:
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_buttonBack_clicked();
    void on_buttonPickColor_clicked();
    void on_buttonResetColor_clicked();
    void on_buttonPlayAgain_clicked();
    void on_buttonMenu_clicked();
    void gameTick();

private:
    void loadPreferences();              // read best score + snake color from disk
    void saveBestScore();                // write best score to disk
    void saveSnakeColor();               // write snake body color to disk
    void updateColorPreview();           // refresh the swatch on the Settings page
    void startGame();
    void endGame();
    void spawnFood();
    void render();

    Ui::MainWindow *ui;

    QTimer m_timer;
    QList<QPoint> m_snake;   // front = head. QPoint(x = col, y = row)
    QPoint m_dir;            // direction currently moving
    QPoint m_nextDir;        // direction requested by the player
    QPoint m_food;
    int m_score = 0;
    int m_bestScore = 0;     // highest score ever (saved between runs)
    bool m_newBest = false;  // true if the current game beat the old best
    QColor m_snakeBody;      // snake body color (saved between runs)
    int m_tickMs = 500;      // current delay per move; shrinks as the snake eats
};
#endif // MAINWINDOW_H
