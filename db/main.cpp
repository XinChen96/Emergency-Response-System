#include <iostream>
#include "db_manager.h"
#include "user_db.h"
#include "group_db.h"

using namespace std;

int main() {
    DB_Manager *db;
    //User_DB user_db(QString("../db.sqlite"));
    Group_DB group_db(QString("../db.sqlite"));

    //db = &user_db;
    //db->build_table();
    //db->create_row(QString("Ben"), QString("Fuller"), QString("benfuller"), QString("firemen"), 1);

    db = &group_db;
    db->build_table();
    //db->create_row(QString("firemen"), 1);
    return 0;
}
