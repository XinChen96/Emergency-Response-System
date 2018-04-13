#ifndef RESPONDER_H
#define RESPONDER_H
#include "user.h"

class Responder: public User
{
public:
    Responder(QString first, QString last, QString user, QString r, int id, int groupid) : User(first, last, id), username(user), role(r), group_id(groupid) {}
   ~Responder() {}

    QString username;
    QString role;
              int group_id;
};

#endif // RESPONDER_H
