#include "entitylabel.h"

EntityLabel::EntityLabel(int id, int type, int posX, int posY, QWidget *parent)
    : QLabel(parent), ID(id), type(type)
{
    counter = 1;
    this->setGeometry(posX,posY,110,110);
    this->setStyleSheet("background:url(:/images/2/4/3/1.png) no-repeat top left;background-color:rgba(0, 0, 0, 0);");
}

void EntityLabel::mousePressEvent(QMouseEvent *ev)
{

}
