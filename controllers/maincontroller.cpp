#include "maincontroller.h"
#include <iostream>

MainController::MainController() {
   dbPath = "../db.sqlite";

   //dbPath = "/Users/chenxin/db.sqlite";

}

MainController::~MainController() {

    std::cout << __PRETTY_FUNCTION__<<"\n";
    delete db_m;
}

QSqlDatabase MainController::get_db(){
    db_m = new User_DB(dbPath);
    return db_m->get_db();
}
// Should return true if user is successfully added to the db, false otherwise

bool MainController::add_user(QString firstName, QString lastName,QString username, Role role) {

    std::cout << firstName.toStdString()
              << "  "
              << lastName.toStdString()
              << "  "
              << username.toStdString()
              << std::endl;

    db_m = new User_DB(dbPath);
    db_m->create_table();

    User* newUser;


    if(role == civilian){
        newUser = new Civilian(firstName,lastName,username);
        db_m->create_row(newUser);
        db_m->print();
        delete newUser;
        delete db_m;
        return true;

    }else if (role == planner){

        newUser = new Planner(firstName,lastName,username);
        db_m->create_row(newUser);
        db_m->print();
        delete newUser;
        delete db_m;
        return true;
    }else if (role == responder){

        newUser = new Responder(firstName,lastName,username);
        db_m->create_row(newUser);
        db_m->print();
        delete newUser;
        delete db_m;
        return true;
    }else{


        db_m->print();
        //delete newUser;
        delete db_m;
        return false;
    }






}

//adds a simulation to the database
bool MainController::add_simulation(Simulation* sim) {
    db_m = new Simulation_DB(dbPath);
    db_m->create_table();

    db_m->create_row(sim);
    //std::cout<<((User_DB*)db)->select_user("6666")->last_name.toStdString()<<std::endl;
    //db->print();

    delete db_m;
    return true;
}

//gets a simulation from the database
Simulation* MainController::select_simulation(QString name) {
    db_m = new Simulation_DB(dbPath);

    Simulation* temp = ((Simulation_DB*)db_m)->select_simulation(name);

    delete db_m;
    return temp;
}

//gets all simulation item names currentcly in the database
std::vector<QString> MainController::get_Sim_DBItems() {
    db_m = new Simulation_DB(dbPath);

    std::vector<QString> temp = ((Simulation_DB*)db_m)->get_DBItems();

    delete db_m;
    return temp;
}

//adds in an emergency item to the database
bool MainController::add_emergency(Emergency* em) {
    db_m = new Emergency_DB(dbPath);
    db_m->create_table();

    db_m->create_row(em);
    //std::cout<<((User_DB*)db)->select_user("6666")->last_name.toStdString()<<std::endl;
    //db->print();

    delete db_m;
    return true;
}

//gets an emergency item from the database
Emergency* MainController::select_emergency(QString name) {
    db_m = new Emergency_DB(dbPath);

    Emergency* temp = ((Emergency_DB*)db_m)->select_emergency(name);

    delete db_m;
    return temp;
}

//gets an emergency item from the database
Emergency* MainController::select_emergency(int id) {
    db_m = new Emergency_DB(dbPath);

    Emergency* temp = ((Emergency_DB*)db_m)->select_emergency(id);

    delete db_m;
    return temp;
}

//gets all emergency item names from the database
std::vector<QString> MainController::get_Em_DBItems() {
    db_m = new Emergency_DB(dbPath);

    std::vector<QString> temp = ((Emergency_DB*)db_m)->get_DBItems();

    delete db_m;
    return temp;
}

// Returns the users role if it exists, otherwise returns 3
int MainController::check_role(QString username) {
    db_m = new User_DB(dbPath);
    User *u = ((User_DB*)db_m)->select_user(username);
    if(u != nullptr) {
        std::cout<<"check_role: returned role_num is "<< u->role_num<<std::endl;
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
    delete db_m;
}

// Add a group to the db
void MainController::add_group(QString group_name) {
    db_m = new Group_DB(dbPath);
    DBItem* g = new Group(group_name);
    db_m->create_row(g);
}

// Get a list of all the civilians
std::vector<User*> MainController::get_civilians() {
    db_m = new User_DB(dbPath);
    return ((User_DB*)db_m)->get_civilians();
}

// Get a list of all the responders
std::vector<User*> MainController::get_responders() {
    db_m = new User_DB(dbPath);
    return ((User_DB*)db_m)->get_responders();
}

Group* MainController::select_group(QString name) {
    db_m = new Group_DB(dbPath);

    Group* temp = ((Group_DB*)db_m)->select_group(name);

    delete db_m;
    return temp;
}

//adds in an emergency item to the database
bool MainController::add_response(Response* resp) {
    db_m = new Response_DB(dbPath);
    db_m->create_table();

    db_m->create_row(resp);
    //std::cout<<((User_DB*)db)->select_user("6666")->last_name.toStdString()<<std::endl;
    //db->print();

    delete db_m;
    return true;
}



