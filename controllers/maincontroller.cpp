#include "maincontroller.h"
#include <iostream>

MainController::MainController() {
    dbPath = "../db.sqlite";


    //dbPath = "/Users/chenxin/db.sqlite"; // this is for Chen's laptop
    std::cout << "MainController constructor" <<std::endl;
}

MainController::~MainController() {

    std::cout << __PRETTY_FUNCTION__<<"\n";
    delete db_m;
    delete s;
    delete c;
}

QSqlDatabase MainController::get_DB(db_table table){
    switch(table){
    case 0:
        db_m = new User_DB(dbPath);
        return db_m->get_db();
        break;
    case 1:
        db_m = new Group_DB(dbPath);
        return db_m->get_db();
        break;
    case 2:
        db_m = new Response_DB(dbPath);
        return db_m->get_db();
        break;
    case 3:
        db_m = new Simulation_DB(dbPath);
        return db_m->get_db();
        break;
    case 4:
        db_m = new Emergency_DB(dbPath);
        return db_m->get_db();
        break;

    }

}



// Should return true if user is successfully added to the db, false otherwise

bool MainController::add_user(QString firstName, QString lastName,QString username, Role role) {

    db_m = new User_DB(dbPath);
    db_m->create_table();

    User* newUser;

    switch(role){
    case civilian:
        newUser = new Civilian(firstName,lastName,username);
        db_m->create_row(newUser);
        db_m->print();
        delete newUser;
        delete db_m;
        return true;
        break;
    case planner:
        newUser = new Planner(firstName,lastName,username);
        db_m->create_row(newUser);
        db_m->print();
        delete newUser;
        delete db_m;
        return true;
        break;
    case responder:
        newUser = new Responder(firstName,lastName,username);
        db_m->create_row(newUser);
        db_m->print();
        delete newUser;
        delete db_m;
        return true;
        break;
    default:
        db_m->print();
        //delete newUser;
        delete db_m;
        return false;
    }

}

void MainController::add_to_group(QString groupID, QString userID){
    db_m = new Group_DB(dbPath);

   ((Group_DB*)db_m)->create_groups_table();

    Group* group = ((Group_DB*)db_m)->select_group(groupID);
    User* user = ((User_DB*)db_m)->select_user(userID);

    ((Group_DB*)db_m)->add_to_group(user,group);
    //delete user;
    //delete group;
    //delete db_m;

}
bool MainController::delete_row(db_table table, QString selected){
    switch(table){
    case user://delete a user;
        db_m = new User_DB(dbPath);
        db_m->delete_row(selected);
        delete db_m;
        break;
    case group:
        db_m = new Group_DB(dbPath);
        return db_m->delete_row(selected);
        delete db_m;
        break;
    case userGroup:
        db_m = new Group_DB(dbPath);
        int id = selected.toInt();
        ((Group_DB*)db_m)->remove_from_group(id);
        delete db_m;
        break;
    }
}

User* MainController::select_user(QString username){
    db_m = new User_DB(dbPath);

    User* user = ((User_DB*)db_m)->select_user(username);
    delete db_m;
    return user;
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
    db_m->create_table();
    db_m->create_row(g);
    delete db_m;
}

// Get a list of all the civilians
std::vector<User*> MainController::get_civilians() {
    db_m = new User_DB(dbPath);
    return ((User_DB*)db_m)->get_civilians();
    delete db_m;
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

Group* MainController::select_group(int id) {
    db_m = new Group_DB(dbPath);

    Group* temp = ((Group_DB*)db_m)->select_group(id);

    delete db_m;
    return temp;
}

//adds in an emergency item to the database
bool MainController::add_response(Response* resp) {
    db_m = new Response_DB(dbPath);
    db_m->create_table();

    db_m->create_row(resp);

    delete db_m;
    return true;
}

Response* MainController::select_response(Emergency* em, Group* gr) {
    db_m = new Response_DB(dbPath);

    Response* temp = ((Response_DB*)db_m)->get_response(em, gr);

    delete db_m;
    return temp;
}

std::vector<int> MainController::get_resp_em_DBItems(int value) {
    db_m = new Response_DB(dbPath);

    std::vector<int> temp = ((Response_DB*)db_m)->get_Em_DBItems(value);

    delete db_m;
    return temp;
}

//adds in an notification to the database
bool MainController::add_notification(Notification* no) {
    db_m = new Notification_DB(dbPath);
    db_m->create_table();

    db_m->create_row(no);

    delete db_m;
    return true;
}


// Method to create a new client instance
void MainController::start_client() {
    c = new Client();
}

// Method to start a new server instance
void MainController::start_server() {
    s = new Server();
}

void MainController::get_notification() {
    c->request_new_msg();
}

//select notification from database
Notification* MainController::select_notification_id(int value) {
    db_m = new Notification_DB(dbPath);

    Notification* no = ((Notification_DB*)db_m)->select_simulation_id(value);

    delete db_m;
    return no;
}

//removes a notification from the database
bool MainController::remove_notification(int value) {
    db_m = new Notification_DB(dbPath);

    db_m->delete_row(value);

    delete db_m;
    return true;
}
