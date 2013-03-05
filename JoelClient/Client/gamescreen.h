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

//REM
#include <QTimer>
//REM




class gameScreen : public QWidget
{
    Q_OBJECT
    std::vector<EntityLabel*> labels;
    EntityLabel *hero;
    
public:
    explicit gameScreen(QWidget *parent = 0);
    void connectWidget(Widget *newW){w = newW;}
    ~gameScreen();

private slots:
    void onTimerHit();
    void return_to_menu();
    void readCommand();
    void serverDisconnected();
    
private:
    Ui::gameScreen *gsui;
    QWidget *wdgtGame;
    QWidget *wdgtPicture;
    QFrame *gameFrame;
    QPushButton *menu;
    Widget *w;
    QTcpSocket *mySocket;

protected:
    void keyPressEvent(QKeyEvent * e);
    void keyReleaseEvent(QKeyEvent *e);
    void closeEvent(QCloseEvent *);
    void resizeEvent ( QResizeEvent * event );

    //REM
    QTimer *timer;
    bool wPressed;
    bool aPressed;
    bool sPressed;
    bool dPressed;
    //REM

    bool upPressed;
    bool rightPressed;
    bool downPressed;
    bool leftPressed;

    int counter;
};

#endif // GAMESCREEN_H
