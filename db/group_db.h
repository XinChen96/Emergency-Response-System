#ifndef GROUP_DB_H
#define GROUP_DB_H
#include "db_manager.h"
#include "../users/group.h"
#include "../users/user.h"

class Group_DB : public DB_Manager {
public:
    Group_DB(const QString& path) : DB_Manager(path) { generate_sql_queries(); }
    ~Group_DB() {}

    void create_group_table();
    void add_to_group(User*, Group*);


    void create_row(DBItem*);
    void update_value(DBItem*);
    void generate_sql_queries();

    Group* select_group(int);
    Group* select_group(QString);

    QString create_groups_cmd;
};

#endif // GROUP_DB_H
