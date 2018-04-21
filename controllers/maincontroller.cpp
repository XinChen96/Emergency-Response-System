#include "maincontroller.h"
#include <iostream>

MainController::MainController() {
//dbPath = "/Users/chenxin/db.sqlite";
    dbPath = "../db/db.sqlite";
db_m = new User_DB(dbPath);
std::cout << "new userdb \n";
db_m->build_table();

std::cout << __PRETTY_FUNCTION__<<"\n";
}

MainController::~MainController() {
 std::cout << __PRETTY_FUNCTION__<<"\n";
delete db_m;
}

bool MainController::add_user(QString firstName,QString lastName,QString username) {

    DBItem *newCivilian = new Civilian(firstName,lastName,username);

    std::cout << firstName.toStdString()
         << "  "
         << lastName.toStdString()
         << "  "
         << username.toStdString()
         << std::endl;

    db_m->create_row(newCivilian);


    db_m->print();
std::cout << __PRETTY_FUNCTION__<<"\n";
    return true;
}


