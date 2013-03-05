#ifndef WIDGET_H
#define WIDGET_H

namespace Ui {
class Widget;
class gameScreen;
class ScoreWindow;
class HelpWindow;
}

class Widget;

#include <QWidget>
#include "gamescreen.h"
#include "ui_gamescreen.h"
#include "ui_widget.h"
#include "ui_scorewindow.h"
#include "scorewindow.h"
#include "helpwindow.h"
#include "ui_helpwindow.h"

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    
    void connectGame(gameScreen *g);
    void connectScores(ScoreWindow *s);
    void connectHelp(HelpWindow *h);

private slots:
    void on_btnLocal_clicked();

    void on_btnScores_clicked();

    void close_dialog();

    void on_btnHelp_clicked();

signals:
    void startLocal();

private:
    Ui::Widget *ui;
    Ui::gameScreen *gsui;
    Ui::ScoreWindow *scui;
    Ui::HelpWindow *hsui;
    gameScreen *g;
    ScoreWindow *s;
    HelpWindow *h;
};

#endif // WIDGET_H
