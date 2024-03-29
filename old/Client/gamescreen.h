#ifndef GAMESCREEN_H
#define GAMESCREEN_H

class GameScreen;

#include "widget.h"
#include "entitylabel.h"
#include "scorewindow.h"

#include <QWidget>
#include <QKeyEvent>
#include <QDebug>
#include <assert.h>
#include <QPixmap>
#include <vector>
#include <QResizeEvent>
#include <QFrame>
#include <QPushButton>
#include <QStringList>
#include <QTcpSocket>
#include <QList>
#include <vector>
#include <QTimer>


/*This class stares scores at the end of
    the game.*/
class ScoreObject
{
private:
    int minionKills;
    int playerDeaths;
    int playerKills;
    int playerTeam;
    int totalScore;
    int towerKills;

    QString user;

public:
    //Setter Methods
    void setDeaths(int i){playerDeaths = i;}
    void setMKills(int i){minionKills = i;}
    void setPKills(int i){playerKills = i;}
    void setTeam(int i){playerTeam = i;}
    void setTKills(int i){towerKills = i;}
    void setUsername(QString &s){user = s;}

    //Getter Methods
    int deaths(){return playerDeaths;}
    int mKills(){return minionKills;}
    int pKills(){return playerKills;}
    int team(){return playerTeam;}
    int tKills(){return towerKills;}
    int score(){return totalScore;}

    QString username(){return user;}

    //Other Methods

    //Calculates the score based on other variables.
    void calculate();
};


/*This class defines the actual gameplay window.*/
class GameScreen : public QWidget
{
    Q_OBJECT

    //Instance Variables

    bool downPressed;
    bool leftPressed;
    bool pPressed;
    bool rightPressed;
    bool spacePressed;
    bool targetChanged;
    bool upPressed;

    bool gameOver;

    int userID;
    int userTeam;

    int playerHealthPercent;
    int playerId;
    int targetHealthPercent;
    int targetId;

    EntityLabel *hero;

    Ui::GameScreen *gsui;
    
    QFrame *frGame;
    QFrame *frPause;

    QLabel *lblBar;
    QLabel *lblHud;
    QLabel *lblMap;
    QLabel *lblPlayerHealth;
    QLabel *lblPlayerIcon;
    QLabel *lblTargetHealth;
    QLabel *lblTargetIcon;

    QPushButton *btnMenu;
    QPushButton *btnPause;

    QString playername;

    QTcpSocket *sock;

    QTimer *timer;

    QWidget *wdgtGame;
    QWidget *wdgtPicture;

    Widget *w;

    std::vector<EntityLabel*> objects;

public:
    //Constructor
    explicit GameScreen(QWidget *parent = 0);

    //Destructor
    ~GameScreen();

    //Setter Methods
    //------------//

    //Sets <w> to <newW>
    void connectWidget(Widget *newW){w = newW;}

    //Sets <sock> to <s>
    void passSocket(QTcpSocket *s) {sock = s;}

    //Sets <playername> to <p>
    void setPlayername(QString p){playername = p;}

    void setUserTeam(int team){userTeam = team;}

    //Getter Methods
    //(Technically just used to find an EntityLabel in <objects>)
    //------------//

    EntityLabel* getByID(int id);
    int getIdByName(QString&);

    //Other methods
    //-----------//

    //Updates stylesheet of EntityLabel with <id>
    void animate(int id);

    //Changes heath of EntityLabel with <id> to <heathPercent>
    void changeEntityHealth(int id, int healthPercent);

    //Changes state of EntityLabel with <id> to <state>
    void changeEntityState(int id, int state);

    //Creates a new EntityLabel with the information in the variables
    void createEntity(int type, int id, int team, int health, int state, int posX, int posY, QString name);

    //"Kills" EntityLabel with <id>
    void exterminate(int id);

    //Moves EntityLabel with <id> to (<x>, <y>)
    void moveEntity(int id, int x, int y);

    //Shows EntityLabel with <id>
    void showLbl(int id);

    //Grabs keyboard control
    void takeOverKeyboard() { this->grabKeyboard(); }

    //clears the object list.
    void cleanObjects();

    //Starts the timer
    void TimeroftheGameGo(){timer->start();}

private slots:
    //Timer Calculations
    void onTimerHit();

    //MainMenu Button pressed
    void returnToMenu();

    //On Server Disconnect
    void serverDisconnected();

    //un-pauses the game
    void unPause();

    //Big long method that parses info from server
    void readCommand();


protected:
    //Overwritten Methods
    void closeEvent(QCloseEvent *);
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);
    void mousePressEvent(QMouseEvent *);
    void resizeEvent ( QResizeEvent *);
    void showEvent(QShowEvent *);

    //Other Methods

    //Changes the image of <targetIcon> based on type and team
    void updateTargetLabel(int targetType, int team);

};


#endif // GAMESCREEN_H
