#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QTimer>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    timer->setInterval(1000);
    delay = 3;
    direction = 1;
    bool connected = false;
    socket = new QTcpSocket(this);
    connect(socket, SIGNAL(readyRead()), this, SLOT(dataReceived()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(serverDisconnected()));
    QString hostname = "localhost";
    while(!connected)
    {
        socket->connectToHost(hostname, 5000);
        if(!socket->waitForConnected())
        {
            QMessageBox::critical(this, "Wait","Wait");
        }
        else
        {
            connected = true;
        }
    }
    QString str("1 Joel");
    socket->write(str.toAscii());
    timer->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dataReceived()
{
    while(socket->canReadLine())
    {
        QString str = socket->readLine();
        ui->txtReflect->insertHtml(str + "<br><br>");
    }
}

void MainWindow::timerHit()
{
    delay--;
    QString temp;
    if(delay == 0)
    {
        temp = "3 " + direction;
        socket->write(temp.toAscii());
        if(direction == 4)
        {
            direction = 1;
        }
        else
        {
            direction++;
        }
        temp = "2 " + direction;
        socket->write(temp.toAscii());
        delay = 3;
    }
}

void MainWindow::serverDisconnected()
{
    bool connected = false;
    socket = new QTcpSocket(this);
    QString hostname = "localhost";
    while(!connected)
    {
        socket->connectToHost(hostname, 5000);
        if(!socket->waitForConnected())
        {
            QMessageBox::critical(this, "Wait","Wait");
        }
        else
        {
            connected = true;
        }
    }
}
