#include "entitylabel.h"

EntityLabel::EntityLabel(int id, int type, int posX, int posY, int pHealth, int nState, QString pName, QWidget *parent)
    : QLabel(parent), ID(id), type(type), percentHealth(pHealth), state(nState),
      playerName(pName)
{
    counter = 1;
    this->setGeometry(posX,posY,110,110);
    this->setStyleSheet("background:url(:/images/2/4/3/1.png) no-repeat top left;background-color:rgba(0, 0, 0, 0);");
}

void EntityLabel::mousePressEvent(QMouseEvent *ev)
{

}
