#include "maincontroller.h"
#include <iostream>

MainController::MainController() {
   dbPath = "../db.sqlite";
  dbPath = "/Users/chenxin/db.sqlite";
}

MainController::~MainController() {

    std::cout << __PRETTY_FUNCTION__<<"\n";
    delete db_m;
}


// Should return true if user is successfully added to the db, false otherwise

bool MainController::add_user(QString firstName, QString lastName,QString username, Role role) {

    db_m = new User_DB(dbPath);

    //db_m->build_table();
    User* newUser;
    if(role == civilian){
        newUser = new Civilian(firstName,lastName,username);
    }else if (role == planner){
        newUser = new Planner(firstName,lastName,username);
    }else if (role == responder){
        newUser = new Responder(firstName,lastName,username);
    }

    std::cout << firstName.toStdString()
              << "  "
              << lastName.toStdString()
              << "  "
              << username.toStdString()
              << std::endl;

    db_m->create_row(newUser);
    db_m->print();

    delete newUser;
    delete db_m;
    return true;
}

bool MainController::add_simulation(Simulation* sim) {
    db_m = new Simulation_DB(dbPath);

    db_m->create_row(sim);
    //std::cout<<((User_DB*)db)->select_user("6666")->last_name.toStdString()<<std::endl;
    //db->print();

    delete db_m;
    return true;
}

Simulation* MainController::select_simulation(QString name) {
    db_m = new Simulation_DB(dbPath);

    Simulation* temp = ((Simulation_DB*)db_m)->select_simulation(name);

    delete db_m;
    return temp;
}

// Returns the users role if it exists, otherwise returns 3
int MainController::check_role(QString username) {
    db_m = new User_DB(dbPath);
    User *u = ((User_DB*)db_m)->select_user(username);
    if(u != nullptr) {
        std::cout<<"role_num"<< u->role_num<<std::endl;
        delete db_m;
        return u->role_num;

    } else {
        delete db_m;
        return 3;
    }
}

// Return a list of all the current groups
std::vector<Group*> MainController::get_groups() {
    db_m = new Group_DB(dbPath);
    return ((Group_DB*)db_m)->get_groups();
}



