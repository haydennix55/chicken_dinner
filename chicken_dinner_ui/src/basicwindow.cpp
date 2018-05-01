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

basicwindow::basicwindow(QWidget *parent, int decks, bool softHit) :
    QMainWindow(parent),
    ui(new Ui::basicwindow),
    decks_(decks),
    softHit_(softHit)
{
    //setup window and graphing area
    this->setFixedSize(700,700);
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->scale(1, -1); //flip scale
    ui->minBet->setCurrentIndex(1); //set default dropdown selection
    ui->graphicsView->setScene(scene);
    ui->graphicsView->scene()->setSceneRect(0,0,650,200); //set scene to fit rectangle to prevent auto scaling
    ui->graphicsView->setFixedSize(650,400); //create fixed size view in 3:2 rectangle
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); //remove scroll bars
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //draw x axis line
    blackPen->setWidth(2);
    ui->graphicsView->fitInView(ui->graphicsView->scene()->itemsBoundingRect(), Qt::KeepAspectRatio);
    ui->graphicsView->scene()->addLine(0,100,650,100,*blackPen);


}

//runs 2500 simulated games based on on-screen params
void basicwindow::on_run_clicked()
{
    //params selected by on-screen components
    Mode mode;
    QString min = ui->minBet->currentText();

    //Determine mode form radio button
    if (ui->countButtton->isChecked()){
        mode = Mode::Counting;
    } else {
        mode = Mode::Basic;
    }

    //Create new 6 card game
    Game *g1 = new Game(this->decks_,this->softHit_ );

    //play round 2500 times and plot a point correlating to player total chips
    for (int i = 0; i < 2500; i++) {
        g1->PlayRound(mode,min.toInt()); //play round with params

        float y = ((float)g1->get_player_().get_chips_() / 15) - 565; // convert chips (~10000) to screen height scale
        float x = (float)i/2500.0;  //convert index (0-2500) to screen width scale

        //plot green for net positive chips, red for net negative
        if (g1->get_player_().get_chips_() > 10000){
            ui->graphicsView->scene()->addEllipse((float)x*650.0,y,1,1,*greenPen);
        } else {
            ui->graphicsView->scene()->addEllipse((float)x*650.0,y,1,1,*redPen);
        }
    }

    //Display Chiips after a 2500 rounds
    ui->finalchips->setText(QString::number(g1->get_player_().get_chips_()));

}
