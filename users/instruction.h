#ifndef INSTRUCTION_H
#define INSTRUCTION_H
#include "dbitem.h"
#include <QString>
class Instruction : public DBItem {
public:
    Instruction(QString instr, int _id) : DBItem(-1), instruction(instr), group_id(_id) {}

    QString instruction;
    int group_id;
};

#endif // INSTRUCTION_H
