#ifndef DB_MANAGER_H
#define DB_MANAGER_H
#include "QString"
#include "QSqlDatabase"
#include "QSqlQuery"
#include "QVariant"
#include <iostream>

class DB_Manager {
public:
    DB_Manager(QString);
    DB_Manager() {}
    ~DB_Manager() {}
    void build_table();

    // Replaced with polymorphic methods when group and user classes are created
    virtual void create_row(QString, QString, QString, QString, int) {}
    virtual void update_value(QString, QString, QString, QString, int) {}
    virtual void update_value(QString, int) {}
    virtual void create_row(QString, int) {}
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
