#include "maincontroller.h"
#include <iostream>

MainController::MainController() {
    //db_location += "../db.sqlite";
}

MainController::~MainController() {
}

bool MainController::add_user() {
    DB_Manager *db = new User_DB("../db.sqlite");
}
