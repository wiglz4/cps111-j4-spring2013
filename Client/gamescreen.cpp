#include "gamescreen.h"
#include "ui_gamescreen.h"
#include "entitylabel.h"
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

gameScreen::gameScreen(QWidget *parent) :
    QWidget(parent),
    gsui(new Ui::gameScreen)
{
    gsui->setupUi(this);
    //REM
    timer = new QTimer(this);
    timer->setInterval(20);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimerHit()));
    timer->start();
    //REM
    wdgtGame = new QWidget(this);
    wdgtGame->setGeometry(-100, -2150, 4000, 3000);
    wdgtPicture = new QWidget(wdgtGame);
    wdgtPicture->setGeometry(0,0,4000,3000);
    wdgtPicture->setStyleSheet("background-image:url(:/images/map4.png)");

    //wdgtGame->grabKeyboard();

    gameFrame = new QFrame(this);
    gameFrame->setFrameShape(QFrame::Box);
    gameFrame->setLineWidth(10);
    gameFrame->setGeometry(0, 0, 800, 600);
    gameFrame->show();

    pause = new QFrame(gameFrame);
    pause->setGeometry(0, 0, 4000, 3000);
    pause->setStyleSheet("background-color:rgba(0, 0, 0, 100);");
    pause->hide();
    /*
    wPressed = false;
    aPressed = false;
    sPressed = false;
    dPressed = false;*/
    pPressed = false;

    upPressed = false;
    rightPressed = false;
    downPressed = false;
    leftPressed = false;

    //counter = 1;



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

    this->grabKeyboard();

}

gameScreen::~gameScreen()
{
    delete gsui;
}

void gameScreen::updatePlayer(QStringList player)
{
    bool ok;
    if(player.at(0).toInt(&ok, 10) == 41) {
        //    hero = new EntityLabel(wdgtGame);
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
}

void gameScreen::keyPressEvent(QKeyEvent *e)
{
    qDebug()<<"Key pressed";
    if(e->key() == Qt::Key_P && !e->isAutoRepeat())
    {

        if (pPressed == false) {
            timer->stop();
            pPressed = true;
            pause->show();
            btnPause->show();
            menu->show();
            bar->show();
        } else {
            timer->start();
            pPressed = false;
            btnPause->hide();
            menu->hide();
            pause->hide();
            bar->hide();
        }
        qDebug() << "P";

    }
    if(e->key() == Qt::Key_W && !e->isAutoRepeat())
    {
        //REM
        //wPressed = true;
        sock->write("2 1");
        qDebug() << "W";
        //REM
    }
    if(e->key() == Qt::Key_A && !e->isAutoRepeat())
    {
        //REM
        //aPressed = true;
        sock->write("2 4");
        qDebug() << "A";
        //REM
    }
    if(e->key() == Qt::Key_S && !e->isAutoRepeat())
    {
        //REM
        //sPressed = true;
        sock->write("2 3");
        qDebug() << "S";
        //REM
    }
    if(e->key() == Qt::Key_D && !e->isAutoRepeat())
    {
        //REM
        //dPressed = true;
        sock->write("2 2");
        qDebug() << "D";
        //REM
    }
    if(e->key() == Qt::Key_Up)
    {
        //gsui->wdgtPicture->scroll(0, -10);
        //wdgtPicture->move(wdgtPicture->x(), wdgtPicture->y()+20);
        upPressed = true;
        qDebug()<<"UP";
        //gsui->wdgtPicture->repaint();
    }
    if(e->key() == Qt::Key_Left)
    {
        //wdgtPicture->move(wdgtPicture->x()+20, wdgtPicture->y());
        //gsui->wdgtPicture->scroll(10, 0);
        leftPressed = true;
        qDebug()<<"LEFT";
        //gsui->wdgtPicture->repaint();
    }
    if(e->key() == Qt::Key_Down)
    {
        //wdgtPicture->move(wdgtPicture->x(), wdgtPicture->y()-20);
        //gsui->wdgtPicture->scroll(0, 10);
        downPressed = true;
        qDebug()<<"DOWN";
        //gsui->wdgtPicture->repaint();
    }
    if(e->key() == Qt::Key_Right)
    {
        //wdgtPicture->move(wdgtPicture->x()-20, wdgtPicture->y());
        //gsui->wdgtPicture->scroll(-10, 0);
        rightPressed = true;
        qDebug()<<"RIGHT";
        //gsui->wdgtPicture->repaint();
    }
}

void gameScreen::keyReleaseEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_W && !e->isAutoRepeat())
    {
        //REM
        //wPressed = false;
        sock->write("3 1");
        qDebug() << "~W";
        //REM
    }
    if(e->key() == Qt::Key_A && !e->isAutoRepeat())
    {
        //REM
        //aPressed = false;
        sock->write("3 4");
        qDebug() << "~A";
        //REM
    }
    if(e->key() == Qt::Key_S && !e->isAutoRepeat())
    {
        //REM
        //sPressed = false;
        sock->write("3 3");
        qDebug() << "~S";
        //REM
    }
    if(e->key() == Qt::Key_D && !e->isAutoRepeat())
    {
        //REM
        //dPressed = false;
        sock->write("3 2");
        qDebug() << "~D";
        //REM
    }
    if(e->key() == Qt::Key_Up)
    {
        //gsui->wdgtPicture->scroll(0, -10);
        //wdgtPicture->move(wdgtPicture->x(), wdgtPicture->y()+20);
        upPressed = false;
        qDebug()<<"~UP";
        //gsui->wdgtPicture->repaint();
    }
    if(e->key() == Qt::Key_Left)
    {
        //wdgtPicture->move(wdgtPicture->x()+20, wdgtPicture->y());
        //gsui->wdgtPicture->scroll(10, 0);
        leftPressed = false;
        qDebug()<<"~LEFT";
        //gsui->wdgtPicture->repaint();
    }
    if(e->key() == Qt::Key_Down)
    {
        //wdgtPicture->move(wdgtPicture->x(), wdgtPicture->y()-20);
        //gsui->wdgtPicture->scroll(0, 10);
        downPressed = false;
        qDebug()<<"~DOWN";
        //gsui->wdgtPicture->repaint();
    }
    if(e->key() == Qt::Key_Right)
    {
        //wdgtPicture->move(wdgtPicture->x()-20, wdgtPicture->y());
        //gsui->wdgtPicture->scroll(-10, 0);
        rightPressed = false;
        qDebug()<<"~RIGHT";
        //gsui->wdgtPicture->repaint();
    }

}

