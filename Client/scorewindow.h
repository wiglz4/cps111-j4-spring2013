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

 /* This class defines the gui of the
 main score window, and the endgame
 score window */

class ScoreWindow : public QDialog
{
    Q_OBJECT
    
    //Instance Variables
    bool isEndgame;

    int nextY;

    QList<ScoreObject> *scores;

    QPushButton* btnExit2;
    QPushButton* btnMain;

    Ui::ScoreWindow *ui;

    Widget *w;

public:
    //Constructor
    explicit ScoreWindow(QWidget *parent = 0);

    //Destructor
    ~ScoreWindow();

    //Setter Methods
    //------------//

    //Sets <this->w> to <w>
    void connectWidget(Widget *w);

    //Sets text of <ui->lblTTIme>
    void addTime(int t);

    //Display Methods
    //-------------//

    //Sets up display for enndgame
    void makeEndGame();

    //Other Methods
    //-----------//

    //Adds a score to interface
    void addScore(ScoreObject *);

    //Unimplemented methods that don't work
    //-----------------------------------//
    QList<ScoreObject> populateScores();
    void addScoreToScores(ScoreObject *);

    
private slots:
    //Button Clicks
    void onBtnExit2Clicked();
    void onMainWindowClicked();

signals:
    void startMain();
};

#endif // SCOREWINDOW_H


