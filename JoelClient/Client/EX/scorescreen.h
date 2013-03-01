#ifndef SCORESCREEN_H
#define SCORESCREEN_H

#include <QWidget>
#include "widget.h"

namespace Ui
{
class scoreScreen;
}

class scoreScreen : public QWidget
{
    Q_OBJECT
    
public:
    explicit scoreScreen(QWidget *parent = 0);
    ~scoreScreen();
    
private:
    Ui::scoreScreen *ssui;
};

#endif // SCORESCREEN_H
