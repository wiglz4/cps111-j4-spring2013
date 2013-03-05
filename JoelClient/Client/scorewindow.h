#ifndef SCOREWINDOW_H
#define SCOREWINDOW_H

#include <QDialog>
#include "gamescreen.h"
#include "ui_scorewindow.h"
#include "ui_widget.h"
#include "widget.h"
#include <QPushButton>

class Widget;

class ScoreWindow : public QDialog
{
    Q_OBJECT
    
public:
    explicit ScoreWindow(QWidget *parent = 0);
    void connectWidget(Widget *w){this->w = w;}
    ~ScoreWindow();

    
private slots:
    void close_window();


private:
    Ui::ScoreWindow *ui;
    Widget *w;
    QPushButton* close;

signals:
    void start_main();
};

#endif // SCOREWINDOW_H
