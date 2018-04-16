#ifndef PLANNER_H
#define PLANNER_H
#include "user.h"

class Planner: public User
{
public:
    Planner(QString first, QString last, QString user, QString r, int id) : User(first, last, user, id) {}
    ~Planner() {}
};

#endif // PLANNER_H
