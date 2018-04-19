#include "maincontroller.h"

MainController::MainController() {
db_location = "User_Database";
}

MainController::~MainController() {
    delete db;
}

bool MainController::add_user(QString firstName, QString lastName, QString username) {
    db = new User_DB(db_location);

    User *newuser = new Civilian(firstName,lastName,username,0);

    db->create_row(newuser);
    return true;
}
