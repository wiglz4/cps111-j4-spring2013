#include "serverwindow.h"
#include "ui_serverwindow.h"
#include <QMessageBox>
#include <string>
#include <user.h>
#include <sstream>
#include <QTextCodec>
#include <QString>
#include <counter.h>
#include <QLabel>
#include <QDebug>

//NEEDS BUNCHES OF WORK
ServerWindow::ServerWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ServerWindow),
    ticks(0)
{
    ui->setupUi(this);

    connect(&server, SIGNAL(newConnection()), this, SLOT(clientConnected()));
    if(!server.listen(QHostAddress::Any, 5000))
    {
        QMessageBox::critical(this, "ERROR", "Cannot start socket.");
        exit(1);
    }

    timer = new QTimer(this);
    timer->setInterval(20);
    connect(timer, SIGNAL(timeout()) , this, SLOT(timerHit()));
    timerGo = false;
    game = NULL;
    //timer->start();
}

ServerWindow::~ServerWindow()
{
    delete ui;
}

void ServerWindow::clientConnected()
{
    ui->label->setText("connected");
    User *user = new User();
    QTcpSocket *sock = server.nextPendingConnection();
    connect(sock, SIGNAL(disconnected()), this, SLOT(clientDisconnected()));
    connect(sock, SIGNAL(readyRead()), this, SLOT(dataReceived()));
    user->setSocket(sock);
    unUsers.push_back(user);
}

void ServerWindow::clientDisconnected()
{
    QTcpSocket *sock = dynamic_cast<QTcpSocket*>(sender());
    sock->deleteLater();
}

void ServerWindow::dataReceived()
{
    QTcpSocket *sock = dynamic_cast<QTcpSocket*>(sender());
    if(game == NULL)
    {
        QString str = sock->readLine();
        for(uint i = 0; i < unUsers.size(); ++i)
        {
            if(sock == unUsers.at(i)->getSock())
            {
                if(!unUsers.at(i)->checkInstanceVars())
                {
                    QStringList List = str.split(" ",QString::SkipEmptyParts);
                    if(List.at(0) == "5")
                    {
                        unUsers.at(i)->setTeam(GetUserTeam());
                        unUsers.at(i)->setUsername(GetLoadUsername());
                        game = Game::Load(this, &unUsers);
                        timer->start();
                    }
                    else
                    {
                        int team;
                        team = List.at(0).toInt();
                        std::string username = List.at(1).toStdString();
                        unUsers.at(i)->setTeam(team);
                        unUsers.at(i)->setUsername(username);
                        if(!timerGo)
                        {
                            timerGo = true;
                            timerHit();
                        }
                    }
                }
            }
        }
    }
    else
    {
        for(uint i = 0; i < unUsers.size(); i++)
        {
            if(sock == unUsers.at(i)->getSock())
            {
                QString str = sock->readLine();
                unUsers.at(i)->command(str.toStdString());
                break;
            }
        }
    }
}

void ServerWindow::timerHit()
{
    ticks += 20;
    if(timerGo)
    {
        timerGo = false;
        game = new Game(this, &unUsers);
        timer->start();
    }
    else
    {
        if(!game->getOver())
        {
            QString message = game->onTick().c_str();
            if(message != "" && message != "97179\n")
            {
                for(uint i = 0; i < unUsers.size(); ++i)
                {

                    unUsers.at(i)->getSock()->write(message.toAscii());
                }
            }
        }
        else
        {
            timer->stop();
        }
    }
}


int ServerWindow::GetUserTeam()
{
}

string ServerWindow::GetLoadUsername()
{
}
