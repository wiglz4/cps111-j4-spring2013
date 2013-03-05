#ifndef GAME_H
#define GAME_H
#include <QTimer>
#include "world.h"
#include <vector>
#include "user.h"
#include <QUdpSocket>
#include "serverwindow.h"

//NEEDS BUNCHES OF WORK

class Game
{
    static int curGameID;
    World *world;
    //QTimer *timer;//shunt to serverwindow
    bool over;
    vector<User *> users;
    QUdpSocket *sock;
    int readyCount;





public:
    Game(ServerWindow * window, vector<User*> *vect);
    void endGame(int team);
    void onTick();
};

#endif // GAME_H
