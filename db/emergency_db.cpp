#include "emergency_db.h"

void Emergency_DB::generate_sql_queries() {
    create_cmd += "CREATE TABLE IF NOT EXISTS emergencies (id integer PRIMARY KEY, name text NOT NULL, public_response text NOT NULL);";
    insert_cmd += "INSERT INTO emergencies (name, public_response) VALUES (:name, :public_response);";

    // Todo: When you update, you need to be able to choose which values you are updating
    update_cmd += "UPDATE emergencies SET name=:name, public_response=:public_response;"; // WHERE id=:id;";
    drop_cmd += "DROP TABLE IF EXISTS emergencies;";
    query = nullptr;
}

void Emergency_DB::update_value(DBItem* u) {
    Emergency *em = (Emergency*)(u);
    query = new QSqlQuery(db);
    query->prepare(update_cmd);
    query->bindValue(":name", em->name);
    query->bindValue(":public_response", em->public_response);

    query->exec();

    delete query;
}

void Emergency_DB::create_row(DBItem* u) {
    Emergency *em = (Emergency*)(u);
    query = new QSqlQuery(db);

    query->prepare(insert_cmd);
    query->bindValue(":name", em->name);
    query->bindValue(":public_response", em->public_response);

    query->exec();

    delete query;
}

Emergency* Emergency_DB::select_emergency(QString name) {
    Emergency *em;
    query = new QSqlQuery(db);
    query->prepare("SELECT DISTINCT * FROM emergencies WHERE name=:name");
    query->bindValue(":name", name);
    query->exec();

    if(query->next()) {
        em = new Emergency(query->value(1).toString(), query->value(2).toString());
        em->id = query->value(0).toInt();

        delete query;
        return em;
    } else {
        std::cerr << "Entry does not exist." << std::endl;
        delete query;
        return nullptr;
    }
}

Emergency* Emergency_DB::select_emergency(int id) {
    Emergency *em;
    query = new QSqlQuery(db);
    query->prepare("SELECT DISTINCT * FROM emergencies WHERE id=:id");
    query->bindValue(":id", id);
    query->exec();

    if(query->next()) {
        em = new Emergency(query->value(1).toString(), query->value(2).toString());
        em->id = query->value(0).toInt();

        delete query;
        return em;
    } else {
        std::cerr << "Entry does not exist." << std::endl;
        delete query;
        return nullptr;
    }
}

std::vector<QString> Emergency_DB::get_DBItems(){
    query = new QSqlQuery(db);

    query->exec("SELECT * FROM emergencies;");

    std::vector<QString> ems;

    while (query->next()) {
        ems.push_back(query->value(1).toString());
    }

    //delete query;

    return ems;
}
