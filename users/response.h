#ifndef RESPONSE_H
#define RESPONSE_H
#include "dbitem.h"
#include "QString"

class Response : public DBItem
{
public:
    Response(int group, int emergency, QString response) : DBItem(-1), group_id(group), emergency_id(emergency), emergency_response(response) {}
    int group_id;
    int emergency_id;
    QString emergency_response;
};

#endif // RESPONSE_H
