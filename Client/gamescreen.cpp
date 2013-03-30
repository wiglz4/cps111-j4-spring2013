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

    targetChanged = false;
    upPressed = false;
    rightPressed = false;
    downPressed = false;
    leftPressed = false;
    spacePressed = false;

    wdgtGame = new QWidget(this);
    wdgtGame->setGeometry(-100, -2150, 4000, 3000);
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
    frGame->setStyleSheet("color:rgba(0,0,0,212);");
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
    timer->start();
}

//Destructor
GameScreen::~GameScreen()
{
    delete gsui;
}


//hides pause menu
void GameScreen::unPause()
{
    timer->start();
    pPressed = false;
    btnPause->hide();
    btnMenu->hide();
    frPause->hide();
    lblBar->hide();
    lblMap->hide();
}

//registers key press
void GameScreen::keyPressEvent(QKeyEvent *e)
{
    if((e->key() == Qt::Key_P && !e->isAutoRepeat() || (e->key() == Qt::Key_Escape && !e->isAutoRepeat())))
    {

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
    if(e->key() == Qt::Key_Up)
    {
        upPressed = true;
    }
    if(e->key() == Qt::Key_Left)
    {
        leftPressed = true;
    }
    if(e->key() == Qt::Key_Down)
    {
        downPressed = true;
    }
    if(e->key() == Qt::Key_Right)
    {
        rightPressed = true;
    }
    if(e->key() == Qt::Key_Space)
    {
        spacePressed = true;
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
    if(e->key() == Qt::Key_Up)
    {
        upPressed = false;
    }
    if(e->key() == Qt::Key_Left)
    {
        leftPressed = false;
    }
    if(e->key() == Qt::Key_Down)
    {
        downPressed = false;
    }
    if(e->key() == Qt::Key_Right)
    {
        rightPressed = false;
    }
    if(e->key() == Qt::Key_Space)
    {
        spacePressed = false;
    }

}

//processes updates parts of the gui and sends information to
//server every timer hit
void GameScreen::onTimerHit()
{
    if(playerId == 0)
    {
        playerId = getIdByName(playername);
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
    } else {
        EntityLabel *e = getByID(playerId);
        playerHealthPercent = e->getHealth();
    }

    if(targetId > 0){
        //qDebug() << "targetID=" << targetId;
        EntityLabel *e = getByID(targetId);
        targetHealthPercent = e->getHealth();

        updateTargetLabel(e->getType(), e->getTeam());

        lblTargetIcon->show();
        lblTargetHealth->show();
    } else {
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
        wdgtPicture->move(0-hx+ww/2, gh-hy-wh);
    }
    else
    {
        if(upPressed && !rightPressed && !downPressed && !leftPressed)
        {
            //1
            if(wdgtPicture->y() + 10 < 2152)
            {
                wdgtPicture->move(wdgtPicture->x(), wdgtPicture->y() + 10);
                qDebug()<<wdgtPicture->x()<<" "<<wdgtPicture->y();
            }
        }
        if(upPressed && rightPressed && !downPressed && !leftPressed)
        {
            //2
            if(wdgtPicture->x() - 8 > -3098 && wdgtPicture->y() + 8 < 2152 && !(wdgtPicture->x() - 8 < -3098))
            {
                wdgtPicture->move(wdgtPicture->x() - 8, wdgtPicture->y() + 8);
                qDebug()<<wdgtPicture->x()<<" "<<wdgtPicture->y();
            }
        }
        if(!upPressed && rightPressed && !downPressed && !leftPressed)
        {
            //3
            if(wdgtPicture->x() - 10 > -3098 && !(wdgtPicture->x() - 10 < -3098));
            {
                wdgtPicture->move(wdgtPicture->x() - 10 , wdgtPicture->y());
                qDebug()<<wdgtPicture->x()<<" "<<wdgtPicture->y();
            }
        }
        if(!upPressed && rightPressed && downPressed && !leftPressed)
        {
            //4
            if(wdgtPicture->x() - 8 > -3098 && wdgtPicture->y() - 8 > -260 && !(wdgtPicture->x() - 8 < -3098))
            {
                wdgtPicture->move(wdgtPicture->x()-8, wdgtPicture->y() - 8);
                qDebug()<<wdgtPicture->x()<<" "<<wdgtPicture->y();
            }
        }
        if(!upPressed && !rightPressed && downPressed && !leftPressed)
        {
            //5
            if(wdgtPicture->y() - 10 > -260)
            {
                wdgtPicture->move(wdgtPicture->x(), wdgtPicture->y() - 10);
                qDebug()<<wdgtPicture->x()<<" "<<wdgtPicture->y();
            }
        }
        if(!upPressed && !rightPressed && downPressed && leftPressed)
        {
            //6
            if(wdgtPicture->x() + 8 < 110 && wdgtPicture->y() - 8 > -260)
            {
                wdgtPicture->move(wdgtPicture->x() + 8, wdgtPicture->y() - 8);
                qDebug()<<wdgtPicture->x()<<" "<<wdgtPicture->y();
            }
        }
        if(!upPressed && !rightPressed && !downPressed && leftPressed)
        {
            //7
            if(wdgtPicture->x() + 10 < 110)
            {
                wdgtPicture->move(wdgtPicture->x() + 10, wdgtPicture->y());
                qDebug()<<wdgtPicture->x()<<" "<<wdgtPicture->y();
            }
        }
        if(upPressed && !rightPressed && !downPressed && leftPressed)
        {
            //8
            if(wdgtPicture->x() + 8 < 110 && wdgtPicture->y() + 8 < 2152)
            {
                wdgtPicture->move(wdgtPicture->x() + 8, wdgtPicture->y() + 8);
                qDebug()<<wdgtPicture->x()<<" "<<wdgtPicture->y();
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
    wdgtGame->releaseKeyboard();
    this->releaseMouse();
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
                int entv, pHealth, x, y, id, state, team, type;
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
                    switch (entv)
                    {

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
                        break;

                        //just in case for some reason the server return a weird case
                        default:
                            qDebug() << "Error code AAUGH: Unidentified Case: " << entv;
                        break;
                    }
                }
            }
        }
    }
}

//handle server disconnect
void GameScreen::serverDisconnected()
{
    w->close();
}

//create a new EntityLabel with <type>, <id>, <team>,
//<health>, <state> at <posX>, <posY> with <username>
void GameScreen::createEntity(int type, int id, int team, int health, int state, int posX, int posY, QString name){
    EntityLabel *thing = new EntityLabel(id, type, team, posX, posY, health, state, name, wdgtPicture);
    if(name == playername)
    {
        hero = thing;
    }
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
    qDebug() << "DEAD THING";
    qDebug() << id;
    thing->die();
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
