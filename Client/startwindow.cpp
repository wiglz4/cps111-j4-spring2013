#include "startwindow.h"
#include "mainwindow.h"
#include "ui_startwindow.h"
#include "ui_mainwindow.h"

StartWindow::StartWindow(QWidget *parent) :
    QWidget(parent),
    sui(new Ui::StartWindow),
    mui(new Ui::MainWindow)
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

void StartWindow::on_btnLocal_clicked()
{
    emit startLocal();
}
