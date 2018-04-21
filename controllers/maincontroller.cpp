#include "maincontroller.h"




MainController::MainController() {


//dbPath = "../db/db.sqlite";
//db_m = new User_DB(dbPath);
std::cout << "Maincontroller: new userdb \n";
//db_m->build_table();
std::cout << "Maincontroller: build table \n";
}

MainController::MainController(QString path) {


// I don't think that we should declare the db up here, it should be instantiated every time it is needed
// The db and tables should be created during installation, and shouldn't be recreated every time the program runs
//db_m = new User_DB(path);

// This should be the same as the query variable in the db classes
std::cout << "Maincontroller: new userdb \n";
//
//For now, we should manually create the table instead of using build_table() bc build_table deletes the old version
//db_m->build_table();

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

    delete newCivilian; // make sure you delete your pointers after you're done using them

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

// Returns true if the username is in the db
bool MainController::check_login(QString username) {
    db_m = new User_DB(dbPath);
    User *u = ((User_DB*)db_m)->select_user(username);
    if(u != nullptr) {
        switch(u->role): {
            // Not all of these pages are made yet, but when they are, different people should see different things
        }
    }
}


