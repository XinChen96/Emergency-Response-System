#ifndef NOTIFICATION_DB_H
#define NOTIFICATION_DB_H

#include "db_manager.h"
#include <vector>

class Notification_DB : public DB_Manager {
public:
    Notification_DB(const QString& path) : DB_Manager(path) {
        tableName = "notifications";
        generate_sql_queries(); }

    ~Notification_DB() {}
    void create_row(DBItem*);
    bool delete_row(int);
    void update_value(DBItem*);
    void generate_sql_queries();

    //selection methods
    Notification* select_simulation_id(int sim_id);
};

#endif // NOTIFICATION_DB_H
