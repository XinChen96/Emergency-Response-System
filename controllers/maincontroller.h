#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include "../db/user_db.h"
#include "../db/db_manager.h"


class MainController
{
public:
    MainController();
    ~MainController();

    bool add_user(QString,QString,QString);
private:
    QString db_location;
    DB_Manager *db;
};

#endif // MAINCONTROLLER_H
