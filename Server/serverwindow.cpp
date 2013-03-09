#include "serverwindow.h"
#include "ui_serverwindow.h"
#include <QMessageBox>
#include <string>
#include <user.h>
#include <sstream>
#include <QTextCodec>
#include <QString>
#include <counter.h>

//NEEDS BUNCHES OF WORK
serverWindow::serverWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::serverWindow)
{
    ui->setupUi(this);
    connect(server, SIGNAL(newConnection()), this, SLOT(clientConnected()));
    if(!server->listen(QHostAddress::Any, 1337))
    {
        QMessageBox::critical(this, "ERROR", "Cannot start socket.");
        exit(1);
    }
    timer = new QTimer(this);
    timer->setInterval(20);
    connect(timer, SIGNAL(timeout()) , this, SLOT(timerHit()));
    timerGo = false;
    //timer->start();
}

serverWindow::~serverWindow()
{
    delete ui;
}

void serverWindow::clientConnected()
{
    User *user = new User();
    QTcpSocket *sock = server->nextPendingConnection();
    connect(sock, SIGNAL(disconnected()), this, SLOT(clientDisconnected()));
    connect(sock, SIGNAL(readyRead()), this, SLOT(dataReceived()));
    user->setSocket(sock);
    unUsers.push_back(user);
    //if(count == NULL)
    //{
    //count = new Counter()
    //}
}

void serverWindow::clientDisconnected()
{
    QTcpSocket *sock = dynamic_cast<QTcpSocket*>(sender());
    sock->deleteLater();
}

void serverWindow::dataReceived()
{
    //Test code
    QTcpSocket *sock = dynamic_cast<QTcpSocket*>(sender());
    if(game == NULL)
    {
        QString str = sock->readLine();
        for(uint i = 0; i < unUsers.size()-1;++i)
        {
            if(sock == unUsers.at(i)->getSock())
            {
                if(!unUsers.at(i)->checkInstanceVars())
                {
                    stringstream strm(str.toStdString());
                    int team;
                    strm>>team;
                    std::string username = strm.str();
                    unUsers.at(i)->setTeam(team);
                    unUsers.at(i)->setUsername(username);
                    QString message("Hello ");
                    QString uname(username.c_str());
                    message += uname + "!";
                    sock->write(message.toAscii());
                    if(!timerGo)
                    {
                        timerGo = true;
                        timerHit();
                    }
                }
            }
        }
    }
    else
    {
        for(uint i = 0; i < unUsers.size()-1; i++)
        {
            if(sock == unUsers.at(i)->getSock())
            {
                 QString str = sock->readLine();
                 unUsers.at(i)->command(str.toStdString());
                 break;
            }
        }
    }
    //Real code
    /*
    QTcpSocket *sock = dynamic_cast<QTcpSocket*>(sender());
    for(uint i = 0; i < unUsers.size()-1; i++)
    {
        if(sock == unUsers.at(i)->getSock())
        {
             QString str = sock->readLine();
             unUsers.at(i)->command(str.toStdString());
             break;
        }
    }
    */
}

void serverWindow::timerHit()
{
    /*
    if(game != NULL)
    {
        game->onTick();
    }
    else if(unUsers.size() > 0)
    {
        game = new Game(&unUsers);
    }
    */
    if(timerGo)
    {
        timerGo = false;
        game = new Game(&unUsers);
        timer->start();
    }
    else
    {
        game->onTick();
    }
}
