#ifndef SERVERWINDOW_H
#define SERVERWINDOW_H

#include <vector>
#include <QTcpSocket>
#include <QTcpServer>
#include <QMainWindow>
#include <QTimer>
#include <game.h>

using namespace std;

namespace Ui {
class serverWindow;
}

class serverWindow : public QMainWindow
{
    Q_OBJECT
    QTimer *timer;
    QTcpServer *server;
    //vector<User *> unUsers;
    vector<QTcpSocket *> unSocks;
   // vector<User *> lobbyUsers;
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
