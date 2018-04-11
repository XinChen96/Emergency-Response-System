#include "user_db.h"

void User_DB::generate_sql_queries() {
    create_cmd += "CREATE TABLE users (id integer PRIMARY KEY, firstName text NOT NULL, lastName text NOT NULL, username text NOT NULL UNIQUE, role text NOT NULL);";
    insert_cmd += "INSERT INTO users (firstName, lastName, username, role) VALUES (:firstName, :lastName, :username, :role);";

    // Todo: When you update, you need to be able to choose which values you are updating
    update_cmd += "UPDATE users SET firstName=:first, lastName=:last, role=:role, username=:username WHERE id=:id;";
    drop_cmd += "DROP TABLE IF EXISTS users;";
    query = nullptr;
}

// Should later be replaced by create_row(User& user)
void User_DB::create_row(QString first, QString last, QString username, QString role, int id) {
    query = new QSqlQuery(db);
    query->prepare(insert_cmd);
    query->bindValue(":firstName", first);
    query->bindValue(":lastName", last);
    query->bindValue(":username", username);
    query->bindValue(":role", role);
    //query->bindValue(":groupid", id);

    query->exec();

    delete query; // Delete pointer
}

void User_DB::update_value(QString first, QString last, QString username, QString role, int id) {
    query = new QSqlQuery(db);
    query->prepare(update_cmd);

    query->bindValue(":first", first);
    query->bindValue(":last", last);
    query->bindValue(":username", username);
    query->bindValue(":role", role);
    query->bindValue(":id", id);

    query->exec();

    delete query; // Delete pointer
}


