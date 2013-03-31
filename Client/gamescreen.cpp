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

GameScreen::GameScreen(QWidget *parent) :
    QWidget(parent),
    gsui(new Ui::GameScreen)
{
    gsui->setupUi(this);

    playerHealthPercent = 100;
    targetHealthPercent = 100;

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

    upPressed = false;
    rightPressed = false;
    downPressed = false;
    leftPressed = false;

    spacePressed = false;

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

    playerId = 0;
    targetId = 0;

    targetChanged = false;

    timer = new QTimer(this);
    timer->setInterval(20);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimerHit()));
    timer->start();
}

GameScreen::~GameScreen()
{
    delete gsui;
}

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

void GameScreen::keyPressEvent(QKeyEvent *e)
{
    //qDebug() << "button";
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
        //qDebug() << "P";

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
                //qDebug()<<wdgtPicture->x()<<" "<<wdgtPicture->y();
            }
        }
        if(upPressed && rightPressed && !downPressed && !leftPressed)
        {
            //2
            if(wdgtPicture->x() - 8 > -3098 && wdgtPicture->y() + 8 < 2152 && !(wdgtPicture->x() - 8 < -3098))
            {
                wdgtPicture->move(wdgtPicture->x() - 8, wdgtPicture->y() + 8);
                //qDebug()<<wdgtPicture->x()<<" "<<wdgtPicture->y();
            }
        }
        if(!upPressed && rightPressed && !downPressed && !leftPressed)
        {
            //3
            if(wdgtPicture->x() - 10 > -3098 && !(wdgtPicture->x() - 10 < -3098));
            {
                wdgtPicture->move(wdgtPicture->x() - 10 , wdgtPicture->y());
                // qDebug()<<wdgtPicture->x()<<" "<<wdgtPicture->y();
            }
        }
        if(!upPressed && rightPressed && downPressed && !leftPressed)
        {
            //4
            if(wdgtPicture->x() - 8 > -3098 && wdgtPicture->y() - 8 > -260 && !(wdgtPicture->x() - 8 < -3098))
            {
                wdgtPicture->move(wdgtPicture->x()-8, wdgtPicture->y() - 8);
                // qDebug()<<wdgtPicture->x()<<" "<<wdgtPicture->y();
            }
        }
        if(!upPressed && !rightPressed && downPressed && !leftPressed)
        {
            //5
            if(wdgtPicture->y() - 10 > -260)
            {
                wdgtPicture->move(wdgtPicture->x(), wdgtPicture->y() - 10);
                // qDebug()<<wdgtPicture->x()<<" "<<wdgtPicture->y();
            }
        }
        if(!upPressed && !rightPressed && downPressed && leftPressed)
        {
            //6
            if(wdgtPicture->x() + 8 < 110 && wdgtPicture->y() - 8 > -260)
            {
                wdgtPicture->move(wdgtPicture->x() + 8, wdgtPicture->y() - 8);
                // qDebug()<<wdgtPicture->x()<<" "<<wdgtPicture->y();
            }
        }
        if(!upPressed && !rightPressed && !downPressed && leftPressed)
        {
            //7
            if(wdgtPicture->x() + 10 < 110)
            {
                wdgtPicture->move(wdgtPicture->x() + 10, wdgtPicture->y());
                //qDebug()<<wdgtPicture->x()<<" "<<wdgtPicture->y();
            }
        }
        if(upPressed && !rightPressed && !downPressed && leftPressed)
        {
            //8
            if(wdgtPicture->x() + 8 < 110 && wdgtPicture->y() + 8 < 2152)
            {
                wdgtPicture->move(wdgtPicture->x() + 8, wdgtPicture->y() + 8);
                // qDebug()<<wdgtPicture->x()<<" "<<wdgtPicture->y();
            }
        }
    }
    lblPlayerHealth->setGeometry(39, this->height() - 44, playerHealthPercent, 10);
    if(targetId != 0){
        lblTargetHealth->setGeometry(644, this->height() - 134, targetHealthPercent, 10);
    }

}


