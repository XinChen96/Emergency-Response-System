#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H
#include "QtSql/QSqlDatabase"
#include "QtSql/QSqlQuery"
#include "../db/user_db.h"
#include "../db/db_manager.h"

class MainController
{
public:
    MainController();
    ~MainController();

    const QString db_location;
    bool add_user();
    //DB_Manager *db = nullptr;
    bool add_user(QString,QString,QString);
private:
    //QString db_location;
    DB_Manager *db;
};

#endif // MAINCONTROLLER_H
