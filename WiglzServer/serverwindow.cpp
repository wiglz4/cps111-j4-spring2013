#include "serverwindow.h"
#include "ui_serverwindow.h"

serverWindow::serverWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::serverWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    timer->setInterval(20);
    connect(timer, SIGNAL(timeout()) , this, SLOT(timerHit()));
    timer->start();
}

serverWindow::~serverWindow()
{
    delete ui;
}

void serverWindow::clientConnected()
{

}

void serverWindow::clientDisconnected()
{
    QTcpSocket *sock = dynamic_cast<QTcpSocket*>(sender());
    sock->deleteLater();
}

void serverWindow::timerHit()
{
    game->onTick();
}
