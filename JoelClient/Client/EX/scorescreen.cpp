#include "scorescreen.h"
#include "ui_scorescreen.h"

scoreScreen::scoreScreen(QWidget *parent) :
    QWidget(parent),
    ssui(new Ui::scoreScreen)
{
    ssui->setupUi(this);
}

scoreScreen::~scoreScreen()
{
    delete ssui;
}

