#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H
<<<<<<< HEAD
#include "QtSql/QSqlDatabase"
#include "QtSql/QSqlQuery"
#include "../db/db_manager.h"
=======

>>>>>>> 3a18b025449d259385e369773772235841e5de4c
#include "../db/user_db.h"
#include "../db/db_manager.h"


class MainController
{
public:
    MainController();
    ~MainController();

<<<<<<< HEAD
    const QString db_location;
    bool add_user();
    //DB_Manager *db = nullptr;
=======
    bool add_user(QString,QString,QString);
private:
    QString db_location;
    DB_Manager *db;
>>>>>>> 3a18b025449d259385e369773772235841e5de4c
};

#endif // MAINCONTROLLER_H
