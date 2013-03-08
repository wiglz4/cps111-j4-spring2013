#ifndef SERVERWINDOW_H
#define SERVERWINDOW_H

//NEEDS BUNCHES OF WORK
#include <vector>
#include <QTcpSocket>
#include <QTcpServer>
#include <QMainWindow>
#include <QTimer>
#include <game.h>
#include <user.h>

using namespace std;

namespace Ui {
class serverWindow;
}

class serverWindow : public QMainWindow
{
    Q_OBJECT
    QTimer *timer;
    QTcpServer *server;
    vector<User *> unUsers;
    vector<QTcpSocket *> unSocks;
    vector<User *> lobbyUsers;
    Game *game;


public:
    explicit serverWindow(QWidget *parent = 0);
    ~serverWindow();

private slots:
    void clientConnected();
    void clientDisconnected();
    void timerHit();

private:
    Ui::serverWindow *ui;
    int connectCount;
    int gameCount;
};

#endif // SERVERWINDOW_H
