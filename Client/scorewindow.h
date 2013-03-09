#ifndef SCOREWINDOW_H
#define SCOREWINDOW_H

class ScoreWindow;

#include <QDialog>
#include "ui_scorewindow.h"
#include "ui_widget.h"
#include "widget.h"
#include <QPushButton>

class ScoreWindow : public QDialog
{
    Q_OBJECT
    
public:
    explicit ScoreWindow(QWidget *parent = 0);
    void connectWidget(Widget *w);
    ~ScoreWindow();

    
private slots:
    void main_window();
    void on_btnExit2_clicked();

private:
    Ui::ScoreWindow *ui;
    Widget *w;
    QPushButton* main;
    QPushButton* btnExit2;

signals:
    void start_main();
};

#endif // SCOREWINDOW_H


