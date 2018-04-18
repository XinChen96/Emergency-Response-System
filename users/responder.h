#ifndef RESPONDER_H
#define RESPONDER_H
#include "user.h"

class Responder: public User
{
public:
    Responder(QString first, QString last, QString user, int groupid, QString group) : User(first, last, user, Role::responder), group_name(group), group_id(groupid) {}
   ~Responder() {}
    QString group_name;
    int group_id;
};

#endif // RESPONDER_H
