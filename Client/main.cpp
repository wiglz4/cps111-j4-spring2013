#include <QApplication>
#include "widget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    gameScreen g;
    Widget w;
    ScoreWindow s;
    HelpWindow h;
    GameStartWidget gsw;
    w.connectHelp(&h);
    w.connectGame(&g);
    w.connectScores(&s);
    w.connectStart(&gsw);
    w.show();
    
    return a.exec();
}
