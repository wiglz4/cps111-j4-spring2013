#include "widget.h"
#include "ui_widget.h"
#include "ui_gamescreen.h"
#include "scorewindow.h"
#include "ui_scorewindow.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    gsui(new Ui::gameScreen),
    scui(new Ui::ScoreWindow),
    hsui(new Ui::HelpWindow)
{
    ui->setupUi(this);

    mySocket = new QTcpSocket(this);
    connect(mySocket, SIGNAL(readyRead()), this, SLOT(readCommand()));
    connect(mySocket, SIGNAL(disconnected()), this, SLOT(serverDisconnected()));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::readCommand()
{
    while (mySocket->canReadLine()) {
        QString str = mySocket->readLine();
        qDebug() << str;
        QStringList tempList = str.split(" ", QString::SkipEmptyParts);
        qDebug() << tempList.at(0);
    }

}

void Widget::connectGame(gameScreen *g)
{
    this->g = g;
    gsui->setupUi(g);
    g->connectWidget(this);
}

void Widget::on_btnLocal_clicked()
{
    mySocket->connectToHost("localhost",5000);
    if (!mySocket->waitForConnected())  {
            qDebug() << "Unable to connect to server.";
            return;
    }
    QString message = "there you sexy thing you \n";
    mySocket->write(message.toAscii());
    g->show();
    g->takeOverKeyboard();
    this->hide();
}

void Widget::close_dialog()
{
    this->show();
    s->hide();
}

void Widget::connectScores(ScoreWindow *s)
{
    this->s = s;
    scui->setupUi(s);
    s->connectWidget(this);
}

void Widget::on_btnScores_clicked()
{    
    s->show();
    this->hide();
}

void Widget::connectHelp(HelpWindow *h)
{
    this->h = h;
    hsui->setupUi(h);
    h->connectWidget(this);
}

void Widget::on_btnHelp_clicked()
{
    h->show();
    this->hide();    
}

void Widget::on_btnExit_clicked()
{
    this->close();
}

void Widget::serverDisconnected()
{
    //
}
