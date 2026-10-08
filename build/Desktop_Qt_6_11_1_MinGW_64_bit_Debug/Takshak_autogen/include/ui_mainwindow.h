/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <groundlabel.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QStackedWidget *stackedWidget;
    QWidget *pageSettings;
    QVBoxLayout *settingsLayout;
    QSpacerItem *settingsSpacerTop;
    QLabel *label_2;
    QLabel *labelColorHeading;
    QHBoxLayout *colorRowLayout;
    QSpacerItem *colorSpacerLeft;
    QLabel *labelColorPreview;
    QPushButton *buttonPickColor;
    QPushButton *buttonResetColor;
    QSpacerItem *colorSpacerRight;
    QLabel *labelColorHint;
    QPushButton *buttonBack;
    QSpacerItem *settingsSpacerBottom;
    QWidget *pageGameOver;
    QVBoxLayout *gameOverLayout;
    QSpacerItem *gameOverSpacerTop;
    QLabel *labelGameOverTitle;
    QLabel *labelGameOverSub;
    QLabel *label;
    QSpacerItem *gameOverSpacerMid;
    QPushButton *buttonPlayAgain;
    QPushButton *buttonMenu;
    QLabel *labelGameOverHint;
    QSpacerItem *gameOverSpacerBottom;
    QWidget *pageMainMenu;
    QVBoxLayout *menuLayout;
    QSpacerItem *menuSpacerTop;
    QLabel *labelTitle;
    QLabel *labelSubtitle;
    QSpacerItem *menuSpacerMid;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *labelMenuHint;
    QSpacerItem *menuSpacerBottom;
    QWidget *pageGameplay;
    QGridLayout *gameplayLayout;
    GroundLabel *field;
    QVBoxLayout *scoreLayout;
    QLabel *labelScoreHeading;
    QLabel *labelScore;
    QLabel *labelBestHeading;
    QLabel *labelBest;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1300, 877);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setStyleSheet(QString::fromUtf8(""));
        pageSettings = new QWidget();
        pageSettings->setObjectName("pageSettings");
        pageSettings->setStyleSheet(QString::fromUtf8("QWidget#pageSettings { background-color: rgb(90, 10, 25); }"));
        settingsLayout = new QVBoxLayout(pageSettings);
        settingsLayout->setSpacing(18);
        settingsLayout->setObjectName("settingsLayout");
        settingsSpacerTop = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        settingsLayout->addItem(settingsSpacerTop);

        label_2 = new QLabel(pageSettings);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 153, 51); font-size: 48px; font-weight: bold; background: transparent;"));
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        settingsLayout->addWidget(label_2);

        labelColorHeading = new QLabel(pageSettings);
        labelColorHeading->setObjectName("labelColorHeading");
        labelColorHeading->setStyleSheet(QString::fromUtf8("color: rgb(255, 248, 225); font-size: 22px; background: transparent;"));
        labelColorHeading->setAlignment(Qt::AlignmentFlag::AlignCenter);

        settingsLayout->addWidget(labelColorHeading);

        colorRowLayout = new QHBoxLayout();
        colorRowLayout->setSpacing(20);
        colorRowLayout->setObjectName("colorRowLayout");
        colorSpacerLeft = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        colorRowLayout->addItem(colorSpacerLeft);

        labelColorPreview = new QLabel(pageSettings);
        labelColorPreview->setObjectName("labelColorPreview");
        labelColorPreview->setMinimumSize(QSize(96, 56));
        labelColorPreview->setMaximumSize(QSize(96, 56));
        labelColorPreview->setStyleSheet(QString::fromUtf8("background-color: rgb(69, 115, 232); border: 3px solid rgb(255, 153, 51); border-radius: 10px;"));

        colorRowLayout->addWidget(labelColorPreview);

        buttonPickColor = new QPushButton(pageSettings);
        buttonPickColor->setObjectName("buttonPickColor");
        buttonPickColor->setMinimumSize(QSize(200, 56));
        buttonPickColor->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        buttonPickColor->setStyleSheet(QString::fromUtf8("QPushButton { color: rgb(60, 20, 0); background-color: rgb(255, 153, 51); border-radius: 12px; font-size: 20px; font-weight: bold; }\n"
"QPushButton:hover { background-color: rgb(255, 178, 90); }\n"
"QPushButton:pressed { background-color: rgb(220, 120, 30); }"));

        colorRowLayout->addWidget(buttonPickColor);

        buttonResetColor = new QPushButton(pageSettings);
        buttonResetColor->setObjectName("buttonResetColor");
        buttonResetColor->setMinimumSize(QSize(140, 56));
        buttonResetColor->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        buttonResetColor->setStyleSheet(QString::fromUtf8("QPushButton { color: white; background-color: rgb(19, 136, 8); border-radius: 12px; font-size: 20px; font-weight: bold; }\n"
"QPushButton:hover { background-color: rgb(30, 165, 20); }\n"
"QPushButton:pressed { background-color: rgb(10, 100, 5); }"));

        colorRowLayout->addWidget(buttonResetColor);

        colorSpacerRight = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        colorRowLayout->addItem(colorSpacerRight);


        settingsLayout->addLayout(colorRowLayout);

        labelColorHint = new QLabel(pageSettings);
        labelColorHint->setObjectName("labelColorHint");
        labelColorHint->setStyleSheet(QString::fromUtf8("color: rgb(230, 190, 150); font-size: 15px; background: transparent;"));
        labelColorHint->setAlignment(Qt::AlignmentFlag::AlignCenter);

        settingsLayout->addWidget(labelColorHint);

        buttonBack = new QPushButton(pageSettings);
        buttonBack->setObjectName("buttonBack");
        buttonBack->setMinimumSize(QSize(260, 52));
        buttonBack->setMaximumSize(QSize(260, 52));
        buttonBack->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        buttonBack->setStyleSheet(QString::fromUtf8("QPushButton { color: rgb(255, 153, 51); background: transparent; border: 2px solid rgb(255, 153, 51); border-radius: 12px; font-size: 20px; font-weight: bold; }\n"
"QPushButton:hover { background-color: rgb(120, 30, 45); }\n"
"QPushButton:pressed { background-color: rgb(60, 20, 0); }"));

        settingsLayout->addWidget(buttonBack, 0, Qt::AlignmentFlag::AlignHCenter);

        settingsSpacerBottom = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        settingsLayout->addItem(settingsSpacerBottom);

        stackedWidget->addWidget(pageSettings);
        pageGameOver = new QWidget();
        pageGameOver->setObjectName("pageGameOver");
        pageGameOver->setStyleSheet(QString::fromUtf8("QWidget#pageGameOver { background-color: rgb(90, 10, 25); }"));
        gameOverLayout = new QVBoxLayout(pageGameOver);
        gameOverLayout->setSpacing(16);
        gameOverLayout->setObjectName("gameOverLayout");
        gameOverSpacerTop = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gameOverLayout->addItem(gameOverSpacerTop);

        labelGameOverTitle = new QLabel(pageGameOver);
        labelGameOverTitle->setObjectName("labelGameOverTitle");
        labelGameOverTitle->setStyleSheet(QString::fromUtf8("color: rgb(255, 153, 51); font-size: 72px; font-weight: bold; letter-spacing: 6px; background: transparent;"));
        labelGameOverTitle->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gameOverLayout->addWidget(labelGameOverTitle);

        labelGameOverSub = new QLabel(pageGameOver);
        labelGameOverSub->setObjectName("labelGameOverSub");
        labelGameOverSub->setStyleSheet(QString::fromUtf8("color: rgb(255, 248, 225); font-size: 20px; background: transparent;"));
        labelGameOverSub->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gameOverLayout->addWidget(labelGameOverSub);

        label = new QLabel(pageGameOver);
        label->setObjectName("label");
        label->setMinimumSize(QSize(340, 120));
        label->setMaximumSize(QSize(340, 120));
        label->setStyleSheet(QString::fromUtf8("color: white; font-size: 28px; font-weight: bold; background-color: rgb(60, 20, 0); border: 2px solid rgb(255, 153, 51); border-radius: 14px;"));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gameOverLayout->addWidget(label, 0, Qt::AlignmentFlag::AlignHCenter);

        gameOverSpacerMid = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        gameOverLayout->addItem(gameOverSpacerMid);

        buttonPlayAgain = new QPushButton(pageGameOver);
        buttonPlayAgain->setObjectName("buttonPlayAgain");
        buttonPlayAgain->setMinimumSize(QSize(300, 64));
        buttonPlayAgain->setMaximumSize(QSize(300, 64));
        buttonPlayAgain->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        buttonPlayAgain->setStyleSheet(QString::fromUtf8("QPushButton { color: rgb(60, 20, 0); background-color: rgb(255, 153, 51); border-radius: 14px; font-size: 24px; font-weight: bold; }\n"
"QPushButton:hover { background-color: rgb(255, 178, 90); }\n"
"QPushButton:pressed { background-color: rgb(220, 120, 30); }"));

        gameOverLayout->addWidget(buttonPlayAgain, 0, Qt::AlignmentFlag::AlignHCenter);

        buttonMenu = new QPushButton(pageGameOver);
        buttonMenu->setObjectName("buttonMenu");
        buttonMenu->setMinimumSize(QSize(300, 64));
        buttonMenu->setMaximumSize(QSize(300, 64));
        buttonMenu->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        buttonMenu->setStyleSheet(QString::fromUtf8("QPushButton { color: white; background-color: rgb(19, 136, 8); border-radius: 14px; font-size: 24px; font-weight: bold; }\n"
"QPushButton:hover { background-color: rgb(30, 165, 20); }\n"
"QPushButton:pressed { background-color: rgb(10, 100, 5); }"));

        gameOverLayout->addWidget(buttonMenu, 0, Qt::AlignmentFlag::AlignHCenter);

        labelGameOverHint = new QLabel(pageGameOver);
        labelGameOverHint->setObjectName("labelGameOverHint");
        labelGameOverHint->setStyleSheet(QString::fromUtf8("color: rgb(230, 190, 150); font-size: 14px; background: transparent;"));
        labelGameOverHint->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gameOverLayout->addWidget(labelGameOverHint);

        gameOverSpacerBottom = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gameOverLayout->addItem(gameOverSpacerBottom);

        stackedWidget->addWidget(pageGameOver);
        pageMainMenu = new QWidget();
        pageMainMenu->setObjectName("pageMainMenu");
        pageMainMenu->setStyleSheet(QString::fromUtf8("QWidget#pageMainMenu { background-color: rgb(90, 10, 25); }"));
        menuLayout = new QVBoxLayout(pageMainMenu);
        menuLayout->setSpacing(18);
        menuLayout->setObjectName("menuLayout");
        menuSpacerTop = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        menuLayout->addItem(menuSpacerTop);

        labelTitle = new QLabel(pageMainMenu);
        labelTitle->setObjectName("labelTitle");
        labelTitle->setStyleSheet(QString::fromUtf8("color: rgb(255, 153, 51); font-size: 72px; font-weight: bold; letter-spacing: 6px; background: transparent;"));
        labelTitle->setAlignment(Qt::AlignmentFlag::AlignCenter);

        menuLayout->addWidget(labelTitle);

        labelSubtitle = new QLabel(pageMainMenu);
        labelSubtitle->setObjectName("labelSubtitle");
        labelSubtitle->setStyleSheet(QString::fromUtf8("color: rgb(255, 248, 225); font-size: 20px; background: transparent;"));
        labelSubtitle->setAlignment(Qt::AlignmentFlag::AlignCenter);

        menuLayout->addWidget(labelSubtitle);

        menuSpacerMid = new QSpacerItem(20, 30, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        menuLayout->addItem(menuSpacerMid);

        pushButton = new QPushButton(pageMainMenu);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(300, 64));
        pushButton->setMaximumSize(QSize(300, 64));
        pushButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton { color: rgb(60, 20, 0); background-color: rgb(255, 153, 51); border-radius: 14px; font-size: 24px; font-weight: bold; }\n"
