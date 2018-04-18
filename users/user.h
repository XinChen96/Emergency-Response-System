#ifndef USER_H
#define USER_H
#include "QString"
#include "../users/dbitem.h"
#include "roles.h"

class User : public DBItem {
public:
    User(QString first, QString last, QString user, Role r, int id) : DBItem(id), first_name(first), last_name(last), username(user), role(r) {}
    ~User() {}

    QString first_name;
    QString last_name;
    QString username;
    Role role;
};

#endif // USER_H
