#include "group_db.h"
#include "../users/responder.h"
#include <iostream>

using namespace std;

void Group_DB::generate_sql_queries() {
    create_cmd += "CREATE TABLE groups (id integer PRIMARY KEY, groupName text NOT NULL UNIQUE);";
    create_groups_cmd += "CREATE TABLE userGroups (id integer PRIMARY KEY, FOREIGN KEY(group_id) REFERENCES groups(id), FOREIGN KEY(user_id) REFERENCES users(id));";
    insert_cmd += "INSERT INTO groups (groupName) VALUES (:groupName);";

    update_cmd += "UPDATE users SET groupName=:groupName WHERE id=:id;";
    drop_cmd += "DROP TABLE IF EXISTS groups;";
    query = nullptr;
}

// Adds a new group to the
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

void Group_DB::create_group_table() {
    query = new QSqlQuery(db);
    query->exec(create_groups_cmd);
    delete query;
}

void Group_DB::add_to_group(User* user, Group* group) {
    if(user->id != -1 && group->id != -1) {
        query = new QSqlQuery(db);
        query->prepare("INSERT INTO userGroups (userId, groupId) VALUES(:user, :group);");
        query->bindValue(user->id, group->id);
        query->exec();
    } else {
        cerr << "ID from database has not yet been assigned.";
    }
}

vector<User*> Group_DB::get_group_members(Group* g) {
    vector<User*> user_list;
    query = new QSqlQuery(db);
    query->prepare("SELECT id, firstName, lastName, username, role FROM userGroup INNER JOIN users ON userGroup.user_id=users.id WHERE usersGroup.group_id=:id;");
    query->bindValue(":id", g->id);
    query->exec();
    User* user;
    while(query->next()) {
        user = new User(query->value(1).toString(), query->value(2).toString(),query->value(3).toString(), ((Role)query->value(4).toInt()));
        user->id = query->value(0).toInt();
        user_list.push_back(user);
        delete user;
    }

    return user_list;
}


