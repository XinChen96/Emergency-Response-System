#ifndef USER_DB_H
#define USER_DB_H
#include "db_manager.h"

class User_DB : public DB_Manager {
public:
    User_DB(const QString& path) : DB_Manager(path) {
        generate_sql_queries();
    }

    ~User_DB() {}
    void create_row(DBItem*);
    void update_value(DBItem*);
    void generate_sql_queries();

    User* select_civilian(int);
    User* select_civilian(QString);
};

#endif // USER_DB_H
