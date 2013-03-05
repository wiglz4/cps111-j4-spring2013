#include "serverwindow.h"
#include "ui_serverwindow.h"
#include <QMessageBox>

//NEEDS BUNCHES OF WORK

ServerWindow::ServerWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ServerWindow)
{
    ui->setupUi(this);
    /*connect(&server, SIGNAL(newConnection()), this, SLOT(clientConnected()));
    if(!server->listen(QHostAddres::Any, 1337))
    {
        QMessageBox::critical(this, "ERROR", "Cannot start socket.");
        exit(1);
    }*/
    timer = new QTimer(this);
    timer->setInterval(20);
    connect(timer, SIGNAL(timeout()) , this, SLOT(timerHit()));
    timer->start();
}

ServerWindow::~ServerWindow()
{
    delete ui;
}

void ServerWindow::clientConnected()
{
    /*QTcpSocket *sock = server.nextPendingConnection();
    connect(sock, SIGNAL(disconnected()), this, SLOT(clientDisconnected()));
    connect(sock, SIGNAL(readyRead()), this, SLOT(dataReceived()));
    User user = new User();
    user.setSocket(sock);*/

}

void ServerWindow::clientDisconnected()
{
    QTcpSocket *sock = dynamic_cast<QTcpSocket*>(sender());
    sock->deleteLater();
}

void ServerWindow::timerHit()
{
    for(unsigned int i = 0; i < games.size(); ++i)
    {
        games.at(i)->onTick();
    }
}
