#include "gamestartwidget.h"
#include "ui_gamestartwidget.h"
#include <QLineEdit>
#include <QLabel>
#include <QMessageBox>
#include <QDesktopWidget>
#include "widget.h"
#include "gamescreen.h"

class GameStartWidget;

GameStartWidget::GameStartWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameStartWidget)
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
    btnExit2->setGeometry(604,209,121,31);
    btnExit2->setFlat(true);
    btnExit2->setFocusPolicy(Qt::NoFocus);
    btnExit2->setStyleSheet("QPushButton { background:url(:/images/buttonex) no-repeat right top; } QPushButton:hover{ background:url(:/images/buttonex2.png) no-repeat right top; } QPushButton:pressed { background:url(:/images/buttonex.png) no-repeat right top; border: 0px solid grey; }");
    btnExit2->show();
    connect(this->btnExit2, SIGNAL(clicked()), this, SLOT(on_btnExit2_clicked()));

    btnStart = new QPushButton(this);
    btnStart->setGeometry(572,185,121,31);
    btnStart->setFlat(true);
    btnStart->setFocusPolicy(Qt::NoFocus);
    btnStart->setStyleSheet("QPushButton { background:url(:/images/buttonsg) no-repeat right top; } QPushButton:hover{ background:url(:/images/buttonsg2.png) no-repeat right top; } QPushButton:pressed { background:url(:/images/buttonex.png) no-repeat right top; border: 0px solid grey; }");
    btnStart->show();
    connect(this->btnStart, SIGNAL(clicked()), this, SLOT(on_btnStart_clicked()));

    lnedHost = new QLineEdit(this);
    lnedHost->setGeometry(80, 190, 211, 27);
    lnedHost->setFrame(false);
    lnedHost->setStyleSheet("background-color:rgba(0,0,0,100);\ncolor:#fff;\nselection-background-color: rgba(0, 0, 0, 50);");
    lnedHost->setText("localhost");
    lnedHost->setEchoMode(QLineEdit::Normal);
    lnedHost->show();

    lnedUsername = new QLineEdit(this);
    lnedUsername->setGeometry(80, 120, 211, 27);
    lnedUsername->setFrame(false);
    lnedUsername->setStyleSheet("background-color:rgba(0,0,0,100);\ncolor:#fff;\nselection-background-color: rgba(0, 0, 0, 50);");
    lnedUsername->setText("PlayerName");
    lnedUsername->setEchoMode(QLineEdit::Normal);
    lnedUsername->show();

    lblHost = new QLabel(this);
    lblHost->setGeometry(80, 170, 67, 19);
    lblHost->setText("Server:");
    lblHost->show();

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
}

void GameStartWidget::ConnectStuff(Widget *wdgt, QTcpSocket *s, gameScreen *gmscr)
{
    g = gmscr;
    w = wdgt;
    sock = s;
}

void GameStartWidget::hideHost()
{
    lblHost->hide();
    lnedHost->hide();
}

void GameStartWidget::showHost()
{
    lblHost->show();
    lnedHost->show();
}

GameStartWidget::~GameStartWidget()
{
    delete ui;
}

void GameStartWidget::main_window()
{
    this->hide();
    w->show();
}

void GameStartWidget::on_btnExit2_clicked()
{
    this->close();
}

void GameStartWidget::on_btnStart_clicked()
{
    if (lnedHost->text() == "")  {
        sock->disconnect();
        QMessageBox::critical(this, "Error", "Unable to connect to host:\n" + lnedHost->text());
        return;
    }

    if (lnedUsername->displayText() == "" || lnedUsername->displayText() == "PlayerName"){
        qDebug() << lnedUsername->displayText();
        QMessageBox::critical(this, "Error", "Please enter a username");
        return;
    }

    sock->connectToHost(lnedHost->text(),5000);
    if (!sock->waitForConnected()){
        qDebug() << lnedHost->text();
        sock->disconnect();
        QMessageBox::critical(this, "Error", "Unable to connect to host:\n" + lnedHost->text());
        return;
    }

    QString message = "2 " + lnedUsername->displayText() + "\n";
    sock->write(message.toAscii());
    g->setPlayername(lnedUsername->text());
    g->show();
    g->grabKeyboard();
    g->passSocket(sock);
    g->grabMouse();
    this->hide();
}
