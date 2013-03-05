#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "gamescreen.h"
#include "ui_gamescreen.h"
#include "ui_widget.h"
#include "ui_scorewindow.h"

class gameScreen;
class ScoreWindow;

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    
    void connectGame(gameScreen *g);
    void connectScores(ScoreWindow *s);

private slots:
    void on_btnLocal_clicked();

    void on_btnScores_clicked();

    void close_dialog();

signals:
    void startLocal();

private:
    Ui::Widget *ui;
    Ui::gameScreen *gsui;
    Ui::ScoreWindow *scui;
    gameScreen *g;
    ScoreWindow *s;
};

#endif // WIDGET_H
