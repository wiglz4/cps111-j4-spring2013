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

/*This class defines the window used for
 the start game options in singleplayer,
 multiplayer, and load-game mode*/
class GameStartWidget : public QWidget
{
    Q_OBJECT

    //Instance Variables
    bool loading;

    GameScreen *g;

    Ui::GameStartWidget *ui;

    QLabel *lblImg;
    QLabel *lblHost;
    QLabel *lblSave;

    QLineEdit *lnedHost;
    QLineEdit *lnedSave;
    QLineEdit *lnedUsername;

    QPushButton *btnBlue;
    QPushButton *btnExit2;
    QPushButton *btnMain;
    QPushButton *btnRed;
    QPushButton *btnStart;

    QTcpSocket *sock;

    Widget *w;

public:
    //Constructor
    explicit GameStartWidget(QWidget *parent = 0);

    //Destructor
    ~GameStartWidget();

    //Setter Methods
    //------------//

    //Sets <w>, <sock>, and <g>
    void connectStuff(Widget*, QTcpSocket*, GameScreen*);

    //Display Methods
    //-------------//

    //Show objects necessary for multiplayer
    void dislpayHost();

    //Show objects necessary for loading
    void displayLoad();

    //Hide objects necessary for multiplayer
    void hideHost();

    //Hide objects necessary for loading
    void hideLoad();

private slots:
    //Button Clicks
    void onMainWindowClicked();
    void onBtnExitClicked();
    void onBtnStartClicked();
    void onRedClicked();
    void onBlueClicked();

private:

};

#endif // GAMESTARTWIDGET_H
