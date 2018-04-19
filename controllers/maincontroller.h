#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H
#include "QtSql/QSqlDatabase"
#include "QtSql/QSqlQuery"
#include "../db/db_manager.h"
#include "../db/user_db.h"

class MainController
{
public:
    MainController();
    ~MainController();

    const QString db_location;
    bool add_user();
    //DB_Manager *db = nullptr;
};

#endif // MAINCONTROLLER_H
