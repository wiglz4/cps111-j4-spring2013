#include "startwindow.h"
#include "mainwindow.h"
#include "ui_startwindow.h"
#include "ui_mainwindow.h"
#include "ui_scorewindow.h"

StartWindow::StartWindow(QWidget *parent) :
    QWidget(parent),
    sui(new Ui::StartWindow),
    mui(new Ui::MainWindow),
    scui(new Ui::ScoreWindow)
{
    sui->setupUi(this);

}

StartWindow::~StartWindow()
{
    delete sui;
}

void StartWindow::connectMain(MainWindow *m){
    mui->setupUi(m);
    connect(this, SIGNAL(startLocal()), m, SLOT(show()));
}

void StartWindow::connectScore(ScoreWindow *sc){
    scui->setupUi(sc);
    connect(this, SIGNAL(startScore()), sc, SLOT(show()));
}

void StartWindow::on_btnLocal_clicked()
{
    emit startLocal();
}

void StartWindow::on_btnScores_clicked()
{
    emit startScore();
}
