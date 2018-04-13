#ifndef PLANNER_H
#define PLANNER_H
#include "user.h"

class Planner: public User
{
public:
    Planner(QString first, QString last, QString user, QString r, int id, int groupid) : User(first, last, id), username(user), role(r), group_id(groupid) {}
    ~Planner() {}

    QString username;
    QString role;
    int group_id;
};

#endif // PLANNER_H
