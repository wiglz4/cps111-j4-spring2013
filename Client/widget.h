#ifndef WIDGET_H
#define WIDGET_H

namespace Ui {
class Widget;
class GameScreen;
class ScoreWindow;
class HelpWindow;
class GameStartWidget;
}

class Widget;
class GameStartWidget;

#include <QWidget>
#include "gamescreen.h"
#include "ui_gamescreen.h"
#include "ui_widget.h"
#include "ui_scorewindow.h"
#include "ui_gamestartwidget.h"
#include "scorewindow.h"
#include "helpwindow.h"
#include "gamestartwidget.h"
#include "ui_helpwindow.h"
#include <QTcpSocket>

class Widget : public QWidget
{
    Q_OBJECT
    
    //Instance Variables
    GameScreen *g;

    Ui::GameScreen *gsui;

    GameStartWidget *gsw;

    Ui::GameStartWidget *gswui;

    HelpWindow *h;

    Ui::HelpWindow *hsui;

    QTcpSocket *mySocket;

    ScoreWindow *s;

    Ui::ScoreWindow *scui;

    Ui::Widget *ui;

public:
    //Constructor
    explicit Widget(QWidget *parent = 0);

    //Destructor
    ~Widget();
    
    //Setter Methods
    void connectGame(GameScreen *g);
    void connectScores(ScoreWindow *s);
    void connectHelp(HelpWindow *h);
    void connectStart(GameStartWidget *gsw);

private slots:

    //Button Clicks
    void on_btnExit_clicked();
    void on_btnHelp_clicked();
    void on_btnLoad_clicked();
    void on_btnLocal_clicked();
    void on_btnNetwork_clicked();
    void on_btnScores_clicked();

signals:
    void startLocal();

private:
};

#endif // WIDGET_H
