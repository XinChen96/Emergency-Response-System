#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H
#include "QtSql/QSqlDatabase"
#include "QtSql/QSqlQuery"
#include "QString"
#include <iostream>
#include <string>
#include "../db/user_db.h"
#include "../db/db_manager.h"
#include "../users/civilian.h"
#include "../users/user.h"
class MainController
{
public:
    MainController();
    ~MainController();

    bool add_user(QString,QString,QString);
    void print_db();
private:

    QString db_location;
    DB_Manager *db;
};

#endif // MAINCONTROLLER_H
