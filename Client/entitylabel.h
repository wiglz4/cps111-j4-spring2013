#ifndef ENTITYLABEL_H
#define ENTITYLABEL_H
#include <QWidget>
#include <QLabel>

class EntityLabel : public QLabel
{
    Q_OBJECT
    int ID;
public:
    explicit EntityLabel(QWidget *parent = 0);
    void mousePressEvent(QMouseEvent *ev);
    void setID(int newID);
    int getID(){return ID;}
};

#endif // ENTITYLABEL_H
