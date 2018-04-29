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
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_basicwindow
{
public:
    QWidget *centralwidget;
    QPushButton *run;
    QGraphicsView *graphicsView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *basicwindow)
    {
        if (basicwindow->objectName().isEmpty())
            basicwindow->setObjectName(QStringLiteral("basicwindow"));
        basicwindow->resize(712, 533);
        centralwidget = new QWidget(basicwindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        run = new QPushButton(centralwidget);
        run->setObjectName(QStringLiteral("run"));
        run->setGeometry(QRect(0, 0, 151, 61));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(10, 60, 650, 421));
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
        basicwindow->setWindowTitle(QApplication::translate("basicwindow", "MainWindow", nullptr));
        run->setText(QApplication::translate("basicwindow", "Run Sim", nullptr));
    } // retranslateUi

};

namespace Ui {
    class basicwindow: public Ui_basicwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BASICWINDOW_H
