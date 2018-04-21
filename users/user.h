#ifndef USER_H
#define USER_H
#include "QString"
#include "../users/dbitem.h"
#include "roles.h"

class User : public DBItem {
public:

    User(QString first, QString last, QString user, Role r) :
        DBItem(-1)
    {
        first_name = first;
        last_name  = last;
        username   = user;

        switch(r){
        case(civilian):
            role = "Civilian";
                    break;
        case(planner):
            role = "Emergency Planner";
                    break;
        case(responder):
            role = "First Responder";
            break;
        case(NA):
            role = "N/A";

        }
    }

    User() : DBItem(-1) {}
    ~User() {}

    QString first_name;
    QString last_name;
    QString username;
    QString role;
};

#endif // USER_H
