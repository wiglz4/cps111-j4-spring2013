#include "towershot.h"




void towerShot::onTick()
{

   /* if(objects.at(i)->toString().find(("Wanderer")) != std::string::npos)
            {
                targetRow = objects.at(i)->getRow();
                targetCol = objects.at(i)->getCol();
                distance = sqrt(pow(targetRow-row, 2) + pow(targetCol - col, 2));
                if(distance <= finalDistance && distance < viewDistance)
                {
                    found = true;
                    finalDistance = distance;
                    finalRow = objects.at(i)->getRow();
                    finalCol = objects.at(i)->getCol();
                }
            }
        }
        if(found)
        {
            theta = asin((row-finalRow)/finalDistance);
            delta = acos((col-finalCol)/finalDistance);
            if(finalRow > row)
            {
                row = row + abs(speed * sin(theta));
            }
            else
            {
                row = row - abs(speed * sin(theta));
            }
            if(finalCol > col)
            {
                col = col + abs(speed * cos(theta));
            }
            else
            {
                col = col - abs(speed * cos(theta));
            }*/
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
