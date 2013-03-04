#ifndef SERVERWINDOW_H
#define SERVERWINDOW_H

#include <QMainWindow>
#include <QUdpSocket>
#include <QTcpServer>
#include <QTcpSocket>
#include "game.h"
#include "user.h"
#include <vector>
#include <QTimer>

//NEEDS BUNCHES OF WORK

namespace Ui {
class ServerWindow;
}

class ServerWindow : public QMainWindow
{
    Q_OBJECT
    QTimer *timer;
    QTcpServer *server;
    vector<User *> lobbyUsers;
    vector<Game *> games;

    
public:
    explicit ServerWindow(QWidget *parent = 0);
    ~ServerWindow();

private slots:
    void clientConnected();
    void clientDisconnected();
    
private:
    Ui::ServerWindow *ui;
    int connectCount;
    int gameCount;
};

#endif // SERVERWINDOW_H
