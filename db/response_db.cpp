#include "response_db.h"
#include <iostream>

void Response_DB::generate_sql_queries() {
    create_cmd += "CREATE TABLE IF NOT EXISTS responses (id integer PRIMARY KEY, group_id integer, emergency_id integer, response text, FOREIGN KEY(group_id) REFERENCES groups(id), FOREIGN KEY(emergency_id) REFERENCES emergencies(id));";
    insert_cmd += "INSERT INTO responses (group_id, emergency_id, response) VALUES (:group_id, :emergency_id, :response);";

    update_cmd += "UPDATE responses SET group_id=:group, emergency_id=:emergency, response=:response WHERE id=:id;";
    drop_cmd += "DROP TABLE IF EXISTS responses;";
    query = nullptr;
}

// Adds a new response to the db
void Response_DB::create_row(DBItem* r) {
    Response *response = (Response*)(r);

    query = new QSqlQuery(db);
    query->prepare(insert_cmd);
    query->bindValue(":group_id", response->group_id);
    query->bindValue(":emergency_id", response->emergency_id);
    query->bindValue(":response", response->emergency_response);

    query->exec();

    delete query; // Delete pointer
}

void Response_DB::update_value(DBItem *r) {
    Response *response = (Response*)(r);

    query = new QSqlQuery(db);
    query->prepare(update_cmd);
    query->bindValue(":group", response->group_id);
    query->bindValue(":emergency", response->emergency_id);
    query->bindValue(":response", response->emergency_response);
    query->bindValue(":id", response->id);
    query->exec();

    delete query; // Delete pointer
}

Response* Response_DB::get_response(Emergency* e, Group* g) {
    query = new QSqlQuery(db);
    query->prepare("SELECT id, group_id, emergency_id, response FROM responses WHERE group_id=:group AND emergency_id=:emergency;");
    query->bindValue(":group", g->id);
    query->bindValue(":emergency", e->id);
    query->exec();

    if(query->next()) {
        Response *r = new Response(query->value(1).toInt(), query->value(2).toInt(), query->value(3).toString());
        r->id = query->value(0).toInt();
        delete query;
        return r;
    } else {
        std::cerr << "Could not find entry.";
        delete query;
        return nullptr;
    }
}

std::vector<int> Response_DB::get_Em_DBItems(int value) {
    query = new QSqlQuery(db);

    query->exec("SELECT * FROM responses;");

    std::vector<int> resp;

    while (query->next()) {
        if (query->value(2).toInt() == value) {
            resp.push_back(query->value(1).toInt());
        }
    }

    //delete query;

    return resp;
}
