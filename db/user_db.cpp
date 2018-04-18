#include "user_db.h"
#include <iostream>

using namespace std;

void User_DB::generate_sql_queries() {
    create_cmd += "CREATE TABLE users (id integer PRIMARY KEY, firstName text NOT NULL, lastName text NOT NULL, username text NOT NULL UNIQUE);";
    insert_cmd += "INSERT INTO users (firstName, lastName, username) VALUES (:firstName, :lastName, :username);";

    // Todo: When you update, you need to be able to choose which values you are updating
    update_cmd += "UPDATE users SET firstName=:first, lastName=:last, role=:role, username=:username WHERE id=:id;";
    drop_cmd += "DROP TABLE IF EXISTS users;";
    query = nullptr;
}

void User_DB::create_row(DBItem* u) {
    User *user = (User*)(u);

    query = new QSqlQuery(db);

    query->prepare(insert_cmd);
    query->bindValue(":firstName", user->first_name);
    query->bindValue(":lastName", user->last_name);
    query->bindValue(":username", user->username);

    query->exec();

    delete query;
    delete user;
}

void User_DB::update_value(DBItem* u) {
    User *user = (User*)(u);
    query = new QSqlQuery(db);
    query->prepare(update_cmd);

    query->bindValue(":first", user->first_name);
    query->bindValue(":last", user->last_name);
    query->bindValue(":username", user->username);
    query->bindValue(":id", user->id);

    query->exec();

    delete query;
    delete user;
}

User* User_DB::select_civilian(int id) {
    User *user;
    query = new QSqlQuery(db);
    query->prepare("SELECT DISTINCT FROM users WHERE id=:id");
    query->bindValue(":id", id);

    user = new Civilian(query->value(1).toString(), query->value(2).toString(), query->value(3).toString(), query->value(0).toInt());
    return user;
}


