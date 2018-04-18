#ifndef PLANNER_H
#define PLANNER_H
#include "user.h"

class Planner: public User
{
public:
    Planner(QString first, QString last, QString user) : User(first, last, user, Role::planner) {}
    ~Planner() {}
};

#endif // PLANNER_H
