#include "notification_db.h"

void Notification_DB::generate_sql_queries() {
    create_cmd += "CREATE TABLE IF NOT EXISTS notifications (id integer PRIMARY KEY, simulation_id integer, FOREIGN KEY (simulation_id) REFERENCES simulations(id));";
    insert_cmd += "INSERT INTO notifications (simulation_id) VALUES (:simulation_id);";

    // Todo: When you update, you need to be able to choose which values you are updating
    update_cmd += "UPDATE notifications SET simulation_id=:simulation_id;"; // WHERE id=:id;";
    drop_cmd += "DROP TABLE IF EXISTS notifications;";
    delete_cmd += "DELETE FROM notifications WHERE id=:id;";
    query = nullptr;
}

void Notification_DB::update_value(DBItem* u) {
    Notification* noti = (Notification*)(u);
    query = new QSqlQuery(db);
    query->prepare(update_cmd);
    query->bindValue(":simulation_id", noti->simulation_id);

    query->exec();

    delete query;
}

void Notification_DB::create_row(DBItem* u) {
    Notification* noti = (Notification*)(u);
    query = new QSqlQuery(db);

    query->prepare(insert_cmd);
    query->bindValue(":simulation_id", noti->simulation_id);;

    query->exec();

    delete query;
}

bool Notification_DB::delete_row(int id) {
    query = new QSqlQuery(db);
    query->prepare(delete_cmd);
    query->bindValue(":id", id);

    if(query->exec()) {
        return true;
    } else {
        return false;
    }
}


Notification* Notification_DB::select_simulation_id(int simulation_id) {
    Notification* noti;
    query = new QSqlQuery(db);
    query->prepare("SELECT DISTINCT * FROM notifications WHERE simulation_id=:simulation_id");
    query->bindValue(":simulation_id", simulation_id);
    query->exec();

    if(query->next()) {
        noti = new Notification(query->value(1).toInt());
        noti->id = query->value(0).toInt();

        delete query;
        return noti;
    } else {
        std::cerr << "Entry does not exist." << std::endl;
        delete query;
        return nullptr;
    }
}
