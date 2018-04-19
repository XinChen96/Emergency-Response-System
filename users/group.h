#ifndef GROUP_H
#define GROUP_H
#include "dbitem.h"
#include "user.h"

class Group : public DBItem {
public:
    Group(QString n) : DBItem(-1), name(n) {}
    Group() : DBItem(-1) {}
    void add_to_group(User* user);
    QString name;
};

#endif // GROUP_H
