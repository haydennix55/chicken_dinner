#ifndef BASICWINDOW_H
#define BASICWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>

namespace Ui {
class basicwindow;
}
class basicwindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit basicwindow(QWidget *parent = nullptr);

private:
     Ui::basicwindow *ui;
     QGraphicsScene *scene;
     QPen *blackPen = new QPen(Qt::black);

signals:

public slots:
private slots:
     void on_run_clicked();
};

#endif // BASICWINDOW_H
