#include "db_manager.h"
#include <iostream>

DB_Manager::DB_Manager(const QString& path) {
    db = QSqlDatabase::addDatabase("QSQLITE"); // Create the db
    db.setDatabaseName(path); // Set it to the correct location

    if(!db.open()) {
        std::cerr << "Could not open db." << std::endl;
        exit(0);
    } else {
        std::cout << "Db connection okay." << std::endl;
    }
}

void DB_Manager::build_table() {
    query = new QSqlQuery(db);

    std::cout << create_cmd.toStdString() << std::endl;
    query->exec(drop_cmd);   // drop existing table
    query->exec(create_cmd); // create table

    delete query;
}
