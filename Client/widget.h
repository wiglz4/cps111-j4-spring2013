#ifndef WIDGET_H
#define WIDGET_H

namespace Ui {
class Widget;
class gameScreen;
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
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    
    void connectGame(GameScreen *g);
    void connectScores(ScoreWindow *s);
    void connectHelp(HelpWindow *h);
    void connectStart(GameStartWidget *gsw);

private slots:
    void on_btnLocal_clicked();

    void on_btnNetwork_clicked();

    void on_btnScores_clicked();

    void close_dialog();

    void on_btnHelp_clicked();

    void on_btnExit_clicked();


    void on_btnLoad_clicked();

signals:
    void startLocal();

private:
    Ui::Widget *ui;
    Ui::gameScreen *gsui;
    Ui::ScoreWindow *scui;
    Ui::HelpWindow *hsui;
    Ui::GameStartWidget *gswui;
    GameScreen *g;
    ScoreWindow *s;
    HelpWindow *h;
    GameStartWidget *gsw;
    QTcpSocket *mySocket;
};

#endif // WIDGET_H
