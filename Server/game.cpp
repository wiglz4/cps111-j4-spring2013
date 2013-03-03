#include "game.h"

//NEEDS BUNCHES OF WORK

Game::Game(ServerWindow * window)
{
    home = window;
    timer = new QTimer(home);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimerHit()));
    timer->setInterval(20);
    over = false;
}
