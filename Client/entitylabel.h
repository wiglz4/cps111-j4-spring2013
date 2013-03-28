#ifndef ENTITYLABEL_H
#define ENTITYLABEL_H
#include <QWidget>
#include <QLabel>
#include <QMouseEvent>

/*This class provides the basic "unit" of the game.
    All clientside units are just an EntityLabel.*/

class EntityLabel : public QLabel
{
    Q_OBJECT
protected:
    //Instance Variables
    int counter;
    int height;
    int id;
    int percentHealth;
    int state;
    int team;
    int type;
    int width;

    QString playerName;

    //Constants
    static const QString STYLE_BEGIN;
    static const QString STYLE_END;

public:
    //Constructor
    EntityLabel(int id, int initTeam, int type, int posX, int posY, int pHealth, int nState, QString pName, QWidget *parent = 0);

    //Setter Methods
    void setCounter(int newCounter){ counter = counter + newCounter;}
    void setHealth(int pHealth){percentHealth = pHealth;}
    void setID(int newID);
    void setState(int initState){state = initState;}

    //Getter Methods
    int getCounter(){return counter;}
    int getHealth(){return percentHealth;}
    int getID(){return id;}
    int getTeam(){return team;}
    int getType() { return type; }

    QString getName(){return playerName;}

    //Other Methods

    //Sets the label to its "dead" state.
    void die();
    //Increments counter based on the label's type.
    //  If it reaches the end of the animation loop
    //  it will reset the counter to 0.
    void nextFrame();
    //Updates the object's stylesheet based on the
    //  current values of its instance variables.
    void updateStyleSheet();
};

#endif // ENTITYLABEL_H
