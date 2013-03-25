#ifndef GAMESTARTWIDGET_H
#define GAMESTARTWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include "widget.h"
#include "ui_widget.h"
#include "gamescreen.h"
#include "ui_gamescreen.h"
#include <QTcpSocket>
#include <QLineEdit>

namespace Ui {
class GameStartWidget;
}

class GameStartWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit GameStartWidget(QWidget *parent = 0);
    void ConnectStuff(Widget*, QTcpSocket*, gameScreen*);
    void hideHost();
    void showHost();
    ~GameStartWidget();
    
private slots:
    void main_window();
    void on_btnExit2_clicked();
    void on_btnStart_clicked();

private:
    Ui::GameStartWidget *ui;
    QLabel *img;

    QPushButton *main;
    QPushButton *btnExit2;
    QPushButton *btnStart;

    QLineEdit *lnedHost;
    QLabel *lblHost;
    QLineEdit *lnedUsername;

    Widget *w;
    gameScreen *g;
    QTcpSocket *sock;

};

#endif // GAMESTARTWIDGET_H
