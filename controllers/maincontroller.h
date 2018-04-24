#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H
#include "QtSql/QSqlDatabase"
#include "QtSql/QSqlQuery"
#include "QString"
#include <iostream>
#include <vector>
#include <string>
#include "db_table.h"
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
#include "../users/response.h"
#include "../db/response_db.h"


class MainController
{
public:
    MainController();
    MainController(QString path);
    ~MainController();

    bool add_user(QString,QString,QString,Role);
    bool add_simulation(Simulation*);
    QSqlDatabase get_DB(db_table);
    void delete_user(QString);
    User*   select_user(QString);
    Simulation* select_simulation(QString name);
    bool add_emergency(Emergency*);
    Emergency* select_emergency(QString name);
    Emergency* select_emergency(int id);
    void print_db();
    std::vector<Group*> get_groups();
    std::vector<QString> get_Sim_DBItems();
    std::vector<QString> get_Em_DBItems();
    void add_group(QString);
    std::vector<User*> get_civilians();
    std::vector<User*> get_responders();
    Group* select_group(QString name);
    bool add_response(Response*);
    Response* select_response(Emergency* em, Group* gr);


    int check_role(QString);

private:


    QString dbPath;
    DB_Manager *db_m;


};

#endif // MAINCONTROLLER_H
