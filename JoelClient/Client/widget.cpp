#include "widget.h"
#include "ui_widget.h"
#include "ui_gamescreen.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    gsui(new Ui::gameScreen)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::connectGame(gameScreen *g)
{
    gsui->setupUi(g);
    qDebug()<<"reached connect";
    connect(this, SIGNAL(startLocal()), g, SLOT(show()));
}

void Widget::on_btnLocal_clicked()
{
    /*
    qDebug() << "local clicked";
    emit startLocal();
    */

    gameScreen *g = new gameScreen();
    gsui->setupUi(g);
    g->show();

}

