#include "helpwindow.h"
#include "ui_helpwindow.h"
#include <QPixmap>
#include <QWidget>

HelpWindow::HelpWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HelpWindow)
{
    ui->setupUi(this);
    button = new QPushButton(this);
    button->setGeometry(165,260,105,35);
    button->setFlat(true);
    button->setStyleSheet("background:url(:/images/button) no-repeat top left;border-style:none;background-color:rgba(0, 0, 0, 0);");
    button->setText("Done");
    button->show();

    connect(this->button, SIGNAL(clicked()), this, SLOT(close_window()));
}

HelpWindow::~HelpWindow()
{
    delete ui;
}

void HelpWindow::close_window(){
    w->show();
    this->close();

}
