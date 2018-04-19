#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "playwindow.h"
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
    playwindow = new PlayWindow(this);
    playwindow->show();
    this->hide();
}

void MainWindow::on_basicButton_clicked()
{
    this->hide();
}

void MainWindow::on_countingButton_clicked()
{
    this->hide();
}

void MainWindow::on_actionQuit_triggered()
{
    QApplication::quit();
}
