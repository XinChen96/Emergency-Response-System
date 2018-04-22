#ifndef DB_MANAGER_H
#define DB_MANAGER_H
#include "QtSql/QSqlDatabase"
#include "QtSql/QSqlQuery"
#include "QVariant"
#include <QDebug>
#include <QSqlError>
#include <iostream>
#include "../users/user.h"
#include "../users/civilian.h"
#include "../users/dbitem.h"
#include "../users/responder.h"
#include "../users/planner.h"
#include "../users/simulation.h"
#include "../users/emergency.h"

#include "QString"

#include <string>


class DB_Manager {
public:
    DB_Manager(const QString&);
    virtual ~DB_Manager() { db.close();
                          std::cout << __PRETTY_FUNCTION__<<"\n";
                          }

    void build_table();

    virtual void create_row(DBItem*) {}
    virtual void update_value(DBItem*) {}
    virtual void generate_sql_queries() {}
    virtual void print(){}


    QSqlDatabase database(){
        return db;
    }

protected:
    QString create_cmd;
    QString insert_cmd;
    QString update_cmd;
    QString drop_cmd;

    QSqlQuery *query;

    QSqlDatabase db;
};

#endif // DB_MANAGER_H
