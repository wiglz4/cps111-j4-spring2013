#ifndef GAMESCREEN_H
#define GAMESCREEN_H

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

//REM
#include <QTimer>
//REM

namespace Ui {
class Widget;
class gameScreen;
class ScoreWindow;
}

class gameScreen : public QWidget
{
    Q_OBJECT
    std::vector<EntityLabel*> labels;
    EntityLabel *hero;
    
public:
    explicit gameScreen(QWidget *parent = 0);
    ~gameScreen();

private slots:
    void onTimerHit();
    void readCommand();
    void serverDisconnected();
    
private:
    Ui::gameScreen *gsui;
    QWidget *wdgtGame;
    QWidget *wdgtPicture;
    QFrame *gameFrame;
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
