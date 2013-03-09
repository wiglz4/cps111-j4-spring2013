#ifndef GAME_H
#define GAME_H
#include <QUdpSocket>
#include <vector>

//NEEDS BUNCHES OF WORK
class World;
class User;

class Game
{
    World *world;
    bool over;
    std::vector<User *> *users;
    QUdpSocket *sock;

public:
    Game(std::vector<User *> *unUsers);
    void endGame(int team);
    std::string onTick();
    bool getOver(){return over;}

private:
    World *gmap;
};

#endif // GAME_H
