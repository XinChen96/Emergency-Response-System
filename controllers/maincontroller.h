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
#include "../users/simulation.h"
#include "../db/simulation_db.h"

class MainController
{
public:
    MainController();
    ~MainController();

    bool add_user(QString,QString,QString);
    bool add_simulation(Simulation* sim);
    void print_db();

private:

    QString db_location;
    DB_Manager *db;
};

#endif // MAINCONTROLLER_H
