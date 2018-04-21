#include "maincontroller.h"
#include <iostream>

MainController::MainController() {

dbPath = "/Users/chenxin/db.sqlite";
   // dbPath = "../db/db.sqlite";
db_m = new User_DB(dbPath);
std::cout << "new userdb \n";
db_m->build_table();

std::cout << __PRETTY_FUNCTION__<<"\n";
}

MainController::~MainController() {

 std::cout << __PRETTY_FUNCTION__<<"\n";
delete db_m;
}




// Should return true if user is successfully added to the db, false otherwise
bool MainController::add_user(QString firstName, QString lastName,QString username) {
    db_m = new User_DB(dbPath);
    User *newCivilian = new Civilian(firstName,lastName,username);

    std::cout << firstName.toStdString()
         << "  "
         << lastName.toStdString()
         << "  "
         << username.toStdString()
         << std::endl;

    db_m->create_row(newCivilian);
    db_m->print();
    std::cout << __PRETTY_FUNCTION__<<"\n";


    delete newCivilian; // make sure you delete your pointers after you're done using them

    return true;
}


