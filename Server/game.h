#ifndef GAME_H
#define GAME_H
#include <QTimer>
#include "world.h"
#include <vector>
#include "user.h"

class Game
{
    World *world;
    QTimer *timer;
    bool isPaused;
    //vector<users *> *users;

private slots:
    void timerHit();



public:
    Game();
};

#endif // GAME_H
