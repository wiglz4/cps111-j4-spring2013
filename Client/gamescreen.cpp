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

gameScreen::gameScreen(QWidget *parent) :
    QWidget(parent),
    gsui(new Ui::gameScreen)
{
    gsui->setupUi(this);

    playerHealthPercent = 100;
    targetHealthPercent = 100;

    wdgtGame = new QWidget(this);
    wdgtGame->setGeometry(-100, -2150, 4000, 3000);
    wdgtPicture = new QWidget(wdgtGame);
    wdgtPicture->setGeometry(0,0,4000,3000);
    wdgtPicture->setStyleSheet("background-image:url(:/images/map4.png)");

    hud = new QLabel(this);
    hud->setGeometry(0, -10, 800, 600);
    hud->setStyleSheet("background:url(:/images/hud.png) no-repeat bottom left; background-color: rgba(0,0,0,0);");
    hud->show();

    gameFrame = new QFrame(this);
    gameFrame->setFrameShape(QFrame::Box);
    gameFrame->setLineWidth(10);
    gameFrame->setGeometry(0, 0, 800, 600);
    gameFrame->show();

    pause = new QFrame(gameFrame);
    pause->setGeometry(0, 0, 4000, 3000);
    pause->setStyleSheet("background-color:rgba(0, 0, 0, 100);");
    pause->hide();
    pPressed = false;

    map = new QLabel(pause);
    map->setGeometry(100, 100, 410, 310);
    map->setStyleSheet("background: url(:/images/background3.png) no-repeat top left");
    map->hide();

    upPressed = false;
    rightPressed = false;
    downPressed = false;
    leftPressed = false;

    menu = new QPushButton(gameFrame);
    menu->setGeometry(588,310,121,31);
    menu->setFlat(true);
    menu->setStyleSheet("QPushButton { background:url(:/images/buttonmm) no-repeat right top; } QPushButton:hover{ background:url(:/images/buttonmm2.png) no-repeat right top; } QPushButton:pressed { background:url(:/images/buttonmm.png) no-repeat right top; border: 0px solid grey; }");
    menu->setFocusPolicy(Qt::NoFocus);
    menu->hide();
    connect(this->menu, SIGNAL(clicked()), this, SLOT(return_to_menu()));

    btnPause = new QPushButton(gameFrame);
    btnPause->setGeometry(600,285,121,31);
    btnPause->setFlat(true);
    btnPause->setStyleSheet("QPushButton { background:url(:/images/buttonpa) no-repeat right top; } QPushButton:hover{ background:url(:/images/buttonpa2.png) no-repeat right top; } QPushButton:pressed { background:url(:/images/buttonpa.png) no-repeat right top; border: 0px solid grey; }");
    btnPause->setFocusPolicy(Qt::NoFocus);
    btnPause->hide();
    connect(this->btnPause, SIGNAL(clicked()), this, SLOT(unPause()));

    bar = new QLabel(gameFrame);
    bar->setGeometry(700,265,21,100);
    bar->setStyleSheet("background:url(:/images/bar.png) no-repeat top left;");
    bar->hide();

    playerIcon = new QLabel(this);
    playerIcon->setGeometry(24, 461, 110, 110);
    playerIcon->setStyleSheet("background:url(:/images/hero.png) no-repeat top right; background-color: rgba(0,0,0,0);");
    playerIcon->show();

    playerHealth = new QLabel(this);
    playerHealth->setGeometry(29, 556, playerHealthPercent, 10);
    playerHealth->setStyleSheet("background-color:#00ff00;");
    playerHealth->show();

    targetIcon = new QLabel(this);
    targetIcon->setGeometry(629, 461, 110, 110);
    targetIcon->setStyleSheet("background-color:#000000;");
    //targetIcon->show();

    targetHealth = new QLabel(this);
    targetHealth->setGeometry(634, 466, 100, 10);
    targetHealth->setStyleSheet("background-color:#00ff00;");
    //targetHealth->show();

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

    //REM
    timer = new QTimer(this);
    timer->setInterval(20);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimerHit()));
    timer->start();
    //REM
}

gameScreen::~gameScreen()
{
    delete gsui;
}

void gameScreen::updatePlayer(QStringList player)
{
    bool ok;
    if(player.at(0).toInt(&ok, 10) == 41) {
        //hero = new EntityLabel(wdgtGame);
        hero->setGeometry(player.at(5).toInt(&ok,10),player.at(6).toInt(&ok,10),110,110);
        hero->setStyleSheet("background:url(:/images/2/4/3/1.png) no-repeat top left;background-color:rgba(0, 0, 0, 0);");
        hero->show();
    }
}

