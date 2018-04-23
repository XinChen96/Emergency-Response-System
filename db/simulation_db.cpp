#include "simulation_db.h"

void Simulation_DB::generate_sql_queries() {
    create_cmd += "CREATE TABLE IF NOT EXISTS simulations (id integer PRIMARY KEY, name text NOT NULL UNIQUE, lat real, lng real, radius real, num_civilians integer, emergency_id integer, FOREIGN KEY (emergency_id) references emergencies(id)));";
    insert_cmd += "INSERT INTO simulations (name, lat, lng, radius, num_civilians, emergency_id) VALUES (:name, :lat, :lng, :radius, :num_civilians, :emergency_id);";

    // Todo: When you update, you need to be able to choose which values you are updating
    update_cmd += "UPDATE simulations SET name=:name, type_sim=:type_sim, lat=:lat, lng=:lng, radius=:radius, num_civilians=:num_civilians, emergency_id=:emergency_id"; // WHERE id=:id;";
    drop_cmd += "DROP TABLE IF EXISTS simulations;";
    query = nullptr;
}

void Simulation_DB::update_value(DBItem* u) {
    Simulation *sim = (Simulation*)(u);
    query = new QSqlQuery(db);
    query->prepare(update_cmd);
    query->bindValue(":name", sim->name);
    query->bindValue(":lat", sim->lat);
    query->bindValue(":lng", sim->lng);
    query->bindValue(":radius", sim->radius);
    query->bindValue(":num_civilians", sim->num_civilians);
    query->bindValue(":emergency_id", sim->emergency_id);

    query->exec();

    delete query;
    //delete sim;
}

void Simulation_DB::create_row(DBItem* u) {
    Simulation *sim = (Simulation*)(u);
    query = new QSqlQuery(db);

    query->prepare(insert_cmd);
    query->bindValue(":name", sim->name);
    query->bindValue(":lat", sim->lat);
    query->bindValue(":lng", sim->lng);
    query->bindValue(":radius", sim->radius);
    query->bindValue(":num_civilians", sim->num_civilians);
    query->bindValue(":emergency_id", sim->emergency_id);;


    query->exec();

    delete query;
    //delete sim;
}

Simulation* Simulation_DB::select_simulation(QString name) {
    Simulation *sim;
    query = new QSqlQuery(db);
    query->prepare("SELECT DISTINCT * FROM simulations WHERE name=:name");
    query->bindValue(":name", name);
    query->exec();

    if(query->next()) {
        sim = new Simulation(query->value(1).toString(), query->value(2).toDouble(), query->value(3).toDouble(), query->value(4).toDouble(),
                             query->value(5).toInt(), query->value(6).toInt());
        sim->id = query->value(0).toInt();

        delete query;
        return sim;
    } else {
        std::cerr << "Entry does not exist." << std::endl;
        delete query;
        return nullptr;
    }
}

std::vector<QString> Simulation_DB::get_DBItems(){
    query = new QSqlQuery(db);

    query->exec("SELECT * FROM simulations;");

    std::vector<QString> sims;

    while (query->next()) {
        sims.push_back(query->value(1).toString());
    }

    //delete query;

    return sims;
}
