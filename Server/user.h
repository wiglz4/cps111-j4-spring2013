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
    int userID;

public:
    User();
    void setSocket(QTcpSocket *newSock){sock = newSock;}
    void setCharacter(PlCh *newChar){character = newChar;}
    void setUsername(std::string user){userName = user;}
    void setUserID(int id){userID = id;}
    void setTeam(int nTeam){team = nTeam;}
    void command(std::string cmdString);

    int getUserID(){return userID;}

    //checks to see whether this user has specified their name and team
    bool checkInstanceVars();
    QTcpSocket* getSock(){return sock;}
    int getTeam(){return team;}
    std::string getName(){return userName;}

    //returns this user's score
    QString score();
};

#endif // USER_H
