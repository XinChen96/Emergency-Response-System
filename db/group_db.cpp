#include "group_db.h"
#include "../users/responder.h"
#include <iostream>

using namespace std;

void Group_DB::generate_sql_queries() {
    create_cmd += "CREATE TABLE groups (id integer PRIMARY KEY, groupName text NOT NULL UNIQUE);";
    insert_cmd += "INSERT INTO groups (groupName) VALUES (:groupName);";

    update_cmd += "UPDATE users SET groupName=:groupName WHERE id=:id;";
    drop_cmd += "DROP TABLE IF EXISTS groups;";
    query = nullptr;
}


void Group_DB::create_row(DBItem* g) {
    Group *group = (Group*)(g);

    query = new QSqlQuery(db);
    query->prepare(insert_cmd);
    query->bindValue(":groupName", group->name);
    query->exec();

    delete query; // Delete pointer
    delete group;
}

void Group_DB::update_value(DBItem* g) {
    Group *group = (Group*)(g);

    query = new QSqlQuery(db);
    query->prepare(update_cmd);
    query->bindValue(":groupName", group->name);
    query->bindValue(":id", group->id);

    query->exec();

    delete query; // Delete pointer
    delete group;
}

Group* Group_DB::select_group(int id) {
    Group* group;
    query = new QSqlQuery(db);
    query->prepare("SELECT DISTINCT * FROM groups WHERE id=:id");
    query->bindValue(":id", id);
    query->exec();

    if(query->next()) {
        group = new Group(query->value(1).toString());
        delete query;
        return group;
    } else {
        cerr << "Entry does not exist." << endl;
        delete query;
        return nullptr;
    }
}

Group* Group_DB::select_group(QString name) {
    Group* group;
    query = new QSqlQuery(db);
    query->prepare("SELECT DISTINCT * FROM groups WHERE groupName=:name");
    query->bindValue(":name", name);
    query->exec();

    if(query->next()) {
        group = new Group(query->value(1).toString());
        group->id = query->value(1).toInt();
        delete query;
        return group;
    } else {
        cerr << "Entry does not exist." << endl;
        delete query;
        return nullptr;
    }
}