//REM
void gameScreen::onTimerHit()
{
    //rem, once you're sure new stuff works
    /*    //qDebug() << "Tick";
    if(wPressed && !aPressed && !sPressed && !dPressed)
    {
        hero->move(hero->x(), hero->y()-4);
        counter++;
        if (counter > 19) {
            counter = 1;
        }
        hero->setStyleSheet("background:url(:/images/2/4/1/" + QString("%1").arg(counter) + ".png) no-repeat top left;background-color:rgba(0, 0, 0, 0);");
    }

    if(wPressed && !aPressed && !sPressed && dPressed)
    {
        hero->move(hero->x()+3, hero->y()-3);
        counter++;
        if (counter > 19) {
            counter = 1;
        }
        hero->setStyleSheet("background:url(:/images/2/4/2/" + QString("%1").arg(counter) + ".png) no-repeat top left;background-color:rgba(0, 0, 0, 0);");
    }

    if(!wPressed && !aPressed && !sPressed && dPressed)
    {
        hero->move(hero->x()+4, hero->y());
        counter++;
        if (counter > 19) {
            counter = 1;
        }
        hero->setStyleSheet("background:url(:/images/2/4/3/" + QString("%1").arg(counter) + ".png) no-repeat top left;background-color:rgba(0, 0, 0, 0);");
    }

    if(!wPressed && !aPressed && sPressed && dPressed)
    {
        hero->move(hero->x()+3, hero->y()+3);
        counter++;
        if (counter > 19) {
            counter = 1;
        }
        hero->setStyleSheet("background:url(:/images/2/4/4/" + QString("%1").arg(counter) + ".png) no-repeat top left;background-color:rgba(0, 0, 0, 0);");
    }

    if(!wPressed && !aPressed && sPressed && !dPressed)
    {
        hero->move(hero->x(), hero->y()+4);
        counter++;
        if (counter > 19) {
            counter = 1;
        }
        hero->setStyleSheet("background:url(:/images/2/4/5/" + QString("%1").arg(counter) + ".png) no-repeat top left;background-color:rgba(0, 0, 0, 0);");
    }

    if(!wPressed && aPressed && sPressed && !dPressed)
    {
        hero->move(hero->x()-3, hero->y()+3);
        counter++;
        if (counter > 19) {
            counter = 1;
        }
        hero->setStyleSheet("background:url(:/images/2/4/6/" + QString("%1").arg(counter) + ".png) no-repeat top left;background-color:rgba(0, 0, 0, 0);");
    }

    if(!wPressed && aPressed && !sPressed && !dPressed)
    {
        hero->move(hero->x()-4, hero->y());
        counter++;
        if (counter > 19) {
            counter = 1;
        }
        hero->setStyleSheet("background:url(:/images/2/4/7/" + QString("%1").arg(counter) + ".png) no-repeat top left;background-color:rgba(0, 0, 0, 0);");
    }

    if(wPressed && aPressed && !sPressed && !dPressed)
    {
        hero->move(hero->x()-3, hero->y()-3);
        counter++;
        if (counter > 19) {
            counter = 1;
        }
        hero->setStyleSheet("background:url(:/images/2/4/8/" + QString("%1").arg(counter) + ".png) no-repeat top left;background-color:rgba(0, 0, 0, 0);");
    }
*/


    if(upPressed && !rightPressed && !downPressed && !leftPressed)
    {
        //1
        //wdgtPicture->move(wdgtPicture->x(), wdgtPicture->y() + 6);
        wdgtGame->scroll(0,6);
    }
    if(upPressed && rightPressed && !downPressed && !leftPressed)
    {
        //2
        //wdgtPicture->move(wdgtPicture->x() - 4, wdgtPicture->y() + 4);
        wdgtGame->scroll(-4,+4);
    }
    if(!upPressed && rightPressed && !downPressed && !leftPressed)
    {
        //3
        //wdgtPicture->move(wdgtPicture->x() -6 , wdgtPicture->y());
        wdgtGame->scroll(-6,0);
    }
    if(!upPressed && rightPressed && downPressed && !leftPressed)
    {
        //4
        //wdgtPicture->move(wdgtPicture->x()-4, wdgtPicture->y() - 4);
        wdgtGame->scroll(-4,-4);
    }
    if(!upPressed && !rightPressed && downPressed && !leftPressed)
    {
        //5
        //wdgtPicture->move(wdgtPicture->x(), wdgtPicture->y() - 6);
        wdgtGame->scroll(0,-6);
    }
    if(!upPressed && !rightPressed && downPressed && leftPressed)
    {
        //6
        //wdgtPicture->move(wdgtPicture->x() + 4, wdgtPicture->y() - 4);
        wdgtGame->scroll(4,-4);
    }
    if(!upPressed && !rightPressed && !downPressed && leftPressed)
    {
        //7
        //wdgtPicture->move(wdgtPicture->x() + 6, wdgtPicture->y());
        wdgtGame->scroll(6,0);
    }
    if(upPressed && !rightPressed && !downPressed && leftPressed)
    {
        //8
        //wdgtPicture->move(wdgtPicture->x() + 4, wdgtPicture->y() + 4);
        wdgtGame->scroll(4, 4);
    }

}