void gameScreen::updatePos(EntityLabel *lblToUpdate, int x, int y, int width, int height)
{
    lblToUpdate->setGeometry(x,y,width,height);
}

void gameScreen::unPause()
{
    timer->start();
    pPressed = false;
    btnPause->hide();
    menu->hide();
    pause->hide();
    bar->hide();
    map->hide();
}

void gameScreen::keyPressEvent(QKeyEvent *e)
{
    //qDebug() << "button";
    if((e->key() == Qt::Key_P && !e->isAutoRepeat() || (e->key() == Qt::Key_Escape && !e->isAutoRepeat())))
    {

        if (pPressed == false) {
            timer->stop();
            pPressed = true;
            pause->show();
            btnPause->show();
            menu->show();
            bar->show();
            map->show();
        } else {
            timer->start();
            pPressed = false;
            btnPause->hide();
            menu->hide();
            pause->hide();
            bar->hide();
            map->hide();
        }
        qDebug() << "P";

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
}

void gameScreen::keyReleaseEvent(QKeyEvent *e)
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

}

void gameScreen::onTimerHit()
{
    if(playerId == 0){
        playerId = getIdByName(playername);
        if(playerId != 0){
            qDebug() << "playerId = " << playerId;
        }
    } else {
        EntityLabel *e = getByID(playerId);
        playerHealthPercent = e->getHealth();
    }

    if(targetId > 0){
        qDebug() << "targetID=" << targetId;
        EntityLabel *e = getByID(targetId);
        targetHealthPercent = e->getHealth();

        updateTargetLabel(e->getType(), e->getTeam());

        targetIcon->show();
        targetHealth->show();
    } else {
        targetIcon->hide();
        targetHealth->hide();
    }

    if(upPressed && !rightPressed && !downPressed && !leftPressed)
    {
        //1
        wdgtPicture->move(wdgtPicture->x(), wdgtPicture->y() + 6);
    }
    if(upPressed && rightPressed && !downPressed && !leftPressed)
    {
        //2
        wdgtPicture->move(wdgtPicture->x() - 4, wdgtPicture->y() + 4);
    }
    if(!upPressed && rightPressed && !downPressed && !leftPressed)
    {
        //3
        wdgtPicture->move(wdgtPicture->x() -6 , wdgtPicture->y());
    }
    if(!upPressed && rightPressed && downPressed && !leftPressed)
    {
        //4
        wdgtPicture->move(wdgtPicture->x()-4, wdgtPicture->y() - 4);
    }
    if(!upPressed && !rightPressed && downPressed && !leftPressed)
    {
        //5
        wdgtPicture->move(wdgtPicture->x(), wdgtPicture->y() - 6);
    }
    if(!upPressed && !rightPressed && downPressed && leftPressed)
    {
        //6
        wdgtPicture->move(wdgtPicture->x() + 4, wdgtPicture->y() - 4);
    }
    if(!upPressed && !rightPressed && !downPressed && leftPressed)
    {
        //7
        wdgtPicture->move(wdgtPicture->x() + 6, wdgtPicture->y());
    }
    if(upPressed && !rightPressed && !downPressed && leftPressed)
    {
        //8
        wdgtPicture->move(wdgtPicture->x() + 4, wdgtPicture->y() + 4);
    }
    playerHealth->setGeometry(29, this->height() - 44, playerHealthPercent, 10);
    if(targetId != 0){
        targetHealth->setGeometry(634, this->height() - 134, targetHealthPercent, 10);
    }

}


void gameScreen::closeEvent(QCloseEvent *)
{
    timer->stop();
}

void gameScreen::resizeEvent(QResizeEvent *event)
{
    gameFrame->resize(event->size());
    wdgtGame->setGeometry(-100, this->height() - 2750, 4000, 3000);
    hud->setGeometry(0, 0, 800, this->height() - 10);

    playerIcon->setGeometry(24, this->height() - 139, 110, 110);
    playerHealth->setGeometry(29, this->height() - 44, playerHealthPercent, 10);


    targetIcon->setGeometry(629, this->height() - 139, 110, 110);
    targetHealth->setGeometry(634, this->height() - 134, targetHealthPercent, 10);

}


