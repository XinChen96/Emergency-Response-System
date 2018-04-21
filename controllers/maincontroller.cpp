#include "maincontroller.h"
#include <iostream>

MainController::MainController() {
    DB_Manager *db = new User_DB("../db.sqlite");
    db->build_table();
    delete db;
}

MainController::~MainController() {
    delete db;
}

bool MainController::add_user() {


    return true;
}


