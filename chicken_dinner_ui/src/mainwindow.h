#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "playwindow.h"
#include "basicwindow.h"
#include <Blackjack.h>
#include <cmath>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    PlayWindow *playwindow;
    basicwindow *basic;


private slots:
    void on_closeButton_clicked();

    void on_playButton_clicked();

    void on_actionQuit_triggered();


    void on_basicButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
