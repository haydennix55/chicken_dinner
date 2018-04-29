#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "playwindow.h"
#include "basicwindow.h"
#include <Blackjack.h>
#include <cmath>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_closeButton_clicked()
{
   QApplication::quit();
}

void MainWindow::on_playButton_clicked()
{
    //open actual play window
    playwindow = new PlayWindow(this);
    playwindow->show();
    this->hide();
}

void MainWindow::on_basicButton_clicked()
{
    //TODO: Implement visuals for simulation
    basic = new basicwindow(this);
    basic->show();
    this->hide();
}

void MainWindow::on_countingButton_clicked()
{
    //TODO: Implement visuals for simulation
}

void MainWindow::on_actionQuit_triggered()
{
    QApplication::quit();
}
