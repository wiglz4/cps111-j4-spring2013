#include "scorewindow.h"
#include "ui_scorewindow.h"

ScoreWindow::ScoreWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ScoreWindow)
{
    ui->setupUi(this);
    ui->btnDone->setDefault(true);
}

ScoreWindow::~ScoreWindow()
{
    delete ui;
}




void ScoreWindow::on_btnDone_clicked()
{
}
