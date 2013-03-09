#ifndef ENTITYLABEL_H
#define ENTITYLABEL_H
#include <QWidget>
#include <QLabel>

class EntityLabel : public QLabel
{
    Q_OBJECT
protected:
    int ID;
    int type;
    int counter;
    int percentHealth;
    int state;
    QString playerName;

public:
    EntityLabel(int id, int type, int posX, int posY, int pHealth, int nState. QString pName, QWidget *parent = 0);
    void mousePressEvent(QMouseEvent *ev);
    void setID(int newID);
    void setCounter(int newCounter){ counter = counter + newCounter;}
    int getID(){return ID;}
    int getCounter(){return counter;}
    void setHealth(int pHealth){percentHealth = pHealth;}
    void set

};

#endif // ENTITYLABEL_H
