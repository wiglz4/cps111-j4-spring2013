#include "entitylabel.h"
#include <QDebug>

EntityLabel::EntityLabel(int id, int type, int initTeam, int posX, int posY, int pHealth, int nState, QString pName, QWidget *parent)
    : QLabel(parent), ID(id), team(initTeam), type(type), percentHealth(pHealth), state(nState),
      playerName(pName), counter(1)
{
    this->setGeometry(posX,posY,110,110);
    updateStyleSheet();
    qDebug() << this->styleSheet();
}

void EntityLabel::mousePressEvent(QMouseEvent *ev)
{

}

void EntityLabel::updateStyleSheet(){
    this->setStyleSheet(STYLE_BEGIN + QString("%1").arg(team) + "/" + QString("%1").arg(type) + "/" +
                        QString("%1").arg(state) + "/" + QString("%1").arg(counter) + STYLE_END);
}

void EntityLabel::die()
{
    if(ID == 3){
        hide();
    }
}

void EntityLabel::nextFrame(){
    if(type == 3 || type == 4){
        if(counter == 19){
            counter == 1;
        } else {
            counter++;
        }
    } else if (type == 1){
        if (counter == 30){
            counter = 1;
        } else {
            counter++;
        }
    }
}

//static constants

const QString EntityLabel::STYLE_BEGIN = "background:url(:/images/";
const QString EntityLabel::STYLE_END = ".png) no-repeat top left;background-color:rgba(0, 0, 0, 0);";
