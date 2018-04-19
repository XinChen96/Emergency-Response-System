#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H
#include "../db/db_manager.h"
#include "../db/user_db.h"
#include "../users/user.h"
#include "../users/civilian.h"
#include "../users/dbitem.h"


class MainController
{
public:
    MainController();
    ~MainController();

    DB_Manager *db;
    bool add_user(QString,QString,QString);
    QString db_location;

};

#endif // MAINCONTROLLER_H
