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
    void gameTick();

private:
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
};
#endif // MAINWINDOW_H
