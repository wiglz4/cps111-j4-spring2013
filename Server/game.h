#ifndef GAME_H
#define GAME_H
#include <QTimer>
#include "world.h"
#include <vector>
#include "user.h"
#include "myudpsocket.h"

class Game
{
    static int curGameID;
    World *world;
    QTimer *timer;
    bool isPaused;
    vector<User *> users;

private slots:
    void timerHit();



public:
    Game();
};

#endif // GAME_H
