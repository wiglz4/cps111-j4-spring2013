#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//#include "startwindow.h"
#include <QMainWindow>
#include <QKeyEvent>
#include <QLabel>
//REM
#include <QTimer>
//REM


namespace Ui {
    class MainWindow;
    class StartWindow;
    class ScoreWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void onTimerHit();
    
protected:
    void keyPressEvent(QKeyEvent * e);
    void keyReleaseEvent(QKeyEvent *e);
    QLabel *lblPlayer;

private:
    Ui::MainWindow *ui;
    QKeyEvent *key;
    QTimer *timer;
    //REM
    bool wPressed;
    bool aPressed;
    bool sPressed;
    bool dPressed;
    //REM

signals:
    void hideStart();
};

#endif // MAINWINDOW_H
