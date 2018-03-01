#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "calcwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:

private slots:

    void on_houseEdge_clicked();

    void on_gameSim_clicked();

    void on_gameStrategies_clicked();

private:
    Ui::MainWindow *ui;
    QWindow *CalcWindow;
};

#endif // MAINWINDOW_H
