//-----------------------------------------------------------
//File:   gamescreen.cpp
//Authors: Jeremie Miller, Jonathan Neves, Joel Sampson, John Wiglesworth
//User IDs: jmill521, jneve321, jsamp710, jwigl437   Class: CPS 110
//Desc:   This provides the window where all the fun part of the game
//          happens.
//-----------------------------------------------------------

#include "gamescreen.h"
#include "ui_gamescreen.h"
#include "entitylabel.h"
#include "scorewindow.h"

#include <QPixmap>
#include <QString>
#include <QByteArray>
#include <QTcpServer>
#include <QTcpSocket>
#include <QUdpSocket>
#include <QStringList>
#include <string>
#include <vector>
#include <sstream>
#include <QDesktopWidget>
#include <QSize>


//Constructor
GameScreen::GameScreen(QWidget *parent) :
    QWidget(parent),
    gsui(new Ui::GameScreen)
{
    gsui->setupUi(this);

    playerHealthPercent = 100;
    targetHealthPercent = 100;
    playerId = 0;
    targetId = 0;

    hero = NULL;
    userID = 0;
    userTeam = 0;

    targetChanged = false;
    upPressed = false;
    rightPressed = false;
    downPressed = false;
    leftPressed = false;
    spacePressed = false;

    wdgtGame = new QWidget(this);
    wdgtGame->setGeometry(-100, -2150, 4000, 3000);
    wdgtGame->setStyleSheet("background-color: rgba(0,0,0,212);");

    wdgtPicture = new QWidget(wdgtGame);
    wdgtPicture->setGeometry(0,0,4000,3000);
    wdgtPicture->setStyleSheet("background-image:url(:/images/map4.png)");

    lblHud = new QLabel(this);
    lblHud->setGeometry(0, 0, 800, 600);
    lblHud->setStyleSheet("background:url(:/images/hud.png) no-repeat bottom left; background-color: rgba(0,0,0,0);");
    lblHud->show();

    frGame = new QFrame(this);
    frGame->setFrameShape(QFrame::Box);
    frGame->setLineWidth(10);
    frGame->setStyleSheet("color:rgba(0,0,0;212);");
    frGame->setGeometry(0, 0, 800, 600);
    frGame->show();

    frPause = new QFrame(frGame);
    frPause->setGeometry(0, 0, 4000, 3000);
    frPause->setStyleSheet("background-color:rgba(0, 0, 0, 100);");
    frPause->hide();
    pPressed = false;

    lblMap = new QLabel(frPause);
    lblMap->setGeometry(100, 100, 410, 310);
    lblMap->setStyleSheet("background: url(:/images/background3.png) no-repeat top left");
    lblMap->hide();


    btnMenu = new QPushButton(frGame);
    btnMenu->setGeometry(588,310,121,31);
    btnMenu->setFlat(true);
    btnMenu->setStyleSheet("QPushButton { background:url(:/images/buttonmm) no-repeat right top; } QPushButton:hover{ background:url(:/images/buttonmm2.png) no-repeat right top; } QPushButton:pressed { background:url(:/images/buttonmm.png) no-repeat right top; border: 0px solid grey; }");
    btnMenu->setFocusPolicy(Qt::NoFocus);
    btnMenu->hide();
    connect(this->btnMenu, SIGNAL(clicked()), this, SLOT(returnToMenu()));

    btnPause = new QPushButton(frGame);
    btnPause->setGeometry(600,285,121,31);
    btnPause->setFlat(true);
    btnPause->setStyleSheet("QPushButton { background:url(:/images/buttonpa) no-repeat right top; } QPushButton:hover{ background:url(:/images/buttonpa2.png) no-repeat right top; } QPushButton:pressed { background:url(:/images/buttonpa.png) no-repeat right top; border: 0px solid grey; }");
    btnPause->setFocusPolicy(Qt::NoFocus);
    btnPause->hide();
    connect(this->btnPause, SIGNAL(clicked()), this, SLOT(unPause()));

    lblBar = new QLabel(frGame);
    lblBar->setGeometry(700,265,21,100);
    lblBar->setStyleSheet("background:url(:/images/bar.png) no-repeat top left;");
    lblBar->hide();

    lblPlayerIcon = new QLabel(this);
    lblPlayerIcon->setGeometry(34, 461, 110, 110);

    lblPlayerHealth = new QLabel(this);
    lblPlayerHealth->setGeometry(49, 556, playerHealthPercent, 10);
    lblPlayerHealth->setStyleSheet("background-color:#00ff00;");
    lblPlayerHealth->show();

    lblTargetIcon = new QLabel(this);
    lblTargetIcon->setGeometry(639, 461, 110, 110);
    lblTargetIcon->setStyleSheet("background-color:#000000;");

    lblTargetHealth = new QLabel(this);
    lblTargetHealth->setGeometry(654, 466, 100, 10);
    lblTargetHealth->setStyleSheet("background-color:#00ff00;");

    QDesktopWidget *desktop = QApplication::desktop();
    int screenWidth, width;
    int screenHeight, height;
    int x, y;
    QSize windowSize;

    screenWidth = desktop->width();
    screenHeight = desktop->height();

    windowSize = size();
    width = windowSize.width();
    height = windowSize.height();

    x = (screenWidth - width)/2;
    y = (screenHeight - height)/2;
    y -= 50;

    move(x, y);

    setMouseTracking(true);

    timer = new QTimer(this);
    timer->setInterval(20);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimerHit()));
    //timer->start();
}

