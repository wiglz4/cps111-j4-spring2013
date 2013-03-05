#include "helpwindow.h"
#include "ui_helpwindow.h"

HelpWindow::HelpWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HelpWindow)
{
    ui->setupUi(this);
    button = new QPushButton(this);
    button->setGeometry(20,20,105,35);
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
    this->close();
    w->show();
}
