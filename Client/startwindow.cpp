#include "startwindow.h"
#include "mainwindow.h"
#include "ui_startwindow.h"

StartWindow::StartWindow(QWidget *parent) :
    QWidget(parent),
    sui(new Ui::StartWindow)
{
    sui->setupUi(this);
}

StartWindow::~StartWindow()
{
    delete sui;
}

void StartWindow::on_btnLocal_clicked()
{

}
