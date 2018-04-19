/********************************************************************************
** Form generated from reading UI file 'playwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYWINDOW_H
#define UI_PLAYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlayWindow
{
public:
    QAction *actionQuit;
    QWidget *centralwidget;
    QLabel *tableLabel;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *stayButton;
    QPushButton *hitButton;
    QPushButton *doubleButton;
    QPushButton *hintButton;
    QLabel *youLabel;
    QLabel *computerLabel;
    QLabel *statusLabel;
    QLabel *computerStatusLabel;
    QWidget *gridLayoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *card0Label;
    QLabel *card1Label;
    QLabel *card2Label;
    QLabel *card3Label;
    QLabel *card4Label;
    QLabel *card5Label;
    QLabel *card6Label;
    QLabel *card7Label;
    QLabel *card8Label;
    QLabel *card9Label;
    QWidget *gridLayoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *card0Label_2;
    QLabel *card1Label_2;
    QLabel *card2Label_2;
    QLabel *card3Label_2;
    QLabel *card4Label_2;
    QLabel *card5Label_2;
    QLabel *card6Label_2;
    QLabel *card7Label_2;
    QLabel *card8Label_2;
    QLabel *card9Label_2;
    QPushButton *dealButton;
    QLabel *chipsLabel;
    QLabel *betLabel;
    QLabel *chipsDisplay;
    QLabel *betDisplay;
    QLabel *hintLabel;
    QMenuBar *menubar;
    QMenu *menuQuit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *PlayWindow)
    {
        if (PlayWindow->objectName().isEmpty())
            PlayWindow->setObjectName(QStringLiteral("PlayWindow"));
        PlayWindow->resize(716, 500);
        PlayWindow->setBaseSize(QSize(800, 500));
        actionQuit = new QAction(PlayWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        centralwidget = new QWidget(PlayWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tableLabel = new QLabel(centralwidget);
        tableLabel->setObjectName(QStringLiteral("tableLabel"));
        tableLabel->setGeometry(QRect(-30, 0, 800, 500));
        tableLabel->setBaseSize(QSize(800, 500));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(150, 410, 401, 32));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        stayButton = new QPushButton(layoutWidget);
        stayButton->setObjectName(QStringLiteral("stayButton"));
        stayButton->setEnabled(true);
        stayButton->setAutoDefault(false);

        horizontalLayout->addWidget(stayButton);

        hitButton = new QPushButton(layoutWidget);
        hitButton->setObjectName(QStringLiteral("hitButton"));

        horizontalLayout->addWidget(hitButton);

        doubleButton = new QPushButton(layoutWidget);
        doubleButton->setObjectName(QStringLiteral("doubleButton"));

        horizontalLayout->addWidget(doubleButton);

        hintButton = new QPushButton(layoutWidget);
        hintButton->setObjectName(QStringLiteral("hintButton"));

        horizontalLayout->addWidget(hintButton);

        youLabel = new QLabel(centralwidget);
        youLabel->setObjectName(QStringLiteral("youLabel"));
        youLabel->setGeometry(QRect(330, 240, 61, 41));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(120, 120, 120, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        youLabel->setPalette(palette);
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        youLabel->setFont(font);
        computerLabel = new QLabel(centralwidget);
        computerLabel->setObjectName(QStringLiteral("computerLabel"));
        computerLabel->setGeometry(QRect(310, 90, 161, 41));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        computerLabel->setPalette(palette1);
        computerLabel->setFont(font);
        statusLabel = new QLabel(centralwidget);
        statusLabel->setObjectName(QStringLiteral("statusLabel"));
        statusLabel->setGeometry(QRect(115, 350, 47, 13));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        statusLabel->setPalette(palette2);
        computerStatusLabel = new QLabel(centralwidget);
        computerStatusLabel->setObjectName(QStringLiteral("computerStatusLabel"));
        computerStatusLabel->setGeometry(QRect(630, 350, 47, 13));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        computerStatusLabel->setPalette(palette3);
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(160, 290, 381, 101));
        horizontalLayout_2 = new QHBoxLayout(gridLayoutWidget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        card0Label = new QLabel(gridLayoutWidget);
        card0Label->setObjectName(QStringLiteral("card0Label"));

        horizontalLayout_2->addWidget(card0Label);

        card1Label = new QLabel(gridLayoutWidget);
        card1Label->setObjectName(QStringLiteral("card1Label"));

        horizontalLayout_2->addWidget(card1Label);

        card2Label = new QLabel(gridLayoutWidget);
        card2Label->setObjectName(QStringLiteral("card2Label"));

        horizontalLayout_2->addWidget(card2Label);

        card3Label = new QLabel(gridLayoutWidget);
        card3Label->setObjectName(QStringLiteral("card3Label"));

        horizontalLayout_2->addWidget(card3Label);

        card4Label = new QLabel(gridLayoutWidget);
        card4Label->setObjectName(QStringLiteral("card4Label"));

        horizontalLayout_2->addWidget(card4Label);

        card5Label = new QLabel(gridLayoutWidget);
        card5Label->setObjectName(QStringLiteral("card5Label"));

        horizontalLayout_2->addWidget(card5Label);

        card6Label = new QLabel(gridLayoutWidget);
        card6Label->setObjectName(QStringLiteral("card6Label"));

        horizontalLayout_2->addWidget(card6Label);

        card7Label = new QLabel(gridLayoutWidget);
        card7Label->setObjectName(QStringLiteral("card7Label"));

        horizontalLayout_2->addWidget(card7Label);

        card8Label = new QLabel(gridLayoutWidget);
        card8Label->setObjectName(QStringLiteral("card8Label"));

        horizontalLayout_2->addWidget(card8Label);

        card9Label = new QLabel(gridLayoutWidget);
        card9Label->setObjectName(QStringLiteral("card9Label"));

        horizontalLayout_2->addWidget(card9Label);

        gridLayoutWidget_2 = new QWidget(centralwidget);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(160, 140, 381, 101));
        horizontalLayout_3 = new QHBoxLayout(gridLayoutWidget_2);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        card0Label_2 = new QLabel(gridLayoutWidget_2);
        card0Label_2->setObjectName(QStringLiteral("card0Label_2"));

        horizontalLayout_3->addWidget(card0Label_2);

        card1Label_2 = new QLabel(gridLayoutWidget_2);
        card1Label_2->setObjectName(QStringLiteral("card1Label_2"));

        horizontalLayout_3->addWidget(card1Label_2);

        card2Label_2 = new QLabel(gridLayoutWidget_2);
        card2Label_2->setObjectName(QStringLiteral("card2Label_2"));

        horizontalLayout_3->addWidget(card2Label_2);

        card3Label_2 = new QLabel(gridLayoutWidget_2);
        card3Label_2->setObjectName(QStringLiteral("card3Label_2"));

        horizontalLayout_3->addWidget(card3Label_2);

        card4Label_2 = new QLabel(gridLayoutWidget_2);
        card4Label_2->setObjectName(QStringLiteral("card4Label_2"));

        horizontalLayout_3->addWidget(card4Label_2);

        card5Label_2 = new QLabel(gridLayoutWidget_2);
        card5Label_2->setObjectName(QStringLiteral("card5Label_2"));

        horizontalLayout_3->addWidget(card5Label_2);

        card6Label_2 = new QLabel(gridLayoutWidget_2);
        card6Label_2->setObjectName(QStringLiteral("card6Label_2"));

        horizontalLayout_3->addWidget(card6Label_2);

        card7Label_2 = new QLabel(gridLayoutWidget_2);
        card7Label_2->setObjectName(QStringLiteral("card7Label_2"));

        horizontalLayout_3->addWidget(card7Label_2);

        card8Label_2 = new QLabel(gridLayoutWidget_2);
        card8Label_2->setObjectName(QStringLiteral("card8Label_2"));

        horizontalLayout_3->addWidget(card8Label_2);

        card9Label_2 = new QLabel(gridLayoutWidget_2);
        card9Label_2->setObjectName(QStringLiteral("card9Label_2"));

        horizontalLayout_3->addWidget(card9Label_2);

        dealButton = new QPushButton(centralwidget);
        dealButton->setObjectName(QStringLiteral("dealButton"));
        dealButton->setGeometry(QRect(280, 40, 133, 32));
        chipsLabel = new QLabel(centralwidget);
        chipsLabel->setObjectName(QStringLiteral("chipsLabel"));
        chipsLabel->setGeometry(QRect(30, 30, 60, 16));
        betLabel = new QLabel(centralwidget);
        betLabel->setObjectName(QStringLiteral("betLabel"));
        betLabel->setGeometry(QRect(30, 50, 60, 16));
        chipsDisplay = new QLabel(centralwidget);
        chipsDisplay->setObjectName(QStringLiteral("chipsDisplay"));
        chipsDisplay->setGeometry(QRect(70, 30, 60, 16));
        betDisplay = new QLabel(centralwidget);
        betDisplay->setObjectName(QStringLiteral("betDisplay"));
        betDisplay->setGeometry(QRect(60, 50, 60, 16));
        hintLabel = new QLabel(centralwidget);
        hintLabel->setObjectName(QStringLiteral("hintLabel"));
        hintLabel->setGeometry(QRect(30, 70, 211, 16));
        PlayWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(PlayWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 716, 22));
        menuQuit = new QMenu(menubar);
        menuQuit->setObjectName(QStringLiteral("menuQuit"));
        PlayWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(PlayWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        PlayWindow->setStatusBar(statusbar);

        menubar->addAction(menuQuit->menuAction());
        menuQuit->addAction(actionQuit);

        retranslateUi(PlayWindow);

        QMetaObject::connectSlotsByName(PlayWindow);
    } // setupUi

    void retranslateUi(QMainWindow *PlayWindow)
    {
        PlayWindow->setWindowTitle(QApplication::translate("PlayWindow", "chicken_dinner", nullptr));
        actionQuit->setText(QApplication::translate("PlayWindow", "Quit", nullptr));
        tableLabel->setText(QString());
        stayButton->setText(QApplication::translate("PlayWindow", "Stay", nullptr));
        hitButton->setText(QApplication::translate("PlayWindow", "Hit", nullptr));
        doubleButton->setText(QApplication::translate("PlayWindow", "Double", nullptr));
        hintButton->setText(QApplication::translate("PlayWindow", "Hint", nullptr));
        youLabel->setText(QApplication::translate("PlayWindow", "You", nullptr));
        computerLabel->setText(QApplication::translate("PlayWindow", "Computer", nullptr));
        statusLabel->setText(QString());
        computerStatusLabel->setText(QString());
        card0Label->setText(QString());
        card1Label->setText(QString());
        card2Label->setText(QString());
        card3Label->setText(QString());
        card4Label->setText(QString());
        card5Label->setText(QString());
        card6Label->setText(QString());
        card7Label->setText(QString());
        card8Label->setText(QString());
        card9Label->setText(QString());
        card0Label_2->setText(QString());
        card1Label_2->setText(QString());
        card2Label_2->setText(QString());
        card3Label_2->setText(QString());
        card4Label_2->setText(QString());
        card5Label_2->setText(QString());
        card6Label_2->setText(QString());
        card7Label_2->setText(QString());
        card8Label_2->setText(QString());
        card9Label_2->setText(QString());
        dealButton->setText(QApplication::translate("PlayWindow", "Deal", nullptr));
        chipsLabel->setText(QApplication::translate("PlayWindow", "Chips:", nullptr));
        betLabel->setText(QApplication::translate("PlayWindow", "Bet:", nullptr));
        chipsDisplay->setText(QString());
        betDisplay->setText(QString());
        hintLabel->setText(QString());
        menuQuit->setTitle(QApplication::translate("PlayWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlayWindow: public Ui_PlayWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYWINDOW_H
