#ifndef USER_H
#define USER_H
#include <string>
#include <QTcpSocket>

class PlCh;

class User
{
    std::string userName;
    int team;
    QTcpSocket *sock;
    PlCh *character;

public:
    User();
    void setSocket(QTcpSocket * newSock){sock = newSock;}
    void setCharacter(PlCh *newChar){character = newChar;}
    void setUsername(std::string user){userName = user;}
    void defaultTeam(){team = 1;}
};

#endif // USER_H
