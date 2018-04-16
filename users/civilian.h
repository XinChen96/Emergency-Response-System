#ifndef CIVILIAN_H
#define CIVILIAN_H
#include "user.h"

class Civilian : public User {
public:
    Civilian(QString first, QString last, QString user, QString r, int id, int groupid) : User(first, last, user, id) {}
    ~Civilian() {}
};

#endif // CIVILIAN_H
