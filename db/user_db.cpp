#include "user_db.h"
#include <iostream>
#include <unistd.h>

using namespace std;

void User_DB::generate_sql_queries() {
    create_cmd += "CREATE TABLE users (id integer PRIMARY KEY, firstName text NOT NULL, lastName text NOT NULL, username text NOT NULL UNIQUE, role integer NOT NULL);";
    insert_cmd += "INSERT INTO users (firstName, lastName, username, role) VALUES (:firstName, :lastName, :username, :role);";

    // Todo: When you update, you need to be able to choose which values you are updating
    update_cmd += "UPDATE users SET firstName=:firstName, lastName=:lastName, username=:username, role=:role;"; // WHERE id=:id;";
    drop_cmd += "DROP TABLE IF EXISTS users;";
    query = nullptr;
}

void User_DB::create_row(DBItem* u) {
    User *user = (User*)(u);

    query = new QSqlQuery(db);

    if(query->prepare(insert_cmd)){
        cout << "create_row:queryPrepare" <<endl;
    }else{
        cerr<< "create_row:queryPrepare failed"<<endl;
        qDebug() << query->lastError();
    }
    query->bindValue(":firstName", user->first_name);
    query->bindValue(":lastName", user->last_name);
    query->bindValue(":username", user->username);
    query->bindValue(":role", user->role);


    if(query->exec()){
        cout << "create row" <<endl;
    }else{
        cerr<< "create row failed"<<endl;
    }
    std::cout << __PRETTY_FUNCTION__<<"\n";

    delete query;
}

void User_DB::update_value(DBItem* u) {
    User *user = (User*)(u);
    query = new QSqlQuery(db);
    query->prepare(update_cmd);

    query->bindValue(":firstName",user->first_name);
    query->bindValue(":lastName", user->last_name);
    query->bindValue(":username", user->username);
    query->bindValue(":role", user->role);

    query->exec();

    delete query;
    //delete user;
}
void User_DB::print(){

    query = new QSqlQuery(db);

    query->exec("SELECT * FROM users;");


    while (query->next()) {
        QString first = query->value(1).toString();
        QString last  = query->value(2).toString();
        QString user  = query->value(3).toString();

        cout << first.toStdString()
             << "  "
             << last.toStdString()
             << "  "
             << user.toStdString()
             << endl;
    }

    query->last();
    delete query;
}
User* User_DB::select_user(int id) {
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

User* User_DB::select_user(QString username) {
    User* user;
    Role role;
    query = new QSqlQuery(db);
    query->prepare("SELECT DISTINCT * FROM users WHERE username=:user");
    query->bindValue(":user", username);
    //query->exec();
    if(query->exec()){
        cout << "select row" <<endl;
    }else{
        cerr<< "select row failed"<<endl;
        qDebug() << query->lastError();
    }
        cout << username.toStdString()
             << endl;

//    if(query->next()) {

//        QString first = query->value(1).toString();
//        QString last  = query->value(2).toString();
//        QString user2  = query->value(3).toString();
//        cout << first.toStdString()
//             << "  "
//             << last.toStdString()
//             << "  "
//             << user2.toStdString()
//             << endl;
//

//        user = new Civilian(query->value(1).toString(), query->value(2).toString(), query->value(3).toString());
//        user->id = query->value(0).toInt();
//        delete query;
//        return user;
//    } else {
//        cerr << "Entry does not exist." << endl;
//        delete query;
//        return nullptr;
//    }

//}
////    qDebug() << query->lastError();
////    qDebug() << query->value(4);

//    if(query->value(4).toString() == "Civilian"){
//        role = civilian;
//    }else if (query->value(4).toString() == "Emergency Planner"){
//        role = planner;
//    }else if (query->value(4).toString() == "First Responder"){
//        role = responder;
//    }else{
//        role = NA;
//    }

    if(query->next()) {

    switch (get_role(query->value(4).toString())) {
        case 0:
            user = new Civilian(query->value(1).toString(), query->value(2).toString(), query->value(3).toString());
            user->id = query->value(0).toInt();
            break;
        case 1:
            user = new Responder(query->value(1).toString(), query->value(2).toString(), query->value(3).toString());
            user->id = query->value(0).toInt();
            break;
        case 2:
            user = new Planner(query->value(1).toString(), query->value(2).toString(), query->value(3).toString());
            user->id = query->value(0).toInt();
            break;
        }
        delete query;

        return user;
    } else {

        std::cerr << "Entry does not exist." << std::endl;
        delete query;
        return nullptr;
    }
}
    int User_DB::get_role(QString role_str){
            Role role;
            if(role_str == "Civilian"){
                role = civilian;
            }else if (role_str == "Emergency Planner"){
                role = planner;
            }else if (role_str == "First Responder"){
                role = responder;
            }else{
                role = NA;
            }
        return role;
    }


