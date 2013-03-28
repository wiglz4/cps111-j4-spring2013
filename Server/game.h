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
    //QUdpSocket *sock;     //Would be used for multiple games
    Observer *obs;
    void setMap(World* loadedWorld);
    Game();

public:
    Game(Observer *o, std::vector<User *> *unUsers);
    void endGame(int team);

    //performs time based ai operations as well as returns the display information for the map
    std::string onTick();//change this to return void if implementing multiple games, have it speak directly with all clients connected to this game
    bool getOver(){return over;}

    //loads an old game
    static Game* Load(Observer *o, std::vector<User *> *unUsers);

private:
    World *gmap;
};

#endif // GAME_H
