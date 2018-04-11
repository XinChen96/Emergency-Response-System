#include <iostream>
#include "db_manager.h"
#include "user_db.h"
#include "group_db.h"

using namespace std;

int main() {
    DB_Manager *db = new Group_DB("../db.sqlite");
    db->build_table();
    db->create_row(QString("firemen"));
    return 0;
}