void GameScreen::closeEvent(QCloseEvent *)
{
    timer->stop();
}

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


void GameScreen::mousePressEvent(QMouseEvent *e)
{
    ////qDebug() <<"mouse clicked";
    if(e->button() == Qt::LeftButton){
        //qDebug() << "was left mouse button";
        QWidget *l = wdgtPicture->childAt(e->x() + abs(wdgtGame->x()) - wdgtPicture->x(), e->y() + abs(wdgtGame->y()) - wdgtPicture->y());
        //qDebug() << l;
        EntityLabel *thing = dynamic_cast<EntityLabel*>(l);
        if(thing){
            //qDebug() << "clicked object with id " << thing->getID();
            QString msg = "1 " + QString::number(thing->getID()) +"\n";
            sock->write(msg.toAscii());
            targetId = thing->getID();
            if (targetId == playerId){
                targetId = 0;
            }
        }
    }
}

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

void GameScreen::returnToMenu(){
    this->hide();
    wdgtGame->releaseKeyboard();
    this->releaseMouse();
    w->show();
}


void GameScreen::readCommand()
{
    while(sock->canReadLine())
    {
        QString str = sock->readLine();
        //qDebug() << str;
        str.remove("\n");
        if(str != "")
        {
            QStringList List = str.split(" ", QString::SkipEmptyParts);
            int iterate = 0;
            int verifier = List.at(iterate).toInt();
            ++iterate;
            if (verifier == 97179)
            {
                int entv, pHealth, x, y, id, state, team, type;
                QString playername;
                for(; iterate < List.size();)
                {
                    entv = 0;
                    pHealth = 0;
                    x = 0;
                    y = 0;
                    id = 0;
                    state = 0;
                    team = 0;
                    playername = "";
                    entv = List.at(iterate).toInt();
                    ++iterate;
                    type = entv/10;
                    switch (entv)
                    {

                    //create and load
                    case 11: //core
                    case 21: //tower
                    case 31: //minion
                    case 41: //player
                        id = List.at(iterate).toInt();
                        ++iterate;
                        team = List.at(iterate).toInt();
                        ++iterate;
                        pHealth = List.at(iterate).toInt();
                        ++iterate;
                        state = List.at(iterate).toInt();
                        ++iterate;
                        x = List.at(iterate).toInt();
                        ++iterate;
                        y = List.at(iterate).toInt();
                        ++iterate;
                        playername = List.at(iterate);
                        ++iterate;
                        createEntity(type, id, team, pHealth, state, x, y, playername);
                        showLbl(id);
                        //qDebug() << "created " << id;
                        break;

                        //position change
                    case 32: //minion
                    case 42: //player
                        id = List.at(iterate).toInt();
                        ++iterate;
                        x = List.at(iterate).toInt();
                        ++iterate;
                        y = List.at(iterate).toInt();
                        ++iterate;
                        moveEntity(id, x, y);
                        animate(id);
                        showLbl(id);
                        break;

                        //state change
                    case 23: //tower
                    case 33: //minion
                    case 43: //player
                        id = List.at(iterate).toInt();
                        ++iterate;
                        state = List.at(iterate).toInt();
                        ++iterate;
                        changeEntityState(id, state);
                        animate(id);
                        showLbl(id);
                        break;

                        //state and position change
                    case 34: //minion
                    case 44: //player

                        id = List.at(iterate).toInt();
                        ++iterate;
                        state = List.at(iterate).toInt();
                        ++iterate;
                        x = List.at(iterate).toInt();
                        ++iterate;
                        y = List.at(iterate).toInt();
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
                        id = List.at(iterate).toInt();
                        ++iterate;
                        pHealth = List.at(iterate).toInt();
                        ++iterate;
                        changeEntityHealth(id, pHealth);
                        showLbl(id);
                        break;

                        //health and position change
                    case 36: //minion
                    case 46: //player
                        id = List.at(iterate).toInt();
                        ++iterate;
                        pHealth = List.at(iterate).toInt();
                        ++iterate;
                        x = List.at(iterate).toInt();
                        ++iterate;
                        y = List.at(iterate).toInt();
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
                        id = List.at(iterate).toInt();
                        ++iterate;
                        pHealth = List.at(iterate).toInt();
                        ++iterate;
                        state = List.at(iterate).toInt();
                        ++iterate;
                        changeEntityHealth(id, pHealth);
                        changeEntityState(id, state);
                        animate(id);
                        showLbl(id);
                        break;

                        //heath state and position change
                    case 38: //minion
                    case 48: //player
                        id = List.at(iterate).toInt();
                        ++iterate;
                        pHealth = List.at(iterate).toInt();
                        ++iterate;
                        state = List.at(iterate).toInt();
                        ++iterate;
                        x = List.at(iterate).toInt();
                        ++iterate;
                        y = List.at(iterate).toInt();
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
                        id = List.at(iterate).toInt();
                        ++iterate;
                        changeEntityState(id, 9);
                        animate(id);
                        showLbl(id);
                        exterminate(id);
                        break;

                        //endgame
                    case 50:
                        //qDebug() << "case 50";
                        ScoreWindow *s = new ScoreWindow(w);
                        s->connectWidget(w);
                        int deaths;
                        int mKills;
                        int tKills;
                        int team;
                        int pKills;
                        QString name;
                        while(List.at(iterate).toStdString() == "P"){
                            ++iterate;
                            ScoreObject *score = new ScoreObject;
                            name = List.at(iterate);
                            ++iterate;
                            team = List.at(iterate).toInt();
                            ++iterate;
                            tKills = List.at(iterate).toInt();
                            ++iterate;
                            mKills = List.at(iterate).toInt();
                            ++iterate;
                            pKills = List.at(iterate).toInt();
                            ++iterate;
                            deaths = List.at(iterate).toInt();
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
                        time = List.at(iterate).toInt();
                        s->addTime(time);
                        this->hide();
                        s->show();
                        break;

                        /*default:
                        //qDebug() << "Error code AAUGH: Unidentified Case: " << entv;
                        break;*/
                    }
                }
            }
        }
    }
}

void GameScreen::serverDisconnected()
{
    w->close();
}




void GameScreen::createEntity(int type, int id, int team, int health, int state, int posX, int posY, QString name){
    EntityLabel *thing = new EntityLabel(id, type, team, posX, posY, health, state, name, wdgtPicture);
    if(name == playername)
    {
        hero = thing;
    }
    //if on screen
    //connect(thing, SIGNAL(clicked(int)),this, SLOT(entityClicked(int)));
    thing->show();
    objects.push_back(thing);
}

void GameScreen::moveEntity(int id, int x, int y){
    EntityLabel *thing = GameScreen::getByID(id);
    thing->move(x, y);
    thing->nextFrame();
}

void GameScreen::changeEntityHealth(int id, int healthPercent)
{
    EntityLabel *thing = GameScreen::getByID(id);
    thing->setHealth(healthPercent);
}

void GameScreen::changeEntityState(int id, int state){
    EntityLabel *thing = GameScreen::getByID(id);
    thing->setState(state);
}

void GameScreen::exterminate(int id){
    EntityLabel *thing = GameScreen::getByID(id);
    qDebug() << "DEAD THING";
    qDebug() << id;
    //thing->setCounter(1);
    if (thing->getType() != 1 && thing->getType() != 2){
        thing->die();
        int g = thing->getCounter() - 1;
        if (thing->getCounter() == g){
            thing->hide();
        }
    }
    else {
        thing->die();
        showLbl(id);
    }
    if(id == targetId){
        lblTargetHealth->hide();
        lblTargetIcon->hide();
        targetId = 0;
    }

}

void GameScreen::showLbl(int id)
{
    EntityLabel *thing = GameScreen::getByID(id);
    thing->show();
}

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

void GameScreen::animate(int id){
    EntityLabel *thing = GameScreen::getByID(id);
    thing->updateStyleSheet();
}

void ScoreObject::calculate(){
    totalScore = (minionKills * 5) + (playerKills * 60) + (playerDeaths * -10) + (towerKills * 50);
}
