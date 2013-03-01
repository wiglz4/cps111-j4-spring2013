#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QListView>
//REM
#include <QTimer>
//REM
#include <QKeyEvent>
#include <QDebug>
#include <assert.h>
#include <QLabel>
#include <QPixmap>

//REM
#include <cmath>
//REM




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //REM
    timer = new QTimer(this);
    timer->setInterval(1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimerHit()));
    timer->start();
    //REM

    wPressed = false;
    aPressed = false;
    dPressed = false;
    sPressed = false;

    lblPlayer = new QLabel(ui->frBackground)
    QPixmap icon(":images/hero1.png");
    lblPlayer->setPixmap(icon);
    lblPlayer->setGeometry(360, 240, 36, 50);
    lblPlayer->show();
}

void MainWindow::keyPressEvent(QKeyEvent *e)
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
}

void MainWindow::keyReleaseEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_W && !e->isAutoRepeat())
    {
        //REM
        wPressed = false;
        qDebug() << "~W";
        //REM
        lblPlayer->move(lblPlayer.x(), lblPlayer.y() + 1);
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
}

MainWindow::~MainWindow()
{
    delete ui;
}

//REM
void MainWindow::onTimerHit()
{
    qDebug() <<"TIMER STRUCK";
    /*
    theta = asin((row-finalRow)/finalDistance);
           delta = acos((col-finalCol)/finalDistance);
           if(finalRow > row)
           {
               row = row + abs(speed * sin(theta));
           }
           else
           {
               row = row - abs(speed * sin(theta));
           }
           if(finalCol > col)
           {
               col = col + abs(speed * cos(theta));
           }
           else
           {
               col = col - abs(speed * cos(theta));
           }
           */

    if(wPressed && !aPressed && !sPressed && !dPressed)
    {
        lblPlayer.move(lblPlayer.x(), lblPlayer.y() + 1);
    }
    /*
    if(wPressed && !aPressed && !sPressed && dPressed)
    {

    }
    */
    if(!wPressed && !aPressed && !sPressed && dPressed)
    {
        lblPlayer.move(lblPlayer.x() + 1, lblPlayer.y());
    }
    /*
    if(!wPressed && !aPressed && sPressed && dPressed)
    {

    }
    */
    if(!wPressed && !aPressed && sPressed && !dPressed)
    {
        lblPlayer.move(lblPlayer.x(), lblPlayer.y() - 1);
    }
    /*
    if(!wPressed && aPressed && sPressed && !dPressed)
    {

    }
    */
    if(!wPressed && aPressed && !sPressed && !dPressed)
    {
        lblPlayer.move(lblPlayer.x() - 1, lblPlayer.y());
    }
    /*
    if(wPressed && aPressed && !sPressed && !dPressed)
    {

    }
    */
}
//REM


