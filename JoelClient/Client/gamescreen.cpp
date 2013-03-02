#include "gamescreen.h"
#include "ui_gamescreen.h"
#include "entitylabel.h"
#include <QPixmap>
#include <QString>

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

    wdgtPicture = new QWidget(this);
    wdgtPicture->setGeometry(20,20,4000,3000);
    wdgtPicture->setStyleSheet("background-image:url(:/images/mapsm.png)");
    hero = new EntityLabel(wdgtPicture);
    hero->setGeometry(100,100,110,110);
    //QPixmap icon(":/images/hero1.png");
    //hero->setPixmap(icon);
    hero->setStyleSheet("background:url(:/images/1.png) no-repeat top left;background-color:rgba(0, 0, 0, 0);");
    hero->show();

    gameFrame = new QFrame(this);
    gameFrame->setFrameShape(QFrame::Box);
    gameFrame->setLineWidth(20);
    gameFrame->setGeometry(0, 0, 800, 600);
    gameFrame->show();

    wPressed = false;
    aPressed = false;
    sPressed = false;
    dPressed = false;


    upPressed = false;
    rightPressed = false;
    downPressed = false;
    leftPressed = false;

    counter = 1;

}

gameScreen::~gameScreen()
{
    delete gsui;
}

void gameScreen::keyPressEvent(QKeyEvent *e)
{
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
    }

    if(wPressed && !aPressed && !sPressed && dPressed)
    {
        hero->move(hero->x()+2, hero->y()-2);
    }

    if(!wPressed && !aPressed && !sPressed && dPressed)
    {
        hero->move(hero->x()+4, hero->y());
    }

    if(!wPressed && !aPressed && sPressed && dPressed)
    {
        hero->move(hero->x()+2, hero->y()+2);
    }

    if(!wPressed && !aPressed && sPressed && !dPressed)
    {
        hero->move(hero->x(), hero->y()+4);
    }

    if(!wPressed && aPressed && sPressed && !dPressed)
    {
        hero->move(hero->x()-2, hero->y()+2);
        counter++;
        if (counter > 19) {
            counter = 1;
        }
        QString test;
        hero->setStyleSheet("background:url(:/images/" + test.append(QString("%1").arg(counter)) + ".png) no-repeat top left;background-color:rgba(0, 0, 0, 0);");
    }

    if(!wPressed && aPressed && !sPressed && !dPressed)
    {
        hero->move(hero->x()-4, hero->y());
    }

    if(wPressed && aPressed && !sPressed && !dPressed)
    {
        hero->move(hero->x()-2, hero->y()-2);
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
