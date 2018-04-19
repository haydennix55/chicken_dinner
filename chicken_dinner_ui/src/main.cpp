#include "mainwindow.h"
#include <QApplication>
#include <Blackjack.h>
#include <cmath>

int main(int argc, char *argv[])
{
    //load menu window
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
