#ifndef HELPWINDOW_H
#define HELPWINDOW_H

class HelpWindow;

#include <QWidget>
#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QLabel>

/*This class defines the gui of the
 help window*/

class HelpWindow : public QWidget
{
    Q_OBJECT
    
    //Instance Variables
    Ui::HelpWindow *ui;

    QPushButton* btnMain;
    QPushButton* btnExit2;

    QLabel* lblImg;

    QWidget *arrows;

    Widget *w;

public:
    //Constructor
    explicit HelpWindow(QWidget *parent = 0);

    //Destructor
    ~HelpWindow();

    //Setter Methods
    //------------//

    //Sets <this->w> to <w>
    void connectWidget(Widget *w){this->w = w;}

private slots:

    //Button Clicks
    void onMainWindowClicked();
    void onBtnExit2Clicked();
    void onBtnNetworkClicked();
};

#endif // HELPWINDOW_H