void gameScreen::mousePressEvent(QMouseEvent *e)
{
    //qDebug() <<"mouse clicked";
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

void gameScreen::updateTargetLabel(int targetType, int team)
{
    if(team == 1){
        switch(targetType){
        case 1:
            targetIcon->setStyleSheet("background:url(:/images/1/1/0/1.png) no-repeat top right");
            break;
        case 2:
            targetIcon->setStyleSheet("background:url(:/images/1/2/5/1.png) no-repeat top right");
            break;
        case 3:
            targetIcon->setStyleSheet("background:url(:/images/1/3/5/8.png) no-repeat top right");
            break;
        case 4:
            targetIcon->setStyleSheet("background:url(:/images/1/4/5/8.png) no-repeat top right");
            break;
        }
    } else if (team == 2) {
        switch(targetType){
        case 1:
            targetIcon->setStyleSheet("background:url(:/images/2/1/0/1.png) no-repeat top right");
            break;
        case 2:
            targetIcon->setStyleSheet("background:url(:/images/2/2/5/1.png) no-repeat top right");
            break;
        case 3:
            targetIcon->setStyleSheet("background:url(:/images/1/3/5/8.png) no-repeat top right");
            break;
        case 4:
            targetIcon->setStyleSheet("background:url(:/images/hero.png) no-repeat top right");
            break;
        }
    }
}

void gameScreen::return_to_menu(){
    this->hide();
    wdgtGame->releaseKeyboard();
    this->releaseMouse();
    w->show();
}


void gameScreen::readCommand()
{
    while(sock->canReadLine())
    {
        QString str = sock->readLine();
        qDebug() << str;
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
                    //create
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
                        qDebug() << "created " << id;
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
                        qDebug() << "DIED";
                        exterminate(id);
                        break;

                        //endgame
                    case 50:
                        qDebug() << "case 50";
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
                        qDebug() << "Error code AAUGH: Unidentified Case: " << entv;
                        break;*/
                    }
                }
            }
        }
    }
}

void gameScreen::lblClicked()
{
    qDebug()<<"ENTITY CLICKED";
    EntityLabel *lbl = dynamic_cast<EntityLabel*>(sender());
    if(lbl != NULL)
    {
        QString message = "1 ";
        message += lbl->getID();
        message += " ";
        sock->write(message.toAscii());
    }
}

void gameScreen::serverDisconnected()
{
    w->close();
}




void gameScreen::createEntity(int type, int id, int team, int health, int state, int posX, int posY, QString name){
    EntityLabel *thing = new EntityLabel(id, type, team, posX, posY, health, state, name, wdgtPicture);

    //if on screen
    //connect(thing, SIGNAL(clicked(int)),this, SLOT(entityClicked(int)));
    thing->show();
    objects.push_back(thing);
}

void gameScreen::entityClicked(int id){
    qDebug() << "cliked entity with id " << id;
}

void gameScreen::moveEntity(int id, int x, int y){
    EntityLabel *thing = gameScreen::getByID(id);
    thing->move(x, y);
    thing->nextFrame();
}

void gameScreen::changeEntityHealth(int id, int healthPercent){
    //qDebug() << healthPercent;
    EntityLabel *thing = gameScreen::getByID(id);
    thing->setHealth(healthPercent);
    //qDebug() << thing->getHealth();
}

void gameScreen::changeEntityState(int id, int state){
   EntityLabel *thing = gameScreen::getByID(id);
    thing->setState(state);
}

void gameScreen::exterminate(int id){
    EntityLabel *thing = gameScreen::getByID(id);
    qDebug() << "DEAD THING";
    thing->die();
    if(id == targetId){
        targetHealth->hide();
        targetIcon->hide();
        targetId = 0;
    }
}

void gameScreen::showLbl(int id)
{
    EntityLabel *thing = gameScreen::getByID(id);
    thing->show();
}

EntityLabel* gameScreen::getByID(int id)
{
    for(uint i = 0; i < objects.size(); ++i)
    {
        if(id == objects.at(i)->getID())
        {
            return objects.at(i);
        }
    }
}

int gameScreen::getIdByName(QString& name)
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

void gameScreen::animate(int id){
    EntityLabel *thing = gameScreen::getByID(id);
    thing->updateStyleSheet();
}

void ScoreObject::calculate(){
    totalScore = (minionKills * 5) + (playerKills * 60) + (playerDeaths * -10) + (towerKills * 50);
}