//Destructor
GameScreen::~GameScreen()
{
    delete gsui;
}


//hides pause menu
void GameScreen::unPause()
{
    sock->write("7\n");
}

//registers key press
void GameScreen::keyPressEvent(QKeyEvent *e)
{
    if((e->key() == Qt::Key_P && !e->isAutoRepeat() || (e->key() == Qt::Key_Escape && !e->isAutoRepeat())))
    {
        sock->write("7\n");
    }
    if(e->key() == Qt::Key_W && !e->isAutoRepeat())
    {
        sock->write("2 1 ");
    }
    if(e->key() == Qt::Key_A && !e->isAutoRepeat())
    {
        sock->write("2 4 ");
    }
    if(e->key() == Qt::Key_S && !e->isAutoRepeat())
    {
        sock->write("2 3 ");
    }
    if(e->key() == Qt::Key_D && !e->isAutoRepeat())
    {
        sock->write("2 2 ");
    }
    if(e->key() == Qt::Key_Up && !e->isAutoRepeat())
    {
        upPressed = true;
    }
    if(e->key() == Qt::Key_Left && !e->isAutoRepeat())
    {
        leftPressed = true;
    }
    if(e->key() == Qt::Key_Down && !e->isAutoRepeat())
    {
        downPressed = true;
    }
    if(e->key() == Qt::Key_Right && !e->isAutoRepeat())
    {
        rightPressed = true;
    }
    if(e->key() == Qt::Key_Space && !e->isAutoRepeat())
    {
        spacePressed = !spacePressed;
    }
}


//registers key release
void GameScreen::keyReleaseEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_W && !e->isAutoRepeat())
    {
        sock->write("3 1 ");
    }
    if(e->key() == Qt::Key_A && !e->isAutoRepeat())
    {
        sock->write("3 4 ");
    }
    if(e->key() == Qt::Key_S && !e->isAutoRepeat())
    {
        sock->write("3 3 ");
    }
    if(e->key() == Qt::Key_D && !e->isAutoRepeat())
    {
        sock->write("3 2 ");
    }
    if(e->key() == Qt::Key_Up && !e->isAutoRepeat())
    {
        upPressed = false;
    }
    if(e->key() == Qt::Key_Left && !e->isAutoRepeat())
    {
        leftPressed = false;
    }
    if(e->key() == Qt::Key_Down && !e->isAutoRepeat())
    {
        downPressed = false;
    }
    if(e->key() == Qt::Key_Right && !e->isAutoRepeat())
    {
        rightPressed = false;
    }
    if(e->key() == Qt::Key_Space && !e->isAutoRepeat())
    {
        //spacePressed = false;
    }

}

