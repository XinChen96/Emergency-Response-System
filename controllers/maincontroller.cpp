#include "maincontroller.h"

MainController::MainController(QString path) {

    // I don't think that we should declare the db up here, it should be instantiated every time it is needed
    // The db and tables should be created during installation, and shouldn't be recreated every time the program runs
    //db_m = new User_DB(dbPath);
    // This should be the same as the query variable in the db classes

    std::cout << "new userdb \n";

    // For now, we should manually create the table instead of using build_table() bc build_table deletes the old version
    //db_m->build_table();
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


