#include "helpwindow.h"
#include "ui_helpwindow.h"
#include <QPixmap>
#include <QWidget>
#include <QDesktopWidget>
#include <QSize>

HelpWindow::HelpWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HelpWindow)
{
    ui->setupUi(this);

    img = new QLabel(this);
    img->setGeometry(0,0,775,375);
    img->setStyleSheet("background:url(:/images/backgrounde) no-repeat right top;");
    img->show();

    main = new QPushButton(this);
    main->setGeometry(570,161,121,31);
    main->setFlat(true);
    main->setFocusPolicy(Qt::NoFocus);
    main->setStyleSheet("QPushButton { background:url(:/images/buttonmm) no-repeat right top; } QPushButton:hover{ background:url(:/images/buttonmm2.png) no-repeat right top; } QPushButton:pressed { background:url(:/images/buttonmm.png) no-repeat right top; border: 0px solid grey; }");
    connect(this->main, SIGNAL(clicked()), this, SLOT(main_window()));

    btnExit2 = new QPushButton(this);
    btnExit2->setGeometry(604,185,121,31);
    btnExit2->setFlat(true);
    btnExit2->setFocusPolicy(Qt::NoFocus);
    btnExit2->setStyleSheet("QPushButton { background:url(:/images/buttonex) no-repeat right top; } QPushButton:hover{ background:url(:/images/buttonex2.png) no-repeat right top; } QPushButton:pressed { background:url(:/images/buttonex.png) no-repeat right top; border: 0px solid grey; }");
    btnExit2->show();
    connect(this->btnExit2, SIGNAL(clicked()), this, SLOT(onBtnExit2Clicked()));

    QDesktopWidget *desktop = QApplication::desktop();
    int screenWidth, width;
    int screenHeight, height;
    int x, y;
    QSize windowSize;

    screenWidth = desktop->width();
    screenHeight = desktop->height();

    windowSize = size();
    width = windowSize.width();
    height = windowSize.height();

    x = (screenWidth - width)/2;
    y = (screenHeight - height)/2;
    y -= 50;

    move(x, y);
    setFixedSize(windowSize.width(), windowSize.height());

    setWindowFlags(Qt::SplashScreen);
}

HelpWindow::~HelpWindow()
{
    delete ui;
}

void HelpWindow::main_window(){
    //qDebug() << "pressed";
    this->hide();
    w->show();
}

void HelpWindow::onBtnExit2Clicked()
{
    QApplication::quit();
}


void HelpWindow::onBtnNetworkClicked()
{

}
