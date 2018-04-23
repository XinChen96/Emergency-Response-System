#ifndef EMERGENCY_H
#define EMERGENCY_H

#include "dbitem.h"
#include <QString>

class Emergency : public DBItem
{
public:

    Emergency(): DBItem(-1) {}

    Emergency(QString temp_name, QString temp_public_response) : DBItem(-1) {
        name = temp_name;
        public_response = temp_public_response;
    }

    QString name;
    QString public_response;
};

#endif // EMERGENCY_H
