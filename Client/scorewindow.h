#ifndef SCOREWINDOW_H
#define SCOREWINDOW_H

class ScoreWindow;
class ScoreObject;

#include <QDialog>
#include "ui_scorewindow.h"
#include "ui_widget.h"
#include "widget.h"
#include "gamescreen.h"
#include <QPushButton>
#include <QList>

class ScoreWindow : public QDialog
{
    Q_OBJECT
    
public:
    explicit ScoreWindow(QWidget *parent = 0);
    void connectWidget(Widget *w);
    void addScore(ScoreObject *);
    void addTime(int t);
    void makeEndGame();
    QList<ScoreObject> populateScores();
    void addScoreToScores(ScoreObject *);
    ~ScoreWindow();

    
private slots:
    void main_window();
    void onBtnExit2Clicked();

private:
    Ui::ScoreWindow *ui;
    Widget *w;
    QPushButton* main;
    QPushButton* btnExit2;
    QList<ScoreObject> *scores;
    bool isEndgame;
    int nextY;

signals:
    void start_main();
};

#endif // SCOREWINDOW_H


