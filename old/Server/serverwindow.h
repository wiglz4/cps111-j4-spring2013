#ifndef SERVERWINDOW_H
#define SERVERWINDOW_H

class Game;

//NEEDS BUNCHES OF WORK
#include <vector>
#include <QTcpSocket>
#include <QTcpServer>
#include <QMainWindow>
#include <QTimer>
#include <game.h>
#include <user.h>
#include <counter.h>

using namespace std;

namespace Ui {
class ServerWindow;
}

class Observer{
public:
    virtual void pauseGame() = 0;
    virtual void unpauseGame() = 0;
    virtual int getTime() = 0;
};

class ServerWindow : public QMainWindow, public Observer
{
    Q_OBJECT
    QTimer *timer;
    int ticks;
    QTcpServer server;
    vector<User *> unUsers;
    Game *game;
    bool timerGo;
    bool paused;
    //Counter *count;
    bool debug;
    int GetUserTeam();
    std::string GetLoadUsername();
    int curUserID;


public:
    explicit ServerWindow(QWidget *parent = 0);
    ~ServerWindow();
    void pauseGame()
    {
        timer->stop();
    }
    void unpauseGame(){timer->start();}
    int getTime(){return ticks;}

private slots:
    void clientConnected();
    void clientDisconnected();
    void dataReceived();
    void timerHit();
    void on_btnReset_clicked();

private:
    Ui::ServerWindow *ui;
    int connectCount;
    int gameCount;
};

#endif // SERVERWINDOW_H
