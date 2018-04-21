#include "maincontroller.h"
#include <iostream>

MainController::MainController() {
dbPath = "db.sqlite";
db = new User_DB(dbPath);
}

MainController::~MainController() {
//delete db;
}
//void MainController::print_db(DB_Manager db){
//    std::cout << "--------------------------------------" << std::endl;

//    QSqlQuery query(db);

//    query.exec("select title, cost from movies where cost < 100 and cost > 10;");

//    while (query.next()) {
//        QString title = query.value(0).toString();
//        int         cost  = query.value(1).toInt();
//        std::cout << title.toStdString()
//                  << "  "
//                  << cost
//                  << std::endl;
//    }

//    query.last();
//}

bool MainController::add_user(QString firstName,QString lastName,QString username) {

    User *newCivilian = new Civilian(firstName,lastName,username);

    db->create_row(newCivilian);
    //std::cout<<((User_DB*)db)->select_civilian("6666")->last_name.toStdString()<<std::endl;
    db->print();

    return true;
}


