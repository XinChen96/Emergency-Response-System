#ifndef RESPONDER_H
#define RESPONDER_H
#include "user.h"

class Responder: public User
{
public:
    Responder(QString first, QString last, QString user) : User(first, last, user, Role::responder) {}
   ~Responder() {}
};

#endif // RESPONDER_H
