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
#include "../db/notification_db.h"
#include "../db/instructions_db.h"
#include "../users/instruction.h"
#include "server.h"
#include "client.h"
#include <QMutex>


class MainController {
public:
    //MainController() : dbPath("../db.sqlite") {}
    MainController() : dbPath("/mnt/cs205/db.sqlite") {} //Ben's db path
    //MainController() : dbPath("/Users/chenxin/db.sqlite") {} //Chen's db path
    //MainController() : dbPath("/Volumes/cs205/db.sqlite") {} //Chen's db path
    //MainController() : dbPath("/mnt/205_Database/db.sqlite") {} //Joe's db path

    ~MainController();

    bool add_user(QString,QString,QString,Role);
    void add_to_group(QString,QString);
    bool add_simulation(Simulation*);
    bool delete_row(db_table,QString);
    QSqlDatabase get_DB(db_table);

    User*   select_user(QString);
    Simulation* select_simulation(QString name);
    Simulation* select_simulation(int id);
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
    Group* select_group(int id);
    bool add_response(Response*);
    Response* select_response(Emergency* em, Group* gr);
    std::vector<int> get_resp_em_DBItems(int value);
    bool add_notification(Notification*);
    Notification* select_notification_id(int value);
    bool remove_notification(int value);
    void start_server();
    void start_client();
    void get_notification();
    std::vector<int> get_noti_sim_DBItems();
    std::vector<Group*> get_user_groups(int);
    int get_user_id(QString);
    void update_instructions(int);
    int check_role(QString);
    void add_instruction(QString, int);
    int get_group_id(QString);
    int find_group(int);
    bool update_response(Response*);

private:

    Client *c = nullptr;
    Server *s = nullptr;
    QString dbPath;
    DB_Manager *db_m;


};

#endif // MAINCONTROLLER_H
