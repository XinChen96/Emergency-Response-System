#ifndef DB_MANAGER_H
#define DB_MANAGER_H
#include "QtSql/QSqlDatabase"
#include "QtSql/QSqlQuery"
#include "QVariant"
#include <iostream>
#include "../users/user.h"
#include "../users/civilian.h"
#include "../users/dbitem.h"

class DB_Manager {
public:
    DB_Manager(const QString&);
    DB_Manager() {}
    ~DB_Manager() { db.close(); }
    void build_table();

    virtual void create_row(DBItem*) {}
    virtual void update_value(DBItem*) {}
    virtual void generate_sql_queries() {}

protected:
    QString create_cmd;
    QString insert_cmd;
    QString update_cmd;
    QString drop_cmd;

    QSqlQuery *query;

    QSqlDatabase db;
};

#endif // DB_MANAGER_H
