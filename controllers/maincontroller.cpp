#include "maincontroller.h"
#include <iostream>

MainController::MainController() {
    db_location += "../db.sqlite";
}

MainController::~MainController() {
}

// Should return true if user is successfully added to the db, false otherwise
bool MainController::add_user(QString firstName, QString lastName,QString username) {
    db = new User_DB(db_location);
    User *newCivilian = new Civilian(firstName,lastName,username);

    db->create_row(newCivilian);
    //std::cout<<((User_DB*)db)->select_civilian("6666")->last_name.toStdString()<<std::endl;
    db->print();

    delete db;
    delete newCivilian; // make sure you delete your pointers after you're done using them
    return true;
}


