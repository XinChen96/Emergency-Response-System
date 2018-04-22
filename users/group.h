#ifndef GROUP_H
#define GROUP_H
#include "dbitem.h"
#include "user.h"

class Group : public DBItem {
public:
    Group(QString n) : DBItem(-1), name(n) {}
    Group(QString n, QString d) : DBItem(-1), name(n), date(d) {}
    Group() : DBItem(-1) {}
    QString name;
    QString date;
};

#endif // GROUP_H
