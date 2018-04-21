#include "simulation_db.h"

void Simulation_DB::generate_sql_queries() {
    create_cmd += "CREATE TABLE simulations (id integer PRIMARY KEY, name text NOT NULL UNIQUE, type_sim integer, lat integer, lng integer, radius integer, num_civilians integer, trigger integer);";
    insert_cmd += "INSERT INTO simulations (name, type_sim, lat, lng, radius, num_civilians, trigger) VALUES (:name, :type_sim, :lat, :lng, :radius, :num_civilians, :trigger);";

    // Todo: When you update, you need to be able to choose which values you are updating
    update_cmd += "UPDATE simulations SET name=:name, type_sim=:type_sim, lat=:lat, lng=:lng, radius=:radius, num_civilians=:num_civilians, trigger=:trigger;"; // WHERE id=:id;";
    drop_cmd += "DROP TABLE IF EXISTS simulations;";
    query = nullptr;
}

void Simulation_DB::update_value(DBItem* u) {
    Simulation *sim = (Simulation*)(u);
    query = new QSqlQuery(db);
    query->prepare(update_cmd);
    std::cout<< "ssssssssssssssssss\n";
    query->bindValue(":name", sim->name);
    query->bindValue(":type_sim", sim->type_sim);
    query->bindValue(":lat", sim->lat);
    query->bindValue(":lng", sim->lng);
    query->bindValue(":radius", sim->radius);
    query->bindValue(":num_civilians", sim->num_civilians);
    query->bindValue(":trigger", sim->trigger);;
//    query->bindValue(":id", user->id);

    query->exec();

    delete query;
    delete sim;
}

void Simulation_DB::create_row(DBItem* u) {
    Simulation *sim = (Simulation*)(u);
    query = new QSqlQuery(db);

    query->prepare(insert_cmd);
    query->bindValue(":name", sim->name);
    query->bindValue(":type_sim", sim->type_sim);
    query->bindValue(":lat", sim->lat);
    query->bindValue(":lng", sim->lng);
    query->bindValue(":radius", sim->radius);
    query->bindValue(":num_civilians", sim->num_civilians);
    query->bindValue(":trigger", sim->trigger);


    query->exec();

    delete query;
    delete sim;
}

Simulation* Simulation_DB::select_simulation(QString name) {
    Simulation *sim;
    query = new QSqlQuery(db);
    query->prepare("SELECT DISTINCT * FROM simulations WHERE name=:sim");
    query->bindValue(":sim", name);
    query->exec();

    if(query->next()) {
        sim = new Simulation(query->value(1).toString(), query->value(2).toInt(), query->value(3).toInt(), query->value(4).toInt(),
                             query->value(6).toInt(), query->value(6).toInt(), query->value(7).toInt());
        sim->id = query->value(0).toInt();

        delete query;
        return sim;
    } else {
        std::cerr << "Entry does not exist." << std::endl;
        delete query;
        return nullptr;
    }
}
