#include "widget.h"
#include "ui_widget.h"
#include "ui_gamescreen.h"
#include "scorewindow.h"
#include "ui_scorewindow.h"
#include "gamestartwidget.h"
#include "ui_gamestartwidget.h"
#include <QDesktopWidget>
#include <QSize>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    gsui(new Ui::gameScreen),
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

    //setWindowFlags(Qt::FramelessWindowHint);
}

Widget::~Widget()
{
    delete ui;
}



void Widget::connectGame(GameScreen *g)
{
    this->g = g;
    gsui->setupUi(g);
    g->connectWidget(this);
    connect(mySocket, SIGNAL(readyRead()), this->g, SLOT(readCommand()));
    connect(mySocket, SIGNAL(disconnected()), this->g, SLOT(serverDisconnected()));
}

void Widget::on_btnLocal_clicked()
{
    gsw->hideLoad();
    gsw->hideHost();
    gsw->show();
    this->hide();
}

void Widget::on_btnNetwork_clicked(){
    gsw->hideLoad();
    gsw->showHost();
    gsw->show();
    this->hide();
}

void Widget::close_dialog()
{
    this->show();
    s->hide();
}

void Widget::connectScores(ScoreWindow *s)
{
    this->s = s;
    scui->setupUi(s);
    s->connectWidget(this);
}

void Widget::on_btnScores_clicked()
{    
    s->show();
    this->hide();
}

void Widget::connectHelp(HelpWindow *h)
{
    this->h = h;
    hsui->setupUi(h);
    h->connectWidget(this);
}

void Widget::connectStart(GameStartWidget *gsw)
{
    this->gsw = gsw;
    gswui->setupUi(gsw);
    gsw->ConnectStuff(this, mySocket, g);
}

void Widget::on_btnHelp_clicked()
{
    h->show();
    this->hide();    
}

void Widget::on_btnExit_clicked()
{
    this->close();
}


void Widget::on_btnLoad_clicked()
{
    gsw->showHost();
    gsw->displayLoad();
    gsw->show();
    this->hide();
}
