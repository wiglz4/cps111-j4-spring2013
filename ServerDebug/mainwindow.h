#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QTcpSocket *socket;
    QTimer *timer;
    int direction;
    int delay;
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void dataReceived();
    void serverDisconnected();
    void timerHit();
    
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