void gameScreen::closeEvent(QCloseEvent *)
{
    timer->stop();
    qDebug()<<"Timer stopped";
}

void gameScreen::resizeEvent(QResizeEvent *event)
{
    gameFrame->resize(event->size());
}

void gameScreen::return_to_menu(){
    this->hide();
    wdgtGame->releaseKeyboard();
    w->show();
}


void gameScreen::readCommand()
{
    /*
    while (sock->canReadLine()) {
        QString str = sock->readLine();
        qDebug() << str;
        QStringList tempList = str.split(" ", QString::SkipEmptyParts);
        bool ok;
        int command = tempList.at(0).toInt(&ok, 10);
        int type = command/10;
        if(ok){

        }
    }*/


    while(sock->canReadLine())
    {
        QString str = sock->readLine();
        /*
        std::stringstream strm(str.toStdString());
        int entv, pHealth, x, y, id, state, team, type;
        QString playername;
        std::string temp;
        int verifier;
        strm>>verifier;
        /*DEBUGqDebug()<<verifier;
        while(strm.str() != "" && strm.str() != " " && strm.str() != "  ")
        {
            entv = 0;
            pHealth = 0;
            x = 0;
            y = 0;
            id = 0;
            state = 0;
            team = 0;
            playername = "";
            strm>>entv;
            type = entv/10;
            switch (entv)
            {
            //create
            case 11: //core
            case 21: //tower
            case 31: //minion
            case 41: //player
                strm >> id >> team >> pHealth >> state >> x >> y;
                temp = strm.str();
                playername = temp.c_str();
                createEntity(type, id, team, pHealth, state, x, y, playername);
                break;

            //position change
            case 32: //minion
            case 42: //player
                strm >> id >> x >> y;
                moveEntity(id, x, y);
                break;

            //state change
            case 23: //tower
            case 33: //minion
            case 43: //player
                strm >> id >> state;
                changeEntityState(id, state);
                break;

            //state and position change
            case 34: //minion
            case 44: //player
                strm >> id >> state >> x >> y;
                changeEntityState(id, state);
                moveEntity(id, x, y);
                break;

            //health change
            case 15: //core
            case 25: //tower
            case 35: //minion
            case 45: //player
                strm >> id >> pHealth;
                changeEntityHealth(id, pHealth);
                break;

            //health and position change
            case 36: //minion
            case 46: //player
                strm >> id >> pHealth >> x >> y;
                changeEntityHealth(id, pHealth);
                moveEntity(id, x, y);
                break;

            //health and state change
            case 27: //tower
            case 37: //minion
            case 47: //player
                strm >> id >> pHealth >> state;
                changeEntityHealth(id, pHealth);
                changeEntityState(id, state);
                break;

            //heath state and position change
            case 38: //minion
            case 48: //player
                strm >> id >> pHealth >> state >> x >> y;
                changeEntityHealth(id, pHealth);
                changeEntityState(id, state);
                moveEntity(id, x, y);
                break;

            //death
            case 19: //core
            case 29: //tower
            case 39: //minion
            case 49: //player
                strm >> id;
                exterminate(id);
                break;

            default:
                //qDebug() << "Error code AAUGH: Unidentified Case: " << entv;
                break;

            }
        }*/
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
                //strm>>entv;
                type = entv/10;
                switch (entv)
                {
                //create
                case 11: //core
                case 21: //tower
                case 31: //minion
                case 41: //player
                    /*strm >> id >> team >> pHealth >> state >> x >> y;
                    temp = strm.str();
                    playername = temp.c_str();*/
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
                    break;

                    //position change
                case 32: //minion
                case 42: //player
                    //strm >> id >> x >> y;
                    id = List.at(iterate).toInt();
                    ++iterate;
                    x = List.at(iterate).toInt();
                    ++iterate;
                    y = List.at(iterate).toInt();
                    ++iterate;
                    moveEntity(id, x, y);
                    break;

                    //state change
                case 23: //tower
                case 33: //minion
                case 43: //player
                    //strm >> id >> state;
                    id = List.at(iterate).toInt();
                    ++iterate;
                    state = List.at(iterate).toInt();
                    ++iterate;
                    changeEntityState(id, state);
                    break;

                    //state and position change
                case 34: //minion
                case 44: //player
                    //strm >> id >> state >> x >> y;
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
                    break;

                    //health change
                case 15: //core
                case 25: //tower
                case 35: //minion
                case 45: //player
                    //strm >> id >> pHealth;
                    id = List.at(iterate).toInt();
                    ++iterate;
                    pHealth = List.at(iterate).toInt();
                    ++iterate;
                    changeEntityHealth(id, pHealth);
                    break;

                    //health and position change
                case 36: //minion
                case 46: //player
                    //strm >> id >> pHealth >> x >> y;
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
                    break;

                    //health and state change
                case 27: //tower
                case 37: //minion
                case 47: //player
                    //strm >> id >> pHealth >> state;
                    id = List.at(iterate).toInt();
                    ++iterate;
                    pHealth = List.at(iterate).toInt();
                    ++iterate;
                    state = List.at(iterate).toInt();
                    ++iterate;
                    changeEntityHealth(id, pHealth);
                    changeEntityState(id, state);
                    break;

                    //heath state and position change
                case 38: //minion
                case 48: //player
                    //strm >> id >> pHealth >> state >> x >> y;
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
                    break;

                    //death
                case 19: //core
                case 29: //tower
                case 39: //minion
                case 49: //player
                    //strm >> id;
                    id = List.at(iterate).toInt();
                    ++iterate;
                    exterminate(id);
                    break;

                default:
                    qDebug() << "Error code AAUGH: Unidentified Case: " << entv;
                    break;
                }

            }
        }
    }
}

void gameScreen::serverDisconnected()
{
    this->close();
}


void gameScreen::createEntity(int type, int id, int team, int health, int state, int posX, int posY, QString name){
    EntityLabel *thing = new EntityLabel(id, team, type, posX, posY, health, state, name, wdgtGame);

    //if on screen
    thing->show();
    objects.push_back(thing);
}


void gameScreen::moveEntity(int id, int x, int y){
    EntityLabel *thing = objects.at(id--);
    thing->move(x, y);
    thing->setCounter(1);
    //move to EntityLabel Class
    int counter = thing->getCounter();
    if (counter > 19) {
        counter = 1;
    }
    hero->setStyleSheet("background:url(:/images/2/4/8/" + QString("%1").arg(counter) + ".png) no-repeat top left;background-color:rgba(0, 0, 0, 0);");
    //end
}

void gameScreen::changeEntityHealth(int id, int healthPercent){
    EntityLabel *thing = objects.at(id--);
    thing->setHealth(healthPercent);
}

void gameScreen::changeEntityState(int id, int state){
    EntityLabel *thing = objects.at(id--);
    thing->setState(state);
}

void gameScreen::exterminate(int id){
    EntityLabel *thing = objects.at(id--);
    thing->die();
}
