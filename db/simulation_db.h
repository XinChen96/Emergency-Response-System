#ifndef SIMULATION_DB_H
#define SIMULATION_DB_H

#include "db_manager.h"

class Simulation_DB : public DB_Manager
{
public:
    Simulation_DB(const QString& path) : DB_Manager(path) {
        generate_sql_queries();
    }

    ~Simulation_DB() {}
    void create_row(DBItem*);
    void update_value(DBItem*);
    void generate_sql_queries();

    Simulation* select_simulation(QString);
};

#endif // SIMULATION_DB_H
