#include "user_db.h"
#include <iostream>
#include <unistd.h>

void User_DB::generate_sql_queries() {
    create_cmd += "CREATE TABLE users (id integer PRIMARY KEY, firstName text NOT NULL, lastName text NOT NULL, username text NOT NULL UNIQUE);";
    insert_cmd += "INSERT INTO users (firstName, lastName, username) VALUES (:firstName, :lastName, :username);";

    // Todo: When you update, you need to be able to choose which values you are updating
    update_cmd += "UPDATE users SET firstName=:firstName, lastName=:lastName, username=:username;"; // WHERE id=:id;";
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
    std::cout << "create row" << std::endl;


    delete query;
    delete user;
}

void User_DB::update_value(DBItem* u) {
    User *user = (User*)(u);
    query = new QSqlQuery(db);
    query->prepare(update_cmd);

    query->bindValue(":firstName", user->first_name);
    query->bindValue(":lastName", user->last_name);
    query->bindValue(":username", user->username);
//    query->bindValue(":id", user->id);

    query->exec();

    delete query;
    delete user;
}
void User_DB::print(){
    query = new QSqlQuery(db);
    query->first();
    query->exec("SELECT * FROM users;");

    while (1) {
    sleep(5);
        QString first;// = query->value(0).toString();
        std::cout << "first name" << std::endl;
        QString last  = query->value(1).toString();
        QString user  = query->value(2).toString();
        query->bindValue(":firstName", first);
        //query->bindValue(":lastName", user->last_name);
        //query->bindValue(":username", user->username);
        std::cout << first.toStdString()
                  << "  "
                  << last.toStdString()
                  << "  "
                  << user.toStdString()
                  << std::endl;
        std::cout << "WHILe" << std::endl;
    }

    query->last();
    delete query;
}
User* User_DB::select_civilian(int id) {
    User *user;
    query = new QSqlQuery(db);
    query->prepare("SELECT DISTINCT * FROM users WHERE id=:id");
    query->bindValue(":id", id);
    query->exec();
    if(query->size() != -1) {
        user = new Civilian(query->value(1).toString(), query->value(2).toString(), query->value(3).toString());
        delete query;
        return user;
    } else {
        std::cerr << "Entry does not exist." << std::endl;
        delete query;
        return nullptr;
    }
}

User* User_DB::select_civilian(QString username) {
    User *user;
    query = new QSqlQuery(db);
    query->prepare("SELECT DISTINCT * FROM users WHERE username=:user");
    query->bindValue(":user", username);
    query->exec();

    if(query->next()) {
        user = new Civilian(query->value(1).toString(), query->value(2).toString(), query->value(3).toString());
        user->id = query->value(0).toInt();
        delete query;

        return user;
    } else {
        std::cerr << "Entry does not exist." << std::endl;
        delete query;
        return nullptr;
    }
}