//processes updates parts of the gui and sends information to
//server every timer hit
void GameScreen::onTimerHit()
{
    if(playerId == 0)
    {
        if(hero != NULL)
        {
            playerId = hero->getID();
            if(playerId != 0)
            {
                EntityLabel *e = getByID(playerId);
                if(e->getTeam() == 1)
                {
                    lblPlayerIcon->setStyleSheet("background:url(:/images/icons/redhero.png) no-repeat top right; background-color: rgba(0,0,0,0);");
                }
                else
                {
                    lblPlayerIcon->setStyleSheet("background:url(:/images/icons/bluehero.png) no-repeat top right; background-color: rgba(0,0,0,0);");
                }
                lblPlayerIcon->show();
            }
        }
    }
    else
    {
        playerHealthPercent = hero->getHealth();
    }

    if(targetId > 0)
    {
        EntityLabel *e = getByID(targetId);
        targetHealthPercent = e->getHealth();

        updateTargetLabel(e->getType(), e->getTeam());

        lblTargetIcon->show();
        lblTargetHealth->show();
    }
    else
    {
        lblTargetIcon->hide();
        lblTargetHealth->hide();
    }
    if(spacePressed)
    {
        int hx = hero->x();
        int hy = hero->y();
        int ww = this->width();
        int wh = this->height();
        int gw = wdgtPicture->width();
        int gh = wdgtPicture->height();
        if(gh - hy -wh + this->height() < 2750 && gh - hy -wh > -260 && ww/2 - hx - this->width() > -3900 && ww/2 - hx < 110)
        {
            wdgtPicture->move(0-hx+ww/2, gh-hy-wh);
        }
        else if(gh - hy -wh + this->height() < 2750 && gh - hy - wh > -260)
        {
            wdgtPicture->move(wdgtPicture->x(), gh- hy - wh);
        }
        else if(ww/2 - hx - this->width() > -3900 && ww/2 - hx < 110)
        {
            wdgtPicture->move(0-hx+ww/2, wdgtPicture->y());
        }
    }
    else
    {
        int pureSpeed = 10;
        int modSpeed = 8;
        if(upPressed && !rightPressed && !downPressed && !leftPressed)
        {
            //1
            if(wdgtPicture->y() + this->height() + pureSpeed < 2750)
            {
                wdgtPicture->move(wdgtPicture->x(), wdgtPicture->y() + pureSpeed);
                //qDebug()<<wdgtPicture->x()<<" "<<wdgtPicture->y();
                //wdgtPicture->scroll(0, -pureSpeed);
            }
        }
        if(upPressed && rightPressed && !downPressed && !leftPressed)
        {
            //2
            if(wdgtPicture->x() - this->width() - modSpeed > -3900 && wdgtPicture->y() +this->height() + modSpeed < 2750 )
            {
                wdgtPicture->move(wdgtPicture->x() - modSpeed, wdgtPicture->y() + modSpeed);
                //qDebug()<<wdgtPicture->x()<<" "<<wdgtPicture->y();
                //wdgtPicture->scroll(modSpeed, -modSpeed);
            }
        }
        if(!upPressed && rightPressed && !downPressed && !leftPressed)
        {
            //3
            if(wdgtPicture->x() - this->width()- pureSpeed > -3900)
            {
                wdgtPicture->move(wdgtPicture->x() - pureSpeed , wdgtPicture->y());
                // qDebug()<<wdgtPicture->x()<<" "<<wdgtPicture->y();
                //wdgtPicture->scroll(pureSpeed, 0);
            }
        }
        if(!upPressed && rightPressed && downPressed && !leftPressed)
        {
            //4
            if(wdgtPicture->x() - this->width() -modSpeed > -3098 && wdgtPicture->y() - modSpeed > -260)
            {
                wdgtPicture->move(wdgtPicture->x()-modSpeed, wdgtPicture->y() - modSpeed);
                // qDebug()<<wdgtPicture->x()<<" "<<wdgtPicture->y();
                //wdgtPicture->scroll(modSpeed, modSpeed);
            }
        }
        if(!upPressed && !rightPressed && downPressed && !leftPressed)
        {
            //5
            if(wdgtPicture->y() - pureSpeed > -260)
            {
                wdgtPicture->move(wdgtPicture->x(), wdgtPicture->y() - pureSpeed);
                // qDebug()<<wdgtPicture->x()<<" "<<wdgtPicture->y();
                //wdgtPicture->scroll(0, pureSpeed);
            }
        }
        if(!upPressed && !rightPressed && downPressed && leftPressed)
        {
            //6
            if(wdgtPicture->x() + modSpeed < 110 && wdgtPicture->y() - modSpeed > -260)
            {
                wdgtPicture->move(wdgtPicture->x() + modSpeed, wdgtPicture->y() - modSpeed);
                // qDebug()<<wdgtPicture->x()<<" "<<wdgtPicture->y();
                //wdgtPicture->scroll(-modSpeed, pureSpeed);
            }
        }
        if(!upPressed && !rightPressed && !downPressed && leftPressed)
        {
            //7
            if(wdgtPicture->x() + pureSpeed < 110)
            {
                wdgtPicture->move(wdgtPicture->x() + pureSpeed, wdgtPicture->y());
                //qDebug()<<wdgtPicture->x()<<" "<<wdgtPicture->y();
                //wdgtPicture->scroll(-pureSpeed,0);

            }
        }
        if(upPressed && !rightPressed && !downPressed && leftPressed)
        {
            //8
            if(wdgtPicture->x() + modSpeed < 110 && wdgtPicture->y() +this->height()+ modSpeed < 2750)
            {
                wdgtPicture->move(wdgtPicture->x() + modSpeed, wdgtPicture->y() + modSpeed);
                // qDebug()<<wdgtPicture->x()<<" "<<wdgtPicture->y();
                //wdgtPicture->scroll(-modSpeed, -modSpeed);
            }
        }
    }
    lblPlayerHealth->setGeometry(39, this->height() - 44, playerHealthPercent, 10);
    if(targetId != 0){
        lblTargetHealth->setGeometry(644, this->height() - 134, targetHealthPercent, 10);
    }

}

