#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H
#include "QtSql/QSqlDatabase"
#include "QtSql/QSqlQuery"
#include "QString"
#include <iostream>
#include <vector>
#include <string>
#include "../db/user_db.h"
#include "../db/simulation_db.h"
#include "../db/db_manager.h"
#include "../users/roles.h"
#include "../users/civilian.h"
#include "../users/planner.h"
#include "../users/user.h"
#include "../users/simulation.h"
#include "../users/group.h"
#include "../db/group_db.h"
#include "../db/emergency_db.h"
#include "../users/emergency.h"


class MainController
{
public:
    MainController();
    MainController(QString path);
    ~MainController();

    bool add_user(QString,QString,QString,Role);
    bool add_simulation(Simulation*);
    QSqlDatabase get_db();
    Simulation* select_simulation(QString name);
    bool add_emergency(Emergency*);
    Emergency* select_emergency(QString name);
    void print_db();
    std::vector<Group*> get_groups();
    std::vector<QString> get_Sim_DBItems();
    void add_group(QString);
    std::vector<User*> get_civilians();
    std::vector<User*> get_responders();


    int check_role(QString);

private:


    QString dbPath;
    DB_Manager *db_m;


};

#endif // MAINCONTROLLER_H
