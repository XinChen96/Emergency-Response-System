#include "maincontroller.h"




MainController::MainController() {


    dbPath = "../db.sqlite";
    //db_m = new User_DB(dbPath);
    //std::cout << "Maincontroller: new userdb \n";
    //db_m->build_table();
    //std::cout << "Maincontroller: build table \n";
}

MainController::~MainController() {

    std::cout << __PRETTY_FUNCTION__<<"\n";
    delete db_m;
}


// Should return true if user is successfully added to the db, false otherwise
bool MainController::add_user(QString firstName, QString lastName,QString username, Role role) {

    db_m = new User_DB("../db.sqlite");

    //db_m->build_table();
    User* newUser;
    if(role == civilian){
        newUser = new Civilian(firstName,lastName,username);
    }else if (role == planner){
        newUser = new Planner(firstName,lastName,username);
    }else{
        newUser = new User(firstName,lastName,username,NA);
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
    //std::cout<<((User_DB*)db)->select_civilian("6666")->last_name.toStdString()<<std::endl;
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


