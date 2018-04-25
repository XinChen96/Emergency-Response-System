#ifndef RESPONSE_DB_H
#define RESPONSE_DB_H
#include "db_manager.h"
#include "../users/response.h"
#include "../users/group.h"

class Response_DB : public DB_Manager {
public:
    Response_DB(const QString& path) : DB_Manager(path) { generate_sql_queries(); }
    ~Response_DB() {}
    void create_row(DBItem*);
    void update_value(DBItem*);
    void generate_sql_queries();

    Response* get_response(Emergency*, Group*);

    std::vector<int> get_Em_DBItems(int value);
};

#endif // RESPONSE_DB_H
