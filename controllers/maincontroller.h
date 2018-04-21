#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H
#include "QtSql/QSqlDatabase"
#include "QtSql/QSqlQuery"
#include "QString"
#include <iostream>
#include <string>
#include "../db/user_db.h"
#include "../db/simulation_db.h"
#include "../db/db_manager.h"
#include "../users/civilian.h"
#include "../users/user.h"
#include "../users/simulation.h"


class MainController
{
public:
    MainController();
    MainController(QString path);
    ~MainController();

    bool add_user(QString,QString,QString);
    bool add_simulation(Simulation*);
    Simulation* select_simulation(QString name);
    void print_db();


    int check_login(QString);

private:


    QString dbPath;
    DB_Manager *db_m;


};

#endif // MAINCONTROLLER_H
