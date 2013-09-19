//-----------------------------------------------------------
//File:   widget.cpp
//Authors: Jeremie Miller, Jonathan Neves, Joel Sampson, John Wiglesworth
//User IDs: jmill521, jneve321, jsamp710, jwigl437   Class: CPS 110
//Desc:   This provides a nice menu to start the game with.
//
//-----------------------------------------------------------

#include "widget.h"
#include "ui_widget.h"
#include "ui_gamescreen.h"
#include "scorewindow.h"
#include "ui_scorewindow.h"
#include "gamestartwidget.h"
#include "ui_gamestartwidget.h"
#include <QDesktopWidget>
#include <QSize>

//Constructor
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    gsui(new Ui::GameScreen),
    scui(new Ui::ScoreWindow),
    hsui(new Ui::HelpWindow),
    gswui(new Ui::GameStartWidget)
{
    ui->setupUi(this);

    mySocket = new QTcpSocket(this);

    QDesktopWidget *desktop = QApplication::desktop();
    int screenWidth, width;
    int screenHeight, height;
    int x, y;
    QSize windowSize;

    screenWidth = desktop->width();
    screenHeight = desktop->height();

    windowSize = size();
    width = windowSize.width();
    height = windowSize.height();

    x = (screenWidth - width)/2;
    y = (screenHeight - height)/2;
    y -= 50;

    move(x, y);
    setFixedSize(windowSize.width(), windowSize.height());

    setWindowFlags(Qt::SplashScreen);
}

//Destructor
Widget::~Widget()
{
    delete ui;
}


//sets <this->g> to <g>
void Widget::connectGame(GameScreen *g)
{
    this->g = g;
    gsui->setupUi(g);
    g->connectWidget(this);
    connect(mySocket, SIGNAL(readyRead()), this->g, SLOT(readCommand()));
    connect(mySocket, SIGNAL(disconnected()), this->g, SLOT(serverDisconnected()));
}

//singleplayer clicked
void Widget::on_btnLocal_clicked()
{
    gsw->hideLoad();
    gsw->hideHost();
    gsw->show();
    this->hide();
}

//multiplayer clicked
void Widget::on_btnNetwork_clicked(){
    gsw->hideLoad();
    gsw->dislpayHost();
    gsw->show();
    gsw->isMultiplyer();
    this->hide();
}

//sets <this->s> to <s>
void Widget::connectScores(ScoreWindow *s)
{
    this->s = s;
    scui->setupUi(s);
    s->connectWidget(this);
}

//high scores clicked
void Widget::on_btnScores_clicked()
{    
    s->show();
    this->hide();
}

//sets <this->h> to <h>
void Widget::connectHelp(HelpWindow *h)
{
    this->h = h;
    hsui->setupUi(h);
    h->connectWidget(this);
}

//sets <this->gsw> to <gsw>
void Widget::connectStart(GameStartWidget *gsw)
{
    this->gsw = gsw;
    gswui->setupUi(gsw);
    gsw->connectStuff(this, mySocket, g);
}

//help clicked
void Widget::on_btnHelp_clicked()
{
    h->show();
    this->hide();    
}

//exit clicked
void Widget::on_btnExit_clicked()
{
    QApplication::quit();
}

//load game clicked
void Widget::on_btnLoad_clicked()
{
    gsw->dislpayHost();
    gsw->displayLoad();
    gsw->show();
    this->hide();
}
