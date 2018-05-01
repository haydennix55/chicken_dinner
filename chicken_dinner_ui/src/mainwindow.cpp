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

    //set dropdown defaults
    ui->decksDropdown->setCurrentText(QString::number(6));
    ui->softDropdown->setCurrentIndex(0);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_closeButton_clicked()
{
   QApplication::quit();
}

//open gameplay window
void MainWindow::on_playButton_clicked()
{
    playwindow = new PlayWindow(this, ui->decksDropdown->currentText().toInt(), ui->softDropdown->currentText().toStdString() == "yes");
    playwindow->show();
    this->hide();
}

//open simulation window
void MainWindow::on_basicButton_clicked()
{
    basic = new basicwindow(this, ui->decksDropdown->currentText().toInt(), ui->softDropdown->currentText().toStdString() == "yes");
    basic->show();
    this->hide();
}


void MainWindow::on_actionQuit_triggered()
{
    QApplication::quit();
}
