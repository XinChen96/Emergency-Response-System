#include "group_db.h"
#include "../users/responder.h"
#include <iostream>

void Group_DB::generate_sql_queries() {
    create_cmd += "CREATE TABLE groups (id integer PRIMARY KEY, groupName text NOT NULL);";
    insert_cmd += "INSERT INTO groups (groupName) VALUES (:groupName);";

    update_cmd += "UPDATE users SET groupName=:groupName WHERE id=:id;";
    drop_cmd += "DROP TABLE IF EXISTS groups;";
    query = nullptr;
}


// Todo: Create Group class
// Should later be replaced by create_row(Group& g)
//void Group_DB::create_row(Group& g) {
//    query = new QSqlQuery(db);
//    query->prepare(insert_cmd);
//    query->bindValue(":groupName", r.group_name);
//    query->exec();

//    delete query; // Delete pointer
//}

//void Group_DB::update_value(QString group, int id) {
//    query = new QSqlQuery(db);
//    query->prepare(update_cmd);

//    query->bindValue(":groupName", group);
//    query->bindValue(":id", id);

//    query->exec();

//    delete query; // Delete pointer
//}


