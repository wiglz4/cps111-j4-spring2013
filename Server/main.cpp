#include <QtGui/QApplication>
#include "serverwindow.h"
#include "stats.h"

using namespace std;

int main(int argc, char *argv[])
{
    Stats test("bob");
    vector<string> args(argv, argv + argc);
    if (args.size() > 1){
        if (args.at(1) == "-test"){
            if (test.runTests() == true){
                qDebug() <<"All test passed.";
            }
        }
    }

    QApplication a(argc, argv);
    ServerWindow w;
    w.show();

    return a.exec();
}

