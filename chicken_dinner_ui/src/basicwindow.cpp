#include "basicwindow.h"
#include "ui_basicwindow.h"
#include "playwindow.h"
#include "ui_playwindow.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <QDebug>
#include <QList>
#include <map>
#include <Blackjack.h>
#include <cmath>
#include <QString>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QMainWindow>
#include <ctime>
#include <cstdlib>

basicwindow::basicwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::basicwindow)
{
    srand(time(NULL));
    this->setFixedSize(700,700);
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->scale(1, -1);
    ui->minBet->setCurrentIndex(1);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->scene()->setSceneRect(0,0,650,200); //set scene to fit rectangle to prevent auto scaling
    ui->graphicsView->setFixedSize(650,400); //create fixed size view in 3:2 rectangle
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); //remove scroll bars
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    blackPen->setWidth(2);
    ui->graphicsView->fitInView(ui->graphicsView->scene()->itemsBoundingRect(), Qt::KeepAspectRatio);

    ui->graphicsView->scene()->addLine(0,100,650,100,*blackPen);


}

void basicwindow::on_run_clicked()
{
    //650 rounds, 10000 chips, $10 bet
    Mode mode;
    QString min = ui->minBet->currentText();

    if (ui->countButtton->isChecked()){
        mode = Mode::Counting;
    } else {
        mode = Mode::Basic;
    }
    Game *g1 = new Game(6);


    for (int i = 0; i < 2500; i++) {
        g1->PlayRound(mode,min.toInt());
        float y = ((float)g1->get_player_().get_chips_() / 15) - 565;
        float x = (float)i/2500.0;
        if (g1->get_player_().get_chips_() > 10000){
            ui->graphicsView->scene()->addEllipse((float)x*650.0,y,1,1,*greenPen);
        } else {
            ui->graphicsView->scene()->addEllipse((float)x*650.0,y,1,1,*redPen);
        }
    }

    ui->finalchips->setText(QString::number(g1->get_player_().get_chips_()));

}
