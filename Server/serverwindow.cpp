#include "serverwindow.h"
#include "ui_serverwindow.h"

serverWindow::serverWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::serverWindow)
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

serverWindow::~serverWindow()
{
    delete ui;
}

void serverWindow::clientConnected()
{
    /*QTcpSocket *sock = server.nextPendingConnection();
    connect(sock, SIGNAL(disconnected()), this, SLOT(clientDisconnected()));
    connect(sock, SIGNAL(readyRead()), this, SLOT(dataReceived()));
    User user = new User();
    user.setSocket(sock);*/
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
