#ifndef GAME_H
#define GAME_H
#include <QTimer>
class Game;
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
    bool over;
    vector<User *> users;
    QUdpSocket *sock;
    int readyCount;

public:
    Game(vector<User*> *vect);
    void endGame(int team);
    void onTick();
};

#endif // GAME_H
