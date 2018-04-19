#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H
#include "../db/user_db.h"

class MainController
{
public:
    MainController();
    ~MainController();

    QString db_location;
    bool add_user();
    //DB_Manager *db = nullptr;
};

#endif // MAINCONTROLLER_H
