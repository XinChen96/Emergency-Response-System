#include "db_manager.h"
#include <iostream>
#include <vector>

DB_Manager::DB_Manager(const QString& path) {
    //std::cerr << "DB_manager: called" << std::endl;
    std::cout << "DB_manager: called" << std::endl;
    db = QSqlDatabase::addDatabase("QSQLITE"); // Create the db
    db.setDatabaseName(path); // Set it to the correct location

    if(!db.open()) {
        std::cerr << "DB_Manager: Could not open db." << std::endl;
        //exit(0);
    } else {
        std::cout << "DB_Manager: Db connection okay." << std::endl;
    }


}


void DB_Manager::create_table(){
    query = new QSqlQuery(db);

    if(query->exec(create_cmd)) {
        std::cout << "create_table: create table if not exist." << std::endl;
    } else {
        std::cerr << "create_table: could not create table." << std::endl;
        qDebug()<<query->exec(drop_cmd);
    }

    delete query;
}
void DB_Manager::build_table() {
    query = new QSqlQuery(db);

    if(!query->exec(drop_cmd)) {
        std::cerr << "build_table: could not drop existing table." << std::endl;
        qDebug()<<query->exec(drop_cmd);
    } else {
        std::cout << "build_table: drop existing table" << std::endl;
    }

    if(!query->exec(create_cmd)) {
        std::cerr << "build_table: could not create table." << std::endl;
        qDebug()<<query->exec(drop_cmd);
    } else {
        std::cout << "build_table: created table." << std::endl;
    }

    //query->exec(drop_cmd);   // drop existing table
    //query->exec(create_cmd); // create table
    std::cout << __PRETTY_FUNCTION__<<"\n";
    delete query;
}

QSqlDatabase DB_Manager::get_db(){
    return db;
}

