#include "gamescreen.h"
#include "ui_gamescreen.h"
#include "entitylabel.h"
#include <QPixmap>
#include <QString>
#include <QByteArray>
#include <QTcpServer>
#include <QTcpSocket>
#include <string>

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
    wdgtPicture->setStyleSheet("background-image:url(:/images/mapsm.png)");
    hero = new EntityLabel(wdgtGame);
    hero->setGeometry(300,2350,110,110);
    //wdgtPicture->move(wdgtPicture->x(), wdgtPicture->y() - 2800);
    //QPixmap icon(":/images/hero1.png");
    //hero->setPixmap(icon);
    hero->setStyleSheet("background:url(:/images/2/4/3/1.png) no-repeat top left;background-color:rgba(0, 0, 0, 0);");
    hero->show();

    wdgtGame->grabKeyboard();

    gameFrame = new QFrame(this);
    gameFrame->setFrameShape(QFrame::Box);
    gameFrame->setLineWidth(10);
    gameFrame->setGeometry(0, 0, 800, 600);
    gameFrame->show();

    lblPause = new QLabel(gameFrame);
    lblPause->setText("PAUSED");
    lblPause->setStyleSheet("font-size:22pt; font-weight:600; color:rgb(0, 0, 0);");
    lblPause->setGeometry(28, 100, 200, 200);
    lblPause->hide();

    pause = new QFrame(gameFrame);
    pause->setGeometry(0, 0, 4000, 3000);
    pause->setStyleSheet("background-color:rgba(0, 0, 0, 100);");
    pause->hide();

    wPressed = false;
    aPressed = false;
    sPressed = false;
    dPressed = false;
    pPressed = false;

    upPressed = false;
    rightPressed = false;
    downPressed = false;
    leftPressed = false;

    counter = 1;
    mySocket = new QTcpSocket(this);
    connect(mySocket, SIGNAL(readyRead()), this, SLOT(readCommand()));
    connect(mySocket, SIGNAL(disconnected()), this, SLOT(serverDisconnected()));
    mySocket->connectToHost("localhost",5000);


    menu = new QPushButton(this);
    menu->setGeometry(20,3,105,35);
    menu->setFlat(true);
    menu->setStyleSheet("background:url(:/images/button) no-repeat top left;border-style:none;background-color:rgba(0, 0, 0, 0);");
    menu->setText("Main Menu");
    menu->show();
    connect(this->menu, SIGNAL(clicked()), this, SLOT(return_to_menu()));

}

gameScreen::~gameScreen()
{
    delete gsui;
}


void gameScreen::readCommand()
{
    if(mySocket->canReadLine()){
        QString str = mySocket->readLine();
        qDebug() << str;
        mySocket->write(str.toAscii());

    }
}

void gameScreen::serverDisconnected()
{

}

void gameScreen::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_P && !e->isAutoRepeat())
    {
        if (pPressed == false){
           timer->stop();
           pPressed = true;
           lblPause->show();
           pause->show();
        } else {
           timer->start();
           pPressed = false;
           lblPause->hide();
           pause->hide();
        }
        qDebug() << "P";
    }
    if(e->key() == Qt::Key_W && !e->isAutoRepeat())
    {
        //REM
        wPressed = true;
        qDebug() << "W";
        //REM
    }
    if(e->key() == Qt::Key_A && !e->isAutoRepeat())
    {
        //REM
        aPressed = true;
        qDebug() << "A";
        //REM
    }
    if(e->key() == Qt::Key_S && !e->isAutoRepeat())
    {
        //REM
        sPressed = true;
        qDebug() << "S";
        //REM
    }
    if(e->key() == Qt::Key_D && !e->isAutoRepeat())
    {
        //REM
        dPressed = true;
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
        wPressed = false;
        qDebug() << "~W";
        //REM
    }
    if(e->key() == Qt::Key_A && !e->isAutoRepeat())
    {
        //REM
        aPressed = false;
        qDebug() << "~A";
        //REM
    }
    if(e->key() == Qt::Key_S && !e->isAutoRepeat())
    {
        //REM
        sPressed = false;
        qDebug() << "~S";
        //REM
    }
    if(e->key() == Qt::Key_D && !e->isAutoRepeat())
    {
        //REM
        dPressed = false;
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
    //qDebug() << "Tick";
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
