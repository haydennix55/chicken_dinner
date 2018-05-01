/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuit;
    QWidget *centralWidget;
    QLabel *pictureLabel;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *playButton;
    QPushButton *basicButton;
    QPushButton *closeButton;
    QComboBox *decksDropdown;
    QLabel *label;
    QComboBox *softDropdown;
    QLabel *label_2;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(480, 410);
        MainWindow->setAutoFillBackground(true);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pictureLabel = new QLabel(centralWidget);
        pictureLabel->setObjectName(QStringLiteral("pictureLabel"));
        pictureLabel->setGeometry(QRect(40, -10, 451, 371));
        pictureLabel->setMaximumSize(QSize(471, 411));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(90, 350, 291, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(110, 60, 261, 241));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        playButton = new QPushButton(verticalLayoutWidget);
        playButton->setObjectName(QStringLiteral("playButton"));

        verticalLayout->addWidget(playButton);

        basicButton = new QPushButton(verticalLayoutWidget);
        basicButton->setObjectName(QStringLiteral("basicButton"));

        verticalLayout->addWidget(basicButton);

        closeButton = new QPushButton(verticalLayoutWidget);
        closeButton->setObjectName(QStringLiteral("closeButton"));

        verticalLayout->addWidget(closeButton);

        decksDropdown = new QComboBox(centralWidget);
        decksDropdown->addItem(QString());
        decksDropdown->addItem(QString());
        decksDropdown->addItem(QString());
        decksDropdown->addItem(QString());
        decksDropdown->addItem(QString());
        decksDropdown->setObjectName(QStringLiteral("decksDropdown"));
        decksDropdown->setGeometry(QRect(110, 30, 104, 26));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(110, 10, 111, 16));
        softDropdown = new QComboBox(centralWidget);
        softDropdown->addItem(QString());
        softDropdown->addItem(QString());
        softDropdown->setObjectName(QStringLiteral("softDropdown"));
        softDropdown->setGeometry(QRect(260, 30, 104, 26));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(250, 10, 131, 16));
        MainWindow->setCentralWidget(centralWidget);
        layoutWidget->raise();
        pictureLabel->raise();
        verticalLayoutWidget->raise();
        decksDropdown->raise();
        label->raise();
        softDropdown->raise();
        label_2->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 480, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionQuit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "chicken_dinner", nullptr));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", nullptr));
        pictureLabel->setText(QString());
        playButton->setText(QApplication::translate("MainWindow", "Play Blackjack", nullptr));
        basicButton->setText(QApplication::translate("MainWindow", "Simulate Games", nullptr));
        closeButton->setText(QApplication::translate("MainWindow", "Close", nullptr));
        decksDropdown->setItemText(0, QApplication::translate("MainWindow", "2", nullptr));
        decksDropdown->setItemText(1, QApplication::translate("MainWindow", "3", nullptr));
        decksDropdown->setItemText(2, QApplication::translate("MainWindow", "4", nullptr));
        decksDropdown->setItemText(3, QApplication::translate("MainWindow", "5", nullptr));
        decksDropdown->setItemText(4, QApplication::translate("MainWindow", "6", nullptr));

        label->setText(QApplication::translate("MainWindow", "Number of Decks", nullptr));
        softDropdown->setItemText(0, QApplication::translate("MainWindow", "yes", nullptr));
        softDropdown->setItemText(1, QApplication::translate("MainWindow", "no", nullptr));

        label_2->setText(QApplication::translate("MainWindow", "Dealer hit on soft 17", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
