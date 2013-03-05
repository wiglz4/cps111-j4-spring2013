#include "towershot.h"
double towerShot::speed = 8;
string towerShot::DispShot()
{
    //NEEDS CODING
}

void towerShot::onTick()
{
    double distance = sqrt(pow(target->getY()-y, 2) + pow(target->getX() - x, 2));
    double theta = asin((y-target->getY())/distance);
    if(target->getY() > y)
    {
        y = y + abs(speed * sin(theta));
    }
    else
    {
        y = y - abs(speed * sin(theta));
    }
    if(target->getX() > x)
    {
        x = x + abs(speed * cos(theta));
    }
    else
    {
        x = x - abs(speed * cos(theta));
    }
}