//make sure things stop when window is closed
void GameScreen::closeEvent(QCloseEvent *)
{
    timer->stop();
}

//makes sure everything is in proper place when the window changes size
void GameScreen::resizeEvent(QResizeEvent *event)
{
    frGame->resize(event->size());
    wdgtGame->setGeometry(-100, this->height() - 2750, 4000, 3000);
    lblHud->setGeometry(10, 0, 800, this->height() - 10);

    lblPlayerIcon->setGeometry(34, this->height() - 139, 110, 110);
    lblPlayerHealth->setGeometry(49, this->height() - 44, playerHealthPercent, 10);


    lblTargetIcon->setGeometry(639, this->height() - 139, 110, 110);
    lblTargetHealth->setGeometry(654, this->height() - 134, targetHealthPercent, 10);

}

void GameScreen::showEvent(QShowEvent *)
{
    if(userTeam == 1)
    {
        //if(wdgtPicture->x() - this->width() - modSpeed > -3900 && wdgtPicture->y() +this->height() + modSpeed < 2750 )
        wdgtPicture->move(-3878 + this->width(),2740 - this->height());
    }
}

//registers mouse clicks
void GameScreen::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton){
        QWidget *l = wdgtPicture->childAt(e->x() + abs(wdgtGame->x()) - wdgtPicture->x(), e->y() + abs(wdgtGame->y()) - wdgtPicture->y());
        EntityLabel *thing = dynamic_cast<EntityLabel*>(l);
        if(thing){
            QString msg = "1 " + QString::number(thing->getID()) +"\n";
            sock->write(msg.toAscii());
            targetId = thing->getID();
            if (targetId == playerId){
                targetId = 0;
            }
        }
    }
}

