#include "scorewindow.h"
#include "widget.h"
#include "ui_scorewindow.h"
#include "gamescreen.h"
#include "ui_widget.h"
#include <QDebug>
#include <QPushButton>

ScoreWindow::ScoreWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ScoreWindow)
{
    ui->setupUi(this);
    close = new QPushButton(this);
    close->setGeometry(75,350,105,35);
    close->setFlat(true);
    close->setStyleSheet("background:url(:/images/button) no-repeat top left;border-style:none;background-color:rgba(0, 0, 0, 0);");
    close->setText("Done");
    close->show();
    connect(this->close, SIGNAL(clicked()), this, SLOT(close_window()));

}

ScoreWindow::~ScoreWindow()
{
    delete ui;
}


void ScoreWindow::close_window(){
    qDebug() << "pressed";
    this->hide();
    w->show();
}




