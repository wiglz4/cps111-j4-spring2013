#ifndef GAME_H
#define GAME_H
#include <QUdpSocket>
#include <vector>


class World;
class User;

class Game
{
    World *world;
    bool over;
    std::vector<User *> users;
    QUdpSocket *sock;

public:
    Game();
    void endGame(int team);
    void onTick();

private:
    World *gmap;
};

#endif // GAME_H
