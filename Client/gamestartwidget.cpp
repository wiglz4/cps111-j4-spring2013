//-----------------------------------------------------------
//File:   gamestartwindow.cpp
//Authors: Jeremie Miller, Jonathan Neves, Joel Sampson, John Wiglesworth
//User IDs: jmill521, jneve321, jsamp710, jwigl437   Class: CPS 110
//Desc:   This provides the window that appears immediately aafter start.
//
//-----------------------------------------------------------

#include "gamestartwidget.h"
#include "ui_gamestartwidget.h"
#include <QLineEdit>
#include <QLabel>
#include <QMessageBox>
#include <QDesktopWidget>
#include "widget.h"
#include "gamescreen.h"
#include "QKeySequence"

class GameStartWidget;

//Constructor
GameStartWidget::GameStartWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameStartWidget)
{
    ui->setupUi(this);

    lblImg = new QLabel(this);
    lblImg->setGeometry(0,0,775,375);
    lblImg->setStyleSheet("background:url(:/images/backgrounde) no-repeat right top;");
    lblImg->show();

    btnMain = new QPushButton(this);
    btnMain->setGeometry(570,161,121,31);
    btnMain->setFlat(true);
    btnMain->setFocusPolicy(Qt::NoFocus);
    btnMain->setStyleSheet("QPushButton { background:url(:/images/buttonmm) no-repeat right top; } QPushButton:hover{ background:url(:/images/buttonmm2.png) no-repeat right top; } QPushButton:pressed { background:url(:/images/buttonmm.png) no-repeat right top; border: 0px solid grey; }");
    connect(this->btnMain, SIGNAL(clicked()), this, SLOT(onMainWindowClicked()));

    btnExit2 = new QPushButton(this);
    btnExit2->setGeometry(604,209,121,31);
    btnExit2->setFlat(true);
    btnExit2->setFocusPolicy(Qt::NoFocus);
    btnExit2->setStyleSheet("QPushButton { background:url(:/images/buttonex) no-repeat right top; } QPushButton:hover{ background:url(:/images/buttonex2.png) no-repeat right top; } QPushButton:pressed { background:url(:/images/buttonex.png) no-repeat right top; border: 0px solid grey; }");
    btnExit2->show();
    connect(this->btnExit2, SIGNAL(clicked()), this, SLOT(onBtnExitClicked()));

    btnStart = new QPushButton(this);
    btnStart->setGeometry(572,185,121,31);
    btnStart->setFlat(true);
    btnStart->setFocusPolicy(Qt::NoFocus);
    btnStart->setStyleSheet("QPushButton { background:url(:/images/buttonsg) no-repeat right top; } QPushButton:hover{ background:url(:/images/buttonsg2.png) no-repeat right top; } QPushButton:pressed { background:url(:/images/buttonsg.png) no-repeat right top; border: 0px solid grey; }");
    btnStart->show();
    connect(this->btnStart, SIGNAL(clicked()), this, SLOT(onBtnStartClicked()));

    lnedSave = new QLineEdit(this);
    lnedSave->setGeometry(80, 60, 211, 27);
    lnedSave->setFrame(false);
    lnedSave->setStyleSheet("background-color:rgba(0,0,0,100);\ncolor:#fff;\nselection-background-color: rgba(0, 0, 0, 50);");
    lnedSave->setEchoMode(QLineEdit::Normal);
    lnedSave->setText("filename");
    lnedSave->hide();

    lnedUsername = new QLineEdit(this);
    lnedUsername->setGeometry(80, 120, 211, 27);
    lnedUsername->setFrame(false);
    lnedUsername->setStyleSheet("background-color:rgba(0,0,0,100);\ncolor:#fff;\nselection-background-color: rgba(0, 0, 0, 50);");
    lnedUsername->setText("Ender_Wiggin");
    lnedUsername->setEchoMode(QLineEdit::Normal);
    lnedUsername->show();

    lnedHost = new QLineEdit(this);
    lnedHost->setGeometry(80, 190, 211, 27);
    lnedHost->setFrame(false);
    lnedHost->setStyleSheet("background-color:rgba(0,0,0,100);\ncolor:#fff;\nselection-background-color: rgba(0, 0, 0, 50);");
    lnedHost->setText("localhost");
    lnedHost->setEchoMode(QLineEdit::Normal);
    lnedHost->show();

    lblSave = new QLabel(this);
    lblSave->setGeometry(80, 40, 67, 19);
    lblSave->setText("Load:");
    lblSave->hide();

    lblHost = new QLabel(this);
    lblHost->setGeometry(80, 170, 67, 19);
    lblHost->setText("Server:");
    lblHost->show();


    this->btnRed = new QPushButton(this);
    this->btnRed->setGeometry(100, 230, 36, 36);
    this->btnRed->setFlat(true);
    btnRed->setFocusPolicy(Qt::NoFocus);
    this->btnRed->setStyleSheet("QPushButton { background: url(:/images/br_deselected.png) no-repeat top right; } QPushButton:hover{ background:url(:/images/br_clicked.png) no-repeat top left; } QPushButton:checked { background: url(:/images/br_selected.png) no-repeat top left; border: 0px solid grey; }");
    this->btnRed->setCheckable(true);
    this->btnRed->setChecked(false);
    connect(this->btnRed, SIGNAL(clicked()), this, SLOT(onRedClicked()));
    this->btnRed->show();

    this->btnBlue = new QPushButton(this);
    this->btnBlue->setGeometry(130, 230, 36, 36);
    this->btnBlue->setFlat(true);
    btnBlue->setFocusPolicy(Qt::NoFocus);
    this->btnBlue->setStyleSheet("QPushButton { background: url(:/images/bb_deselected.png) no-repeat top right; } QPushButton:hover{ background:url(:/images/bb_clicked.png) no-repeat top left; } QPushButton:checked { background: url(:/images/bb_selected.png) no-repeat top left; border: 0px solid grey; }");
    this->btnBlue->setCheckable(true);
    this->btnBlue->setChecked(true);
    connect(this->btnBlue, SIGNAL(clicked()), this, SLOT(onBlueClicked()));
    this->btnBlue->show();

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

    loading = false;
    multiplayer = false;
    setWindowFlags(Qt::SplashScreen);
}

