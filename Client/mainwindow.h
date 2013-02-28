#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//#include "startwindow.h"
#include <QMainWindow>


namespace Ui {
    class MainWindow;
    class StartWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
signals:
    void hideStart();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
