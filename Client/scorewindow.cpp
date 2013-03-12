#include "scorewindow.h"
#include "widget.h"
#include "ui_scorewindow.h"
#include "gamescreen.h"
#include "ui_widget.h"
#include <QDebug>
#include <QPushButton>
#include <QDesktopWidget>
#include <QSize>

ScoreWindow::ScoreWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ScoreWindow)
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

    setWindowFlags(Qt::FramelessWindowHint);
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
