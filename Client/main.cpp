#include "mainwindow.h"
#include "startwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StartWindow s;
    MainWindow m;
    ScoreWindow sc;
    s.connectScore(&sc);
    s.connectMain(&m);
    s.show();

    
    return a.exec();
}
