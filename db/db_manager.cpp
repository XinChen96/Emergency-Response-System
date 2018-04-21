#include "db_manager.h"
#include <iostream>

DB_Manager::DB_Manager(const QString& path) {
    std::cerr << "called" << std::endl;
    db = QSqlDatabase::addDatabase("QSQLITE"); // Create the db
    db.setDatabaseName(path); // Set it to the correct location

    if(!db.open()) {
        std::cerr << "Could not open db." << std::endl;
        exit(0);
    } else {
        std::cout << "Db connection okay." << std::endl;
    }
    std::cout << __PRETTY_FUNCTION__<<"\n";
}

void DB_Manager::build_table() {
    query = new QSqlQuery(db);
    if(!query->exec(drop_cmd)) {
        std::cerr << "Could not open db." << std::endl;
        qDebug()<<query->exec(drop_cmd);
    } else {
        std::cout << "Db connection okay." << std::endl;
    }

    if(!query->exec(create_cmd)) {
        std::cerr << "Could not open db." << std::endl;
        qDebug()<<query->exec(drop_cmd);
    } else {
        std::cout << "Db connection okay." << std::endl;
    }

    //query->exec(drop_cmd);   // drop existing table
    //query->exec(create_cmd); // create table
    std::cout << __PRETTY_FUNCTION__<<"\n";
    delete query;
}

