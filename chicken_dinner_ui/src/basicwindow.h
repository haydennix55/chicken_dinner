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
    explicit basicwindow(QWidget *parent = nullptr,  int decks = 6, bool softHit = true);
private:
     Ui::basicwindow *ui;
     QGraphicsScene *scene;
     int decks_;
     bool softHit_;

     //Pens for plotting
     QPen *blackPen = new QPen(Qt::black);
     QPen *greenPen = new QPen(Qt::green);
     QPen *redPen = new QPen(Qt::red);

signals:

public slots:
private slots:
     void on_run_clicked();
};

#endif // BASICWINDOW_H
