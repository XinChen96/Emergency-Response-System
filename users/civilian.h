#ifndef CIVILIAN_H
#define CIVILIAN_H
#include "user.h"

class Civilian : public User {
public:
    Civilian(QString first, QString last, QString user, QString r, int id, int groupid) : User(first, last, id), username(user), role(r), group_id(groupid) {}
    ~Civilian() {}

    QString username;
    QString role;
    int group_id;
};

#endif // CIVILIAN_H
