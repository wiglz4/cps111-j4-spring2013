#include "entitylabel.h"

EntityLabel::EntityLabel(int id, int type, int initTeam, int posX, int posY, int pHealth, int nState, QString pName, QWidget *parent)
    : QLabel(parent), ID(id), team(initTeam), type(type), percentHealth(pHealth), state(nState),
      playerName(pName), counter(1)
{
    this->setGeometry(posX,posY,110,110);
    this->setStyleSheet(STYLE_BEGIN + QString("%1").arg(team) + "/" + QString("%1").arg(type) + "/" +
                        QString("%1").arg(state) + "/" + QString("%1").arg(counter) + STYLE_END);
}

void EntityLabel::mousePressEvent(QMouseEvent *ev)
{

}


void EntityLabel::die()
{
    if(ID == 3){
        hide();
    }
}


//static constants

const QString EntityLabel::STYLE_BEGIN = "background:url(:/images/";
const QString EntityLabel::STYLE_END = ".png) no-repeat top left;background-color:rgba(0, 0, 0, 0);";
