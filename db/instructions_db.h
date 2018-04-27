#ifndef INSTRUCTIONS_DB_H
#define INSTRUCTIONS_DB_H
#include "db_manager.h"
#include "../users/instruction.h"

class Instructions_DB : public DB_Manager {
public:
    Instructions_DB(const QString& path) : DB_Manager(path) { generate_sql_queries(); }
    ~Instructions_DB() {}

    void create_row(DBItem*);
    void update_value(DBItem*);
    void generate_sql_queries();

    void add_planner_instruction(DBItem*);
    Instruction* get_instruction(int);
};

#endif // INSTRUCTIONS_DB_H
