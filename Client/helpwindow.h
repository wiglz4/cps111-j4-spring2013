#ifndef HELPWINDOW_H
#define HELPWINDOW_H

class HelpWindow;

#include <QWidget>
#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QLabel>

class HelpWindow : public QWidget
{
    Q_OBJECT
    
public:
    explicit HelpWindow(QWidget *parent = 0);
    void connectWidget(Widget *w){this->w = w;}
    ~HelpWindow();
    
private:
    Ui::HelpWindow *ui;
    Widget *w;
    QPushButton* main;
    QPushButton* btnExit2;
    QLabel* img;
    QWidget *arrows;

private slots:
    void main_window();
    void on_btnExit2_clicked();
};

#endif // HELPWINDOW_H
