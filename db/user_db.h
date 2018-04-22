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
    void print();
    int get_role(QString);


    User* select_user(int);
    User* select_user(QString);
};

#endif // USER_DB_H
