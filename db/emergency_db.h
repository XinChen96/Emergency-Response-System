#ifndef EMERGENCY_DB_H
#define EMERGENCY_DB_H

#include "db_manager.h"

class Emergency_DB : public DB_Manager {
public:
    Emergency_DB(const QString& path) : DB_Manager(path) {
        tableName = "emergencies";
        generate_sql_queries(); }

    ~Emergency_DB() {}
    void create_row(DBItem*);
    void update_value(DBItem*);
    void generate_sql_queries();

    //selection methods
    Emergency* select_emergency(QString);
    Emergency* select_emergency(int);

    std::vector<QString> get_DBItems();
};

#endif // EMERGENCY_DB_H
