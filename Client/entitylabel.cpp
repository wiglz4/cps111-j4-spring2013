#include "entitylabel.h"

#include <QDebug>

//-----------------------------------------------------------
//File:   entitylabel.cpp
//Authors: Jeremie Miller, Jonathan Neves, Joel Sampson, John Wiglesworth
//User IDs: jmill521, jneve321, jsamp710, jwigl437   Class: CPS 110
//Desc:   This class provides the basic "unit" of the game.
//          All clientside units are just an EntityLabel.
//-----------------------------------------------------------

//Constructor
EntityLabel::EntityLabel(int id, int type, int initTeam,
                         int posX, int posY, int pHealth,
                         int nState, QString pName, QWidget *parent)
    : QLabel(parent), id(id), team(initTeam),
      type(type), percentHealth(pHealth), state(nState),
      playerName(pName), counter(1)
{
    //Set size
    if(type == 1)//core
    {
        width = 960;
        height = 540;
    }
    else if (type == 2)//tower
    {
        width = 480;
        height = 360;
    }
    else if (type == 3)//minion
    {
        width = 110;
        height = 110;
    }
    else if (type == 4)//player
    {
        width = 110;
        height = 110;
    }

    this->setGeometry(posX,posY,width,height);
    updateStyleSheet();

}

//Sets the label to its "dead" state.
void EntityLabel::die()
{
    if (this->type == 2) //tower
    {
    }
    else if (this->type == 3) //minion
    {
        this->nextFrame();
    }
    else if (this->type == 4) //player
    {
        this->nextFrame();
    }
}

//Increments counter based on the label's type.
//  If it reaches the end of the animation loop
//  it will reset the counter to 0.
void EntityLabel::nextFrame(){
    if(type == 3 || type == 4)//minion or player
    {
        if (state ==9)
        qDebug() << state;
        if (state == 9 && counter == 19)
        {
            this->hide();
        }
        if(counter == 19)
        {
            counter = 1;
        }
        else
        {
            counter++;
        }

    }
    else if (type == 1) //core
    {
        if (counter == 30)
        {
            counter = 1;
        }
        else
        {
            counter++;
        }
    }
}

//Updates the object's stylesheet based on the
//  current values of its instance variables.
void EntityLabel::updateStyleSheet(){
    this->setStyleSheet(STYLE_BEGIN + QString("%1").arg(team) +
                        "/" + QString("%1").arg(type) + "/" +
                        QString("%1").arg(state) + "/" +
                        QString("%1").arg(counter) + STYLE_END);
}

//Constants
const QString EntityLabel::STYLE_BEGIN = "background:url(:/images/";
const QString EntityLabel::STYLE_END = ".png) no-repeat top left;background-color:rgba(0, 0, 0, 0);";
