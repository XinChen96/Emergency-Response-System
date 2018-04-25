#ifndef GROUP_DB_H
#define GROUP_DB_H
#include <vector>
#include "db_manager.h"
#include "../users/group.h"
#include "../users/user.h"

using namespace std;

class Group_DB : public DB_Manager {
public:
    Group_DB(const QString& path) : DB_Manager(path) {

        generate_sql_queries(); }
    ~Group_DB() {}

    bool create_groups_table();
    void add_to_group(User*, Group*);
    bool remove_from_group(int);
    bool delete_row(QString);

    void create_row(DBItem*);

    void update_value(DBItem*);
    void generate_sql_queries();
    int find_group(int);

    Group* select_group(int);
    Group* select_group(QString);
    vector<User*> get_group_members(Group*);
    vector<Group*> get_groups();

    QString create_groups_cmd;
    QString insert_groups_cmd;
    QString delete_groups_cmd;
};

#endif // GROUP_DB_H
