#ifndef GAME_H
#define GAME_H
#include <QUdpSocket>
#include <vector>
#include "serverwindow.h"

//NEEDS BUNCHES OF WORK
class World;
class User;
class Observer;

class Game
{
    World *world;
    bool over;
    bool newOver;
    std::vector<User *> *users;
    QUdpSocket *sock;
    Observer *obs;
    void setMap(World* loadedWorld);
    Game();

public:
    Game(Observer *o, std::vector<User *> *unUsers);
    void endGame(int team);

    //performs all time-based actions on the map
    std::string onTick();

    bool getOver(){return over;}

    //loads an old game
    static Game* Load(Observer *o, std::vector<User *> *unUsers);

private:
    World *gmap;
};

#endif // GAME_H
