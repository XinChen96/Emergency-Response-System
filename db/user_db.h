#ifndef USER_DB_H
#define USER_DB_H
#include <vector>
#include "db_manager.h"

class User_DB : public DB_Manager {
public:
    User_DB(const QString& path) : DB_Manager(path) {
        generate_sql_queries();
    }

    ~User_DB() {}
    void create_row(DBItem*);
    void update_value(DBItem*);
    void delete_user(QString);
    void generate_sql_queries();
    void print();
    int get_role(QString);


    User* select_user(int);
    User* select_user(QString);
    std::vector<User*> get_civilians();
    std::vector<User*> get_responders();
};

#endif // USER_DB_H
