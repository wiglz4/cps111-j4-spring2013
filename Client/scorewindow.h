#ifndef SCOREWINDOW_H
#define SCOREWINDOW_H

#include <QDialog>
#include <mainwindow.h>


class ScoreWindow : public QDialog
{
    Q_OBJECT
    
public:
    explicit ScoreWindow(QWidget *parent = 0);
    ~ScoreWindow();
    
signals:
    void end();

private slots:

    void on_btnDone_clicked();

private:
    Ui::ScoreWindow *ui;
};

#endif // SCOREWINDOW_H
