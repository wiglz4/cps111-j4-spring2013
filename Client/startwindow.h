#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include "mainwindow.h"
#include <QWidget>



class StartWindow : public QWidget
{
    Q_OBJECT
    
public:
    explicit StartWindow(QWidget *parent = 0);
    ~StartWindow();

    void connectMain(MainWindow *m);

private slots:
    void on_btnLocal_clicked();

signals:
    void startLocal();

private:
    Ui::StartWindow *sui;
    Ui::MainWindow *mui;
};

#endif // STARTWINDOW_H
