#ifndef ENTITYLABEL_H
#define ENTITYLABEL_H
#include <QWidget>
#include <QLabel>

class EntityLabel : public QLabel
{
    Q_OBJECT
protected:
    int ID, type, team, counter, percentHealth, state;
    QString playerName;
    static const QString STYLE_BEGIN, STYLE_END;

public:
<<<<<<< HEAD
    EntityLabel(int id, int type, int posX, int posY, int pHealth, int nState, QString pName, QWidget *parent = 0);
=======
    EntityLabel(int id, int initTeam, int type, int posX, int posY, int pHealth, int nState, QString pName, QWidget *parent = 0);
>>>>>>> 0f4bc453af2bd4f84ca91483dbc06aa961822193
    void mousePressEvent(QMouseEvent *ev);
    void setID(int newID);
    void setCounter(int newCounter){ counter = counter + newCounter;}
    int getID(){return ID;}
    int getCounter(){return counter;}
    void setHealth(int pHealth){percentHealth = pHealth;}
<<<<<<< HEAD
    //void set
=======
    void setState(int initState){state = initState;}
    void updateStyleSheet();
    void nextFrame(){counter++;}
    void die();
>>>>>>> 0f4bc453af2bd4f84ca91483dbc06aa961822193

};

#endif // ENTITYLABEL_H
