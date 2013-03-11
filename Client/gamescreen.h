#ifndef GAMESCREEN_H
#define GAMESCREEN_H

class gameScreen;

#include <QWidget>
#include "widget.h"
#include <QKeyEvent>
#include <QDebug>
#include <assert.h>
#include <QPixmap>
#include "entitylabel.h"
#include <vector>
#include <QResizeEvent>
#include <QFrame>
#include <QTcpSocket>
#include "scorewindow.h"
#include <QPushButton>
#include <QStringList>
#include <QTcpSocket>
#include <QList>
#include <vector>
//REM
#include <QTimer>
//REM




class gameScreen : public QWidget
{
    Q_OBJECT
    EntityLabel *hero;
    
public:
    explicit gameScreen(QWidget *parent = 0);
    void connectWidget(Widget *newW){w = newW;}
    ~gameScreen();
    void takeOverKeyboard() { wdgtGame->grabKeyboard(); }
    void passSocket(QTcpSocket *s) {sock = s;}

    void createEntity(int type, int id, int team, int health, int state, int posX, int posY, QString name);
    void moveEntity(int id, int x, int y);
    void changeEntityState(int id, int state);
    void changeEntityHealth(int id, int healthPercent);
    void animate(int id);
    void exterminate(int id);


    EntityLabel* getByID(int id);

private slots:
    void onTimerHit();
    void return_to_menu();
    void serverDisconnected();
    void unPause();
    void readCommand();
    
private:
    Ui::gameScreen *gsui;
    QWidget *wdgtGame;
    QWidget *wdgtPicture;
    QFrame *gameFrame;
    QFrame *pause;
    QPushButton *menu;
    QPushButton *btnPause;
    QLabel *bar;
    Widget *w;
    QTcpSocket *sock;
    std::vector<EntityLabel*> objects;

    //update methods called from server

     void updatePlayer(QStringList player);
     void updatePos(EntityLabel *lblToUpdate, int x, int y, int width, int height);

protected:
    void keyPressEvent(QKeyEvent * e);
    void keyReleaseEvent(QKeyEvent *e);
    void closeEvent(QCloseEvent *);
    void resizeEvent ( QResizeEvent * event );

    //REM
    QTimer *timer;/*
    bool wPressed;
    bool aPressed;
    bool sPressed;
    bool dPressed;*/
    bool pPressed;
    //REM

    bool upPressed;
    bool rightPressed;
    bool downPressed;
    bool leftPressed;


    //int counter;
};

#endif // GAMESCREEN_H