//updates the image of target
void GameScreen::updateTargetLabel(int targetType, int team)
{
    if(team == 1){
        switch(targetType){
        case 1:
            lblTargetIcon->setStyleSheet("background:url(:/images/icons/redcore.png) no-repeat top right");
            break;
        case 2:
            lblTargetIcon->setStyleSheet("background:url(:/images/icons/redturret.png) no-repeat top right");
            break;
        case 3:
            lblTargetIcon->setStyleSheet("background:url(:/images/icons/redbot.png) no-repeat top right");
            break;
        case 4:
            lblTargetIcon->setStyleSheet("background:url(:/images/icons/redhero.png) no-repeat top right");
            break;
        }
    } else if (team == 2) {
        switch(targetType){
        case 1:
            lblTargetIcon->setStyleSheet("background:url(:/images/icons/bluecore.png) no-repeat top right");
            break;
        case 2:
            lblTargetIcon->setStyleSheet("background:url(:/images/icons/blueturret.png) no-repeat top right");
            break;
        case 3:
            lblTargetIcon->setStyleSheet("background:url(:/images/icons/bluebot.png) no-repeat top right");
            break;
        case 4:
            lblTargetIcon->setStyleSheet("background:url(:/images/icons/bluehero.png) no-repeat top right");
            break;
        }
    }
}

//goes back to main menu
void GameScreen::returnToMenu(){
    this->hide();
    this->releaseKeyboard();
    this->releaseMouse();
    if(pPressed)
    {
        timer->start();
        pPressed = false;
        btnPause->hide();
        btnMenu->hide();
        frPause->hide();
        lblBar->hide();
        lblMap->hide();
    }
    cleanObjects();
    sock->close();
    w->show();
}

