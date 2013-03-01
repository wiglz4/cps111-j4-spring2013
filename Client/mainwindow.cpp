#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QListView>
//REM
#include <QTimer>
//REM
#include <QKeyEvent>
#include <QDebug>
#include <assert.h>




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //REM
    timer = new QTimer(this);
    timer->setInterval(20);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimerHit());
    timer->start();
    //REM
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
    if(wPressed && !aPressed && !sPressed && !dPressed)
    {

    }
    if(wPressed && !aPressed && !sPressed && dPressed)
    {

    }
    if(!wPressed && !aPressed && !sPressed && !dPressed)
    {

    }
    if(!wPressed && !aPressed && sPressed && dPressed)
    {

    }
    if(!wPressed && !aPressed && sPressed && !dPressed)
    {

    }
    if(!wPressed && aPressed && sPressed && !dPressed)
    {

    }
    if(!wPressed && aPressed && !sPressed && !dPressed)
    {

    }
    if(wPressed && aPressed && !sPressed && !dPressed)
    {

    }
}
//REM


