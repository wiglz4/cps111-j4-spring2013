#include <QApplication>
#include "widget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    gameScreen g;
    Widget w;
    ScoreWindow s;
    HelpWindow h;
    w.connectHelp(&h);
    w.connectGame(&g);
    w.connectScores(&s);
    w.show();
    
    return a.exec();
}
