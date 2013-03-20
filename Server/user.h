#ifndef USER_H
#define USER_H

//NEEDS BUNCHES OF WORK

#include <string>
#include "stats.h"

class PlCh;
class QTcpSocket;

class User
{
    std::string userName;
    int team;
    QTcpSocket *sock;
    PlCh *character;



public:
    User();
    void setSocket(QTcpSocket *newSock){sock = newSock;}
    void setCharacter(PlCh *newChar){character = newChar;}
    void setUsername(std::string user){userName = user;}
    void setTeam(int nTeam){team = nTeam;}
    void command(std::string cmdString);
    bool checkInstanceVars();
    QTcpSocket* getSock(){return sock;}
    int getTeam(){return team;}
    std::string getName(){return userName;}
    QString score();
    //void command(std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
};

#endif // USER_H
