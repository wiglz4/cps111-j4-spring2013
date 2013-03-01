#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "gamescreen.h"
#include "ui_gamescreen.h"
#include "ui_widget.h"
class gameScreen;
namespace Ui {
class Widget;
class gameScreen;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    
    void connectGame(gameScreen *g);

private slots:
    void on_btnLocal_clicked();

signals:
    void startLocal();

private:
    Ui::Widget *ui;
    Ui::gameScreen *gsui;
};

#endif // WIDGET_H
