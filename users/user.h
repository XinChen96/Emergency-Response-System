#ifndef USER_H
#define USER_H
#include "QString"
#include "../users/dbitem.h"

class User : public DBItem {
public:
    User(QString first, QString last, QString user, int id) : DBItem(id), first_name(first), last_name(last), username(user) {}
    ~User() {}

    QString first_name;
    QString last_name;
    QString username;
};

#endif // USER_H
