#ifndef GROUP_DB_H
#define GROUP_DB_H
#include "db_manager.h"

class Group_DB : public DB_Manager {
public:
    Group_DB(const QString& path) : DB_Manager(path) { generate_sql_queries(); }
    ~Group_DB() {}
    // Later use polymorphism here, different types of User are implemented differently
    void create_row(DBItem&);
    void update_value(DBItem&);
    void generate_sql_queries();
};

#endif // GROUP_DB_H
