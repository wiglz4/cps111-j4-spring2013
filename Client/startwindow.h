#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include "mainwindow.h"
#include "scorewindow.h"
#include <QWidget>



class StartWindow : public QWidget
{
    Q_OBJECT
    
public:
    explicit StartWindow(QWidget *parent = 0);
    ~StartWindow();

    void connectMain(MainWindow *m);
    void connectScore(ScoreWindow *sc);

private slots:
    void on_btnLocal_clicked();

    void on_btnScores_clicked();

signals:
    void startLocal();
    void startScore();

private:
    Ui::StartWindow *sui;
    Ui::MainWindow *mui;
    Ui::ScoreWindow *scui;
};

#endif // STARTWINDOW_H
