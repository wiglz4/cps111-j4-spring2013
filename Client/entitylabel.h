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

public:
    EntityLabel(int id, int type, int posX, int posY, QWidget *parent = 0);
    void mousePressEvent(QMouseEvent *ev);
    void setID(int newID);
    void setCounter(int newCounter){ counter = counter + newCounter;}
    int getID(){return ID;}
    int getCounter(){return counter;}

};

#endif // ENTITYLABEL_H
