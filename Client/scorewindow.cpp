#include "scorewindow.h"
#include "widget.h"
#include "ui_scorewindow.h"
#include "gamescreen.h"
#include "ui_widget.h"
#include "gamescreen.h"
#include <QDebug>
#include <QPushButton>
#include <QDesktopWidget>
#include <QSize>
#include <QFrame>


ScoreWindow::ScoreWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ScoreWindow),
    isEndgame(false), nextY(34)
{
    ui->setupUi(this);
    main = new QPushButton(this);
    main->setGeometry(570,161,121,31);
    main->setFlat(true);
    main->setFocusPolicy(Qt::NoFocus);
    main->setStyleSheet("QPushButton { background:url(:/images/buttonmm) no-repeat right top; } QPushButton:hover{ background:url(:/images/buttonmm2.png) no-repeat right top; } QPushButton:pressed { background:url(:/images/buttonmm.png) no-repeat right top; border: 0px solid grey; }");
    main->show();
    connect(this->main, SIGNAL(clicked()), this, SLOT(main_window()));

    btnExit2 = new QPushButton(this);
    btnExit2->setGeometry(604,185,121,31);
    btnExit2->setFlat(true);
    btnExit2->setFocusPolicy(Qt::NoFocus);
    btnExit2->setStyleSheet("QPushButton { background:url(:/images/buttonex) no-repeat right top; } QPushButton:hover{ background:url(:/images/buttonex2.png) no-repeat right top; } QPushButton:pressed { background:url(:/images/buttonex.png) no-repeat right top; border: 0px solid grey; }");
    btnExit2->show();

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

ScoreWindow::~ScoreWindow()
{
    delete ui;
}


void ScoreWindow::main_window(){
    qDebug() << "pressed";
    this->hide();
    w->show();
}

void ScoreWindow::on_btnExit2_clicked()
{
    this->close();
}

void ScoreWindow::connectWidget(Widget *w){
    this->w = w;
    connect(this->btnExit2, SIGNAL(clicked()), this, SLOT(on_btnExit2_clicked()));
}

void ScoreWindow::addScore(ScoreObject *s){
    qDebug() << "added score";
    if(!isEndgame){
        makeEndGame();
    }
    QLabel *label = new QLabel(ui->frScore);
    label->setGeometry(4, nextY, 20, 20);
    if(s->team() == 2){
        label->setStyleSheet("background:#44707b");
    }else if (s->team() == 1){
        label->setStyleSheet("background:#a23a1d");
    }
    label->show();

    label = new QLabel(ui->frScore);
    label->setGeometry(32, nextY, 122, 20);
    label->setText(s->username());
    label->setStyleSheet("color:#333333");
    label->show();

    label = new QLabel(ui->frScore);
    label->setGeometry(162, nextY, 66, 20);
    label->setAlignment(Qt::AlignRight);
    label->setText(QString::number(s->deaths()));
    label->setStyleSheet("color:#333333");
    label->show();

    label = new QLabel(ui->frScore);
    label->setGeometry(236, nextY, 66, 20);
    label->setAlignment(Qt::AlignRight);
    label->setText(QString::number(s->tKills()));
    label->setStyleSheet("color:#333333");
    label->show();

    label = new QLabel(ui->frScore);
    label->setGeometry(310, nextY, 66, 20);
    label->setAlignment(Qt::AlignRight);
    label->setText(QString::number(s->mKills()));
    label->setStyleSheet("color:#333333");
    label->show();

    label = new QLabel(ui->frScore);
    label->setGeometry(384, nextY, 66, 20);
    label->setAlignment(Qt::AlignRight);
    label->setText(QString::number(s->pKills()));
    label->setStyleSheet("color:#333333");
    label->show();

    label = new QLabel(ui->frScore);
    label->setGeometry(458, nextY, 66, 20);
    label->setAlignment(Qt::AlignRight);
    label->setText(QString::number(s->score()));
    label->setStyleSheet("color:#333333");
    label->show();
    nextY += 26;
}

void ScoreWindow::addTime(int t){
    qDebug() << "added time";
    ui->lblTTime->setText("Game Time:");
    int tenth;
    int seconds;
    int minutes;
    int hours;
    int temp;
    tenth = t/100;
    temp = t % 100;
    if (temp >= 50){
        tenth++;
    }
    seconds = tenth/10;
    tenth = tenth % 10;
    minutes = seconds/60;
    seconds = seconds % 60;
    hours = minutes/60;
    minutes = minutes % 60;
    ui->lblTime->setText(QString::number(hours) + ":" + QString::number(minutes) + ":" +
                         QString::number(seconds) + "." + QString::number(tenth));
}


void ScoreWindow::makeEndGame(){
    ui->frScore->setFrameShape(QFrame::Box);
    ui->frScore->setStyleSheet("background:rgb(100,100,100);");
    ui->line->setFrameShadow(QFrame::Plain);
    ui->line_2->setFrameShadow(QFrame::Plain);
    ui->line_3->setFrameShadow(QFrame::Plain);
    ui->line_4->setFrameShadow(QFrame::Plain);
    ui->line_5->setFrameShadow(QFrame::Plain);
    ui->line_6->setFrameShadow(QFrame::Plain);
    ui->line_7->setFrameShadow(QFrame::Plain);
    ui->line_8->setFrameShadow(QFrame::Plain);
    ui->line_9->setFrameShadow(QFrame::Plain);
    ui->line_10->setFrameShadow((QFrame::Plain));
    ui->line_11->setFrameShadow(QFrame::Plain);

    ui->lblTName->setText("Name");
    ui->lblTDeaths->setText("Deaths");
    ui->lblTTKills->setText("Towers");
    ui->lblTMKills->setText("Minions");
    ui->lblTPKills->setText("Players");
    ui->lblTScore->setText("Score");

    ui->lblTitle->setStyleSheet("background: url(:/images/game over.png) no-repeat top left; background-color:rgba(0,0,0,0);");

    isEndgame = true;
}