//deciphers all the wonderful numbers which come from the
//magic server...
void GameScreen::readCommand()
{
    while(sock->canReadLine())
    {
        QString str = sock->readLine();
        str.remove("\n");
        if(str != "")
        {
            QStringList list = str.split(" ", QString::SkipEmptyParts);
            int iterate = 0;
            int verifier = list.at(iterate).toInt();
            ++iterate;
            if (verifier == 97179)
            {
                int entv, pHealth, x, y, id, state, team, type, playerID;
                QString playername;
                for(; iterate < list.size();)
                {
                    entv = 0;
                    pHealth = 0;
                    x = 0;
                    y = 0;
                    id = 0;
                    state = 0;
                    team = 0;
                    playername = "";
                    entv = list.at(iterate).toInt();
                    ++iterate;
                    type = entv/10;
                    qDebug()<<entv;
                    switch (entv)
                    {
                    case 777:
                        this->userID = list.at(iterate).toInt();
                        ++iterate;
                        break;

                    case 5:
                        qDebug() << "towershot";
                        x = list.at(iterate).toInt();
                        ++iterate;
                        y = list.at(iterate).toInt();
                        ++iterate;

                        break;
                        //pause
                    case 7:
                        if (pPressed == false) {
                            timer->stop();
                            pPressed = true;
                            frPause->show();
                            btnPause->show();
                            btnMenu->show();
                            lblBar->show();
                            lblMap->show();
                        } else {
                            timer->start();
                            pPressed = false;
                            btnPause->hide();
                            btnMenu->hide();
                            frPause->hide();
                            lblBar->hide();
                            lblMap->hide();
                        }
                        break;

                        //create and load
                    case 11: //core
                    case 21: //tower
                    case 31: //minion
                    case 41: //player
                        id = list.at(iterate).toInt();
                        ++iterate;
                        team = list.at(iterate).toInt();
                        ++iterate;
                        pHealth = list.at(iterate).toInt();
                        ++iterate;
                        state = list.at(iterate).toInt();
                        ++iterate;
                        x = list.at(iterate).toInt();
                        ++iterate;
                        y = list.at(iterate).toInt();
                        ++iterate;
                        playername = list.at(iterate);
                        ++iterate;
                        createEntity(type, id, team, pHealth, state, x, y, playername);
                        if(entv == 41)
                        {
                            playerID = list.at(iterate).toInt();
                            if(userID == list.at(iterate).toInt())
                            {
                                hero = objects.at(objects.size()-1);
                            }
                            ++iterate;
                        }
                        showLbl(id);
                        break;

                        //position change
                    case 32: //minion
                    case 42: //player
                        id = list.at(iterate).toInt();
                        ++iterate;
                        x = list.at(iterate).toInt();
                        ++iterate;
                        y = list.at(iterate).toInt();
                        ++iterate;
                        moveEntity(id, x, y);
                        animate(id);
                        showLbl(id);
                        break;

                        //state change
                    case 23: //tower
                    case 33: //minion
                    case 43: //player
                        id = list.at(iterate).toInt();
                        ++iterate;
                        state = list.at(iterate).toInt();
                        ++iterate;
                        changeEntityState(id, state);
                        animate(id);
                        showLbl(id);
                        break;

                        //state and position change
                    case 34: //minion
                    case 44: //player

                        id = list.at(iterate).toInt();
                        ++iterate;
                        state = list.at(iterate).toInt();
                        ++iterate;
                        x = list.at(iterate).toInt();
                        ++iterate;
                        y = list.at(iterate).toInt();
                        ++iterate;
                        changeEntityState(id, state);
                        moveEntity(id, x, y);
                        animate(id);
                        showLbl(id);
                        break;

                        //health change
                    case 15: //core
                    case 25: //tower
                    case 35: //minion
                    case 45: //player
                        id = list.at(iterate).toInt();
                        ++iterate;
                        pHealth = list.at(iterate).toInt();
                        ++iterate;
                        changeEntityHealth(id, pHealth);
                        showLbl(id);
                        break;

                        //health and position change
                    case 36: //minion
                    case 46: //player
                        id = list.at(iterate).toInt();
                        ++iterate;
                        pHealth = list.at(iterate).toInt();
                        ++iterate;
                        x = list.at(iterate).toInt();
                        ++iterate;
                        y = list.at(iterate).toInt();
                        ++iterate;
                        changeEntityHealth(id, pHealth);
                        moveEntity(id, x, y);
                        animate(id);
                        showLbl(id);
                        break;

                        //health and state change
                    case 27: //tower
                    case 37: //minion
                    case 47: //player
                        id = list.at(iterate).toInt();
                        ++iterate;
                        pHealth = list.at(iterate).toInt();
                        ++iterate;
                        state = list.at(iterate).toInt();
                        ++iterate;
                        changeEntityHealth(id, pHealth);
                        changeEntityState(id, state);
                        animate(id);
                        showLbl(id);
                        break;

                        //heath state and position change
                    case 38: //minion
                    case 48: //player
                        id = list.at(iterate).toInt();
                        ++iterate;
                        pHealth = list.at(iterate).toInt();
                        ++iterate;
                        state = list.at(iterate).toInt();
                        ++iterate;
                        x = list.at(iterate).toInt();
                        ++iterate;
                        y = list.at(iterate).toInt();
                        ++iterate;
                        changeEntityHealth(id, pHealth);
                        changeEntityState(id, state);
                        moveEntity(id, x, y);
                        animate(id);
                        showLbl(id);
                        break;

                        //death
                    case 19: //core
                    case 29: //tower
                    case 39: //minion
                    case 49: //player
                        id = list.at(iterate).toInt();
                        ++iterate;
                        changeEntityState(id, 9);
                        animate(id);
                        showLbl(id);
                        exterminate(id);
                        break;

                        //endgame
                    case 50:
                        ScoreWindow *s = new ScoreWindow(w);
                        s->connectWidget(w);
                        int deaths;
                        int mKills;
                        int tKills;
                        int team;
                        int pKills;
                        QString name;
                        while(list.at(iterate).toStdString() == "P"){
                            ++iterate;
                            ScoreObject *score = new ScoreObject;
                            name = list.at(iterate);
                            ++iterate;
                            team = list.at(iterate).toInt();
                            ++iterate;
                            tKills = list.at(iterate).toInt();
                            ++iterate;
                            mKills = list.at(iterate).toInt();
                            ++iterate;
                            pKills = list.at(iterate).toInt();
                            ++iterate;
                            deaths = list.at(iterate).toInt();
                            ++iterate;
                            score->setDeaths(deaths);
                            score->setMKills(mKills);
                            score->setTeam(team);
                            score->setTKills(tKills);
                            score->setUsername(name);
                            score->setPKills(pKills);
                            score->calculate();
                            s->addScore(score);
                        }
                        int time;
                        time = list.at(iterate).toInt();
                        s->addTime(time);
                        this->hide();
                        s->show();
                        sock->close();
                        cleanObjects();
                        this->releaseKeyboard();
                        this->releaseMouse();
                        break;

                        //just in case for some reason the server return a weird case
                        /*default:
                        qDebug() << "Error code AAUGH: Unidentified Case: " << entv;
                        break;*/
                    }
                }
            }
        }
    }
}

