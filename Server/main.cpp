#include <QtGui/QApplication>
#include "serverwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    serverWindow w;
    w.show();
    
    return a.exec();
}
