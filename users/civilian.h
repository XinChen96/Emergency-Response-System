#ifndef CIVILIAN_H
#define CIVILIAN_H
#include "user.h"
#include "roles.h"

class Civilian : public User {
public:
    Civilian(QString first, QString last, QString user, int id) : User(first, last, user, Role::civilian, id) {}
    ~Civilian() {}
};

#endif // CIVILIAN_H
