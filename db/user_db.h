#ifndef USER_DB_H
#define USER_DB_H
#include "db_manager.h"

class User_DB : public DB_Manager {
public:
    User_DB(const QString& path) : DB_Manager(path) { generate_sql_queries(); }
    ~User_DB() {}
    // Later use polymorphism here, different types of User are implemented differently
    void create_row(QString, QString, QString, QString, int);
    void update_value(QString, QString, QString, QString, int);
    void generate_sql_queries();
};

#endif // USER_DB_H
