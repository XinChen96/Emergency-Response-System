#include "maincontroller.h"


MainController::MainController(QString path) {

//dbPath = "/Users/chenxin/db.sqlite";
 dbPath = "../db/db.sqlite";
db_m = new User_DB(path);
std::cout << "Maincontroller: new userdb \n";
db_m->build_table();
std::cout << "Maincontroller: build table \n";
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


    //delete newCivilian; // make sure you delete your pointers after you're done using them

    return true;
}


