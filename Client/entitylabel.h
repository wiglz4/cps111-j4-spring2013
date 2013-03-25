#ifndef ENTITYLABEL_H
#define ENTITYLABEL_H
#include <QWidget>
#include <QLabel>
#include <QMouseEvent>

class EntityLabel : public QLabel
{
    Q_OBJECT
protected:
    int ID, type, team, counter, percentHealth, state;
    int width, height;
    QString playerName;
    static const QString STYLE_BEGIN, STYLE_END;

public:
    EntityLabel(int id, int initTeam, int type, int posX, int posY, int pHealth, int nState, QString pName, QWidget *parent = 0);
    void setID(int newID);
    void setCounter(int newCounter){ counter = counter + newCounter;}
    int getID(){return ID;}
    int getCounter(){return counter;}
    int getTeam(){return team;}
    void setHealth(int pHealth){percentHealth = pHealth;}
    //void set
    void setState(int initState){state = initState;}
    void updateStyleSheet();
    void nextFrame();
    void die();
    int getType() { return type; }

    QString getName(){return playerName;}
    int getHealth(){return percentHealth;}

signals:
    void clicked(int id);

};

#endif // ENTITYLABEL_H
