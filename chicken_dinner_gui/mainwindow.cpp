#include <iostream>
#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_houseEdge_clicked()
{
    std::cout << "houseEdge button!" << std::endl;
}

void MainWindow::on_gameSim_clicked()
{
    std::cout << "gameSim button!" << std::endl;
}

void MainWindow::on_gameStrategies_clicked()
{
    std::cout << "gameStrategies!" << std::endl;
}
