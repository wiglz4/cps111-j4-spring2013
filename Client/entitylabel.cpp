#include "entitylabel.h"
#include <QDebug>

EntityLabel::EntityLabel(int id, int type, int initTeam, int posX, int posY, int pHealth, int nState, QString pName, QWidget *parent)
    : QLabel(parent), ID(id), team(initTeam), type(type), percentHealth(pHealth), state(nState),
      playerName(pName), counter(1)
{
    int width, height;
    if(type == 1){
        width = 960;
        height = 540;
    } else if (type == 2){
        width = 480;
        height = 360;
    } else if (type == 3){
        width = 110;
        height = 110;
    } else if (type == 4){
        width = 110;
        height = 110;
    }
    this->setGeometry(posX,posY,width,height);
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
            counter = 1;
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
    qDebug() << counter;
}

//static constants

const QString EntityLabel::STYLE_BEGIN = "background:url(:/images/";
const QString EntityLabel::STYLE_END = ".png) no-repeat top left;background-color:rgba(0, 0, 0, 0);";
