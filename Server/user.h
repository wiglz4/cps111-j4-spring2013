#ifndef USER_H
#define USER_H
#include <QTcpSocket>
#include "plch.h"

//NEEDS BUNCHES OF WORK

class User
{
    string userName;
    int team;
    QTcpSocket *sock;
    PlCh *character;

public:
    User();
};

#endif // USER_H
