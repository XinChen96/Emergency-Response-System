#include "maincontroller.h"

MainController::MainController() {

db_location = "../db.sqlite";
//db = new User_DB(db_location);


//db = new DB_Manager(QString::fromStdString("../db.sqlite"));
}

MainController::~MainController() {
   // delete db;
}

bool MainController::add_user(QString firstName, QString lastName, QString username)
{
//db = new DB_Manager(db_location);

    //User *newuser = new Civilian(firstName,lastName,username);

    //db->create_row(newuser);
    //return true;
}
