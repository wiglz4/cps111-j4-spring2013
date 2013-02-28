#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include "mainwindow.h"
#include <QWidget>

namespace Ui {
    class StartWindow;
}

class StartWindow : public QWidget
{
    Q_OBJECT
    
public:
    explicit StartWindow(QWidget *parent = 0);
    ~StartWindow();

private slots:
    void on_btnLocal_clicked();

private:
    Ui::StartWindow *sui;
    Ui::MainWindow *mui;
};

#endif // STARTWINDOW_H
