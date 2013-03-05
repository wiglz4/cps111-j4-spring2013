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
    void setSocket(QTcpSocket * newSock){sock = newSock;}
    void setCharacter(PlCh *newChar){character = newChar;}
    void setUsername(string user){userName = user;}
    void defaultTeam(){team = 1;}
};

#endif // USER_H
