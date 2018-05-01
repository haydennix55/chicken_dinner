/********************************************************************************
** Form generated from reading UI file 'basicwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BASICWINDOW_H
#define UI_BASICWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_basicwindow
{
public:
    QWidget *centralwidget;
    QPushButton *run;
    QGraphicsView *graphicsView;
    QRadioButton *countButtton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QComboBox *minBet;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *finalchips;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *basicwindow)
    {
        if (basicwindow->objectName().isEmpty())
            basicwindow->setObjectName(QStringLiteral("basicwindow"));
        basicwindow->resize(712, 710);
        centralwidget = new QWidget(basicwindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        run = new QPushButton(centralwidget);
        run->setObjectName(QStringLiteral("run"));
        run->setGeometry(QRect(290, 0, 151, 61));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(40, 60, 650, 421));
        countButtton = new QRadioButton(centralwidget);
        countButtton->setObjectName(QStringLiteral("countButtton"));
        countButtton->setGeometry(QRect(100, 490, 161, 20));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 450, 60, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 380, 60, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(0, 240, 60, 16));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(0, 310, 60, 16));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(0, 170, 60, 16));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(0, 100, 60, 16));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(0, 40, 60, 16));
        minBet = new QComboBox(centralwidget);
        minBet->addItem(QString());
        minBet->addItem(QString());
        minBet->addItem(QString());
        minBet->addItem(QString());
        minBet->addItem(QString());
        minBet->setObjectName(QStringLiteral("minBet"));
        minBet->setGeometry(QRect(330, 490, 104, 26));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(240, 490, 91, 16));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(0, 10, 60, 16));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(130, 530, 471, 16));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(60, 550, 611, 16));
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(60, 570, 611, 16));
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(70, 590, 591, 16));
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(50, 610, 601, 16));
        label_15 = new QLabel(centralwidget);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(460, 490, 71, 16));
        finalchips = new QLabel(centralwidget);
        finalchips->setObjectName(QStringLiteral("finalchips"));
        finalchips->setGeometry(QRect(540, 490, 60, 16));
        basicwindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(basicwindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 712, 22));
        basicwindow->setMenuBar(menubar);
        statusbar = new QStatusBar(basicwindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        basicwindow->setStatusBar(statusbar);

        retranslateUi(basicwindow);

        QMetaObject::connectSlotsByName(basicwindow);
    } // setupUi

    void retranslateUi(QMainWindow *basicwindow)
    {
        basicwindow->setWindowTitle(QApplication::translate("basicwindow", "chicken_dinner", nullptr));
        run->setText(QApplication::translate("basicwindow", "Run 2500 Games", nullptr));
        countButtton->setText(QApplication::translate("basicwindow", "Counting Cards", nullptr));
        label->setText(QApplication::translate("basicwindow", "7000", nullptr));
        label_2->setText(QApplication::translate("basicwindow", "8000", nullptr));
        label_3->setText(QApplication::translate("basicwindow", "10000", nullptr));
        label_4->setText(QApplication::translate("basicwindow", "9000", nullptr));
        label_5->setText(QApplication::translate("basicwindow", "11000", nullptr));
        label_6->setText(QApplication::translate("basicwindow", "12000", nullptr));
        label_7->setText(QApplication::translate("basicwindow", "13000", nullptr));
        minBet->setItemText(0, QApplication::translate("basicwindow", "5", nullptr));
        minBet->setItemText(1, QApplication::translate("basicwindow", "10", nullptr));
        minBet->setItemText(2, QApplication::translate("basicwindow", "15", nullptr));
        minBet->setItemText(3, QApplication::translate("basicwindow", "20", nullptr));
        minBet->setItemText(4, QApplication::translate("basicwindow", "25", nullptr));

        label_8->setText(QApplication::translate("basicwindow", "Minimum Bet:", nullptr));
        label_9->setText(QApplication::translate("basicwindow", "Chips:", nullptr));
        label_10->setText(QApplication::translate("basicwindow", "Every run creates a new game and player that starts with 10,000 chips", nullptr));
        label_11->setText(QApplication::translate("basicwindow", "When the \"counting cards\" radio button is unselected, 2500 rounds are played with basic strategy,", nullptr));
        label_12->setText(QApplication::translate("basicwindow", "and if it is selected, 2500 rounds are played with betting that varies depending on the true count,", nullptr));
        label_13->setText(QApplication::translate("basicwindow", "which is the current count / num of decks remaining. You can also change the minimum bet. ", nullptr));
        label_14->setText(QApplication::translate("basicwindow", "Keep in mind, even counting cards only gives a slight advantage. Betting big could mean losing big.", nullptr));
        label_15->setText(QApplication::translate("basicwindow", "Final Chips:", nullptr));
        finalchips->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class basicwindow: public Ui_basicwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BASICWINDOW_H