//clean object list
void GameScreen::cleanObjects()
{
    for(int i = objects.size()-1; i > 0; --i)
    {
        delete objects.at(i);
    }
    objects.clear();
    playerId = 0;
    targetId = 0;
    timer->stop();
}

//handle server disconnect
void GameScreen::serverDisconnected()
{
    sock->close();
    this->hide();
    this->releaseKeyboard();
    this->releaseMouse();
    cleanObjects();
    w->show();
}

//create a new EntityLabel with <type>, <id>, <team>,
//<health>, <state> at <posX>, <posY> with <username>
void GameScreen::createEntity(int type, int id, int team, int health, int state, int posX, int posY, QString name)
{
    EntityLabel *thing = new EntityLabel(id, type, team, posX, posY, health, state, name, wdgtPicture);
    thing->show();
    objects.push_back(thing);
}

//moves entity with <id> to <x>, <y>
void GameScreen::moveEntity(int id, int x, int y){
    EntityLabel *thing = GameScreen::getByID(id);
    thing->move(x, y);
    thing->nextFrame();
}

//changes entity with <id>'s heath to <healthPercent>
void GameScreen::changeEntityHealth(int id, int healthPercent)
{
    EntityLabel *thing = GameScreen::getByID(id);
    thing->setHealth(healthPercent);
}

//changes entity with <id>'s direction(state) to <state>
void GameScreen::changeEntityState(int id, int state){
    EntityLabel *thing = GameScreen::getByID(id);
    thing->setState(state);
}

//Sets entity with <id> to dead state
void GameScreen::exterminate(int id){
    EntityLabel *thing = GameScreen::getByID(id);
    thing->setCounter(1);
    thing->die();
    showLbl(id);
    if(id == targetId){
        lblTargetHealth->hide();
        lblTargetIcon->hide();
        targetId = 0;
    }

}

//shows entity with <id>
void GameScreen::showLbl(int id)
{
    EntityLabel *thing = GameScreen::getByID(id);
    thing->show();
}

//returns entity with <id>
EntityLabel* GameScreen::getByID(int id)
{
    for(uint i = 0; i < objects.size(); ++i)
    {
        if(id == objects.at(i)->getID())
        {
            return objects.at(i);
        }
    }
}

//returns id of entity with <name>
int GameScreen::getIdByName(QString& name)
{
    for(uint i = 0; i < objects.size(); ++i)
    {
        if(name == objects.at(i)->getName())
        {
            return objects.at(i)->getID();
        }
    }
    return 0;
}

//updates image of entity with <id>
void GameScreen::animate(int id){
    EntityLabel *thing = GameScreen::getByID(id);
    thing->updateStyleSheet();
}

//calculates the total score of score object.
void ScoreObject::calculate(){
    totalScore = (minionKills * 5) + (playerKills * 60) + (playerDeaths * -10) + (towerKills * 50);
}
