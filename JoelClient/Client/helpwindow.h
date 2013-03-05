#ifndef HELPWINDOW_H
#define HELPWINDOW_H

class HelpWindow;

#include <QWidget>
#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>

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
    QPushButton *button;

private slots:
    void close_window();
};

#endif // HELPWINDOW_H