"QPushButton:hover { background-color: rgb(255, 178, 90); }\n"
"QPushButton:pressed { background-color: rgb(220, 120, 30); }"));

        menuLayout->addWidget(pushButton, 0, Qt::AlignmentFlag::AlignHCenter);

        pushButton_2 = new QPushButton(pageMainMenu);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setMinimumSize(QSize(300, 64));
        pushButton_2->setMaximumSize(QSize(300, 64));
        pushButton_2->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton { color: white; background-color: rgb(19, 136, 8); border-radius: 14px; font-size: 24px; font-weight: bold; }\n"
"QPushButton:hover { background-color: rgb(30, 165, 20); }\n"
"QPushButton:pressed { background-color: rgb(10, 100, 5); }"));

        menuLayout->addWidget(pushButton_2, 0, Qt::AlignmentFlag::AlignHCenter);

        labelMenuHint = new QLabel(pageMainMenu);
        labelMenuHint->setObjectName("labelMenuHint");
        labelMenuHint->setStyleSheet(QString::fromUtf8("color: rgb(230, 190, 150); font-size: 14px; background: transparent;"));
        labelMenuHint->setAlignment(Qt::AlignmentFlag::AlignCenter);

        menuLayout->addWidget(labelMenuHint);

        menuSpacerBottom = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        menuLayout->addItem(menuSpacerBottom);

        stackedWidget->addWidget(pageMainMenu);
        pageGameplay = new QWidget();
        pageGameplay->setObjectName("pageGameplay");
        pageGameplay->setStyleSheet(QString::fromUtf8("background-color: rgb(90, 10, 25);"));
        gameplayLayout = new QGridLayout(pageGameplay);
        gameplayLayout->setObjectName("gameplayLayout");
        gameplayLayout->setContentsMargins(32, 32, 32, 32);
        field = new GroundLabel(pageGameplay);
        field->setObjectName("field");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(field->sizePolicy().hasHeightForWidth());
        field->setSizePolicy(sizePolicy);
        field->setMinimumSize(QSize(960, 640));
        field->setMaximumSize(QSize(960, 640));
        field->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 255, 0);"));

        gameplayLayout->addWidget(field, 0, 1, 1, 1, Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        scoreLayout = new QVBoxLayout();
        scoreLayout->setSpacing(8);
        scoreLayout->setObjectName("scoreLayout");
        scoreLayout->setContentsMargins(24, -1, -1, -1);
        labelScoreHeading = new QLabel(pageGameplay);
        labelScoreHeading->setObjectName("labelScoreHeading");
        labelScoreHeading->setMinimumSize(QSize(140, 0));
        labelScoreHeading->setStyleSheet(QString::fromUtf8("color: rgb(255, 153, 51); font-size: 26px; font-weight: bold; background: transparent;"));
        labelScoreHeading->setAlignment(Qt::AlignmentFlag::AlignCenter);

        scoreLayout->addWidget(labelScoreHeading);

        labelScore = new QLabel(pageGameplay);
        labelScore->setObjectName("labelScore");
        labelScore->setMinimumSize(QSize(140, 56));
        labelScore->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); font-size: 30px; font-weight: bold; background-color: rgb(60, 20, 0); border: 2px solid rgb(255, 153, 51); border-radius: 6px;"));
        labelScore->setAlignment(Qt::AlignmentFlag::AlignCenter);

        scoreLayout->addWidget(labelScore);

        labelBestHeading = new QLabel(pageGameplay);
        labelBestHeading->setObjectName("labelBestHeading");
        labelBestHeading->setMinimumSize(QSize(140, 0));
        labelBestHeading->setStyleSheet(QString::fromUtf8("color: rgb(255, 153, 51); font-size: 26px; font-weight: bold; background: transparent;"));
        labelBestHeading->setAlignment(Qt::AlignmentFlag::AlignCenter);

        scoreLayout->addWidget(labelBestHeading);

        labelBest = new QLabel(pageGameplay);
        labelBest->setObjectName("labelBest");
        labelBest->setMinimumSize(QSize(140, 56));
        labelBest->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); font-size: 30px; font-weight: bold; background-color: rgb(60, 20, 0); border: 2px solid rgb(255, 153, 51); border-radius: 6px;"));
        labelBest->setAlignment(Qt::AlignmentFlag::AlignCenter);

        scoreLayout->addWidget(labelBest);


        gameplayLayout->addLayout(scoreLayout, 0, 2, 1, 1, Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);

        gameplayLayout->setColumnStretch(2, 1);
        stackedWidget->addWidget(pageGameplay);

        gridLayout->addWidget(stackedWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Takshak", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        labelColorHeading->setText(QCoreApplication::translate("MainWindow", "Snake body color", nullptr));
        labelColorPreview->setText(QString());
        buttonPickColor->setText(QCoreApplication::translate("MainWindow", "Choose Color\342\200\246", nullptr));
        buttonResetColor->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        labelColorHint->setText(QCoreApplication::translate("MainWindow", "Your choice is saved and used every time you play", nullptr));
        buttonBack->setText(QCoreApplication::translate("MainWindow", "Back to Menu", nullptr));
        labelGameOverTitle->setText(QCoreApplication::translate("MainWindow", "GAME OVER", nullptr));
        labelGameOverSub->setText(QCoreApplication::translate("MainWindow", "The snake has met its end", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Score: 0", nullptr));
        buttonPlayAgain->setText(QCoreApplication::translate("MainWindow", "\342\206\273  Play Again", nullptr));
        buttonMenu->setText(QCoreApplication::translate("MainWindow", "\342\230\260  Main Menu", nullptr));
        labelGameOverHint->setText(QCoreApplication::translate("MainWindow", "Enter = Play again  \342\200\242  Esc = Menu", nullptr));
        labelTitle->setText(QCoreApplication::translate("MainWindow", "TAKSHAK", nullptr));
        labelSubtitle->setText(QCoreApplication::translate("MainWindow", "The Snake Game", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\342\226\266  Start Game", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\342\232\231  Settings", nullptr));
        labelMenuHint->setText(QCoreApplication::translate("MainWindow", "Use Arrow keys or W A S D to move  \342\200\242  Esc = Menu", nullptr));
        field->setText(QString());
        labelScoreHeading->setText(QCoreApplication::translate("MainWindow", "Score", nullptr));
        labelScore->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        labelBestHeading->setText(QCoreApplication::translate("MainWindow", "Best", nullptr));
        labelBest->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
