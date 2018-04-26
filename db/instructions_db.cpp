#include "instructions_db.h"
#include <iostream>
void Instructions_DB::generate_sql_queries() {
    create_cmd += "CREATE TABLE IF NOT EXISTS instructions (id integer PRIMARY KEY, instruction text NOT NULL, group_id integer NOT NULL, date text NOT NULL, FOREIGN KEY(group_id) REFERENCES groups.id);";
    insert_cmd += "INSERT INTO instructions (instruction, group_id, date) VALUES (:instruction, :group_id, DATE('now'));";
    update_cmd += "UPDATE instructions SET instruction=:instruction, group_id=:group_id WHERE id=:id;";
    drop_cmd += "DROP TABLE IF EXISTS instructions;";
}

void Instructions_DB::create_row(DBItem* instr) {
    Instruction *in = ((Instruction*)instr);

    query = new QSqlQuery(db);
    query->prepare(insert_cmd);
    query->bindValue(":instruction", in->instruction);
    query->bindValue(":group_id", in->group_id);
    query->exec();
    delete query;
}

void Instructions_DB::update_value(DBItem* instr) {
    Instruction *in = ((Instruction*)instr);

    query = new QSqlQuery(db);
    query->prepare(update_cmd);
    query->bindValue(":instruction", in->instruction);
    query->bindValue(":id", instr->id);
    query->bindValue(":group_id", in->group_id);
    query->exec();
    delete query;
    delete in;
}

void Instructions_DB::add_planner_instruction(DBItem* instr) {
    Instruction *in = ((Instruction*)instr);

    query = new QSqlQuery(db);
    query->prepare("INSERT INTO plannerInstructions (instruction, group_id, date) VALUES (:instruction, :group_id, DATE('now'));");
    query->bindValue(":instruction", in->instruction);
    query->bindValue(":id", instr->id);
    query->bindValue(":group_id", in->group_id);
    query->exec();
    delete query;
    delete in;
}


