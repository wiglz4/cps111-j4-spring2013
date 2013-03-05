#ifndef GAME_H
#define GAME_H
#include <QUdpSocket>

class World;

class Game
{
    World *world;
    bool over;
    //vector<User *> users;
    QUdpSocket *sock;

public:
    Game();
    void endGame(int team);
    void onTick();

};

#endif // GAME_H