//Sets <w>, <sock>, and <g>
void GameStartWidget::connectStuff(Widget *wdgt, QTcpSocket *s, GameScreen *gmscr)
{
    g = gmscr;
    w = wdgt;
    sock = s;
}

//Hide objects necessary for multiplayer
void GameStartWidget::hideHost()
{
    lblHost->hide();
    lnedHost->hide();
}

//Show objects necessary for multiplayer
void GameStartWidget::dislpayHost()
{
    lblHost->show();
    lnedHost->show();
}

//Show objects necessary for loading
void GameStartWidget::displayLoad()
{
    lnedSave->show();
    lblSave->show();
    btnRed->setEnabled(false);
    btnBlue->setEnabled(false);
    loading = true;
}

//Hide objects necessary for loading
void GameStartWidget::hideLoad()
{
    lnedSave->hide();
    lblSave->hide();
    btnRed->setEnabled(true);
    btnBlue->setEnabled(true);
    loading = false;
}

//Destructor
GameStartWidget::~GameStartWidget()
{
    delete ui;
}

//Main menu button clicked
void GameStartWidget::onMainWindowClicked()
{
    this->hide();
    w->show();
}


//exit button clicked
void GameStartWidget::onBtnExitClicked()
{
    QApplication::quit();

}

//start game clicked
void GameStartWidget::onBtnStartClicked()
{
    int num;
    QString message;
    QString filename = "";
    if(!loading)
    {
        if(this->btnRed->isChecked())
        {
            num = 1;
        }
        else if(this->btnBlue->isChecked())
        {
            num = 2;
        }
    }
    else
    {
        num = 5;
        if(lnedSave->text() == "" || lnedSave->text() == "filename")
        {
            QMessageBox::critical(this, "Error", "Please enter a valid filename");
            return;
        }
        filename = lnedSave->text() + " ";
    }

    if (lnedHost->text() == "")
    {
        QMessageBox::critical(this, "Error", "Unable to connect to host:\n" + lnedHost->text());
        return;
    }


    if (lnedUsername->displayText() == "" || lnedUsername->displayText() == "PlayerName"){
        QMessageBox::critical(this, "Error", "Please enter a username");
        return;
    }

    if(lnedUsername->displayText().indexOf(" ") != -1)
    {
        QMessageBox::warning(this, "Error", "Please enter a username with no spaces.....NONE!");
        return;
    }

    sock->connectToHost(lnedHost->text(),5000);
    if (!sock->waitForConnected())
    {
        sock->disconnect();
        QMessageBox::critical(this, "Error", "Unable to connect to host:\n" + lnedHost->text());
        return;
    }
    if(multiplayer)
    {
        message = "9 " + QString::number(num) + " " + filename + lnedUsername->displayText();
    }
    else
    {
        message = QString::number(num) + " " + filename + lnedUsername->displayText();
    }
    sock->write(message.toAscii());
    g->setPlayername(lnedUsername->text());
    g->show();
    g->grabKeyboard();
    g->passSocket(sock);
    g->TimeroftheGameGo();
    this->hide();
}

//red button clicked
void GameStartWidget::onRedClicked()
{
    this->btnBlue->setChecked(false);
    this->btnRed->setChecked(true);
}

//blue button clicked
void GameStartWidget::onBlueClicked()
{
    this->btnRed->setChecked(false);
    this->btnBlue->setChecked(true);
}
