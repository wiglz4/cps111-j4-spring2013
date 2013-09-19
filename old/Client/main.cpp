//-----------------------------------------------------------
//File:   main.cpp
//Authors: Jeremie Miller, Jonathan Neves, Joel Sampson, John Wiglesworth
//User IDs: jmill521, jneve321, jsamp710, jwigl437   Class: CPS 110
//Desc:   This provides the magic starting bit for the game. And
//          all the nasty work of connecting everything together.
//-----------------------------------------------------------
#include <QApplication>
#include "widget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GameScreen g;
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
