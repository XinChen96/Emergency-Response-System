#ifndef RESPONDER_H
#define RESPONDER_H
#include "user.h"

class Responder: public User
{
public:
    Responder(QString first, QString last, QString user, int groupid, QString group, int id) : User(first, last, user, id),
                                                                                                group_name(group), group_id(groupid){}
   ~Responder() {}
    QString group_name;
    int group_id;
};

#endif // RESPONDER_H
