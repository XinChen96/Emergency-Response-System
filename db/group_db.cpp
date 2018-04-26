#include "group_db.h"
#include "../users/responder.h"
#include <iostream>

using namespace std;

void Group_DB::generate_sql_queries() {
    create_cmd += "CREATE TABLE IF NOT EXISTS groups (id integer PRIMARY KEY, groupName text NOT NULL UNIQUE, date text);";
    insert_cmd += "INSERT INTO groups (groupName, date) VALUES (:groupName, DATE('now'));";
    delete_cmd += "DELETE FROM groups WHERE groupName = :group;";
    update_cmd += "UPDATE groups SET groupName=:groupName WHERE id=:id;";
    drop_cmd += "DROP TABLE IF EXISTS groups;";

    create_groups_cmd += "CREATE TABLE IF NOT EXISTS userGroups (id integer PRIMARY KEY, group_id integer NOT NULL, user_id integer NOT NULL, FOREIGN KEY(group_id) REFERENCES groups(id), FOREIGN KEY(user_id) REFERENCES users(id));";
    //insert_groups_cmd += "INSERT INTO userGroups (group_id, user_id) VALUES (:group_id, :user_id);";
    delete_groups_cmd += "DELETE FROM userGroups WHERE id = :id;";
    query = nullptr;
}

// Adds a new group to the
void Group_DB::create_row(DBItem* g) {
    Group *group = (Group*)(g);

    query = new QSqlQuery(db);
    query->prepare(insert_cmd);
    query->bindValue(":groupName", group->name);
    query->exec();

    delete query; // Delete pointer
   // delete group;
}
bool Group_DB::create_groups_table(){
    query = new QSqlQuery(db);

    if(query->exec(create_groups_cmd)) {
        std::cout << "create_userGroup_table: create table if not exist." << std::endl;
         delete query;
        return true;

    } else {
        std::cerr << "create_userGroup_table: could not create table." << std::endl;
        qDebug()<<query->exec(drop_cmd);
         delete query;
        return false;
    }


}

bool Group_DB::delete_row(QString groupName){
    query = new QSqlQuery(db);
    query->prepare(delete_cmd);
    query->bindValue(":group", groupName);

    if(query->exec()) {
        std::cout <<"Group_DB: Group("
                  << groupName.toStdString()
                  <<") deleted"
                  << std::endl;
        return true;
    } else {
        std::cout << "Group_DB: User("
                  << groupName.toStdString()
                  <<") delete failed"
                 << std::endl;
        return false;
    }
}
bool Group_DB::remove_from_group(int id){
    query = new QSqlQuery(db);
    query->prepare(delete_groups_cmd);
    query->bindValue(":id", id);

    if(query->exec()) {
        std::cout << "Remove from groups"
                  << std::endl;
        return true;
    } else {
        std::cout << "Remove failed"
                 << std::endl;
        return false;
    }
}

void Group_DB::update_value(DBItem* g) {
    Group *group = (Group*)(g);

    query = new QSqlQuery(db);
    query->prepare(update_cmd);
    query->bindValue(":groupName", group->name);
    query->bindValue(":id", group->id);

    query->exec();

    delete query; // Delete pointer
    delete group;
}

Group* Group_DB::select_group(int id) {
    Group* group;
    cout << id <<endl;
    query = new QSqlQuery(db);
    query->prepare("SELECT DISTINCT * FROM groups WHERE id=:id");
    query->bindValue(":id", id);
    query->exec();

    if(query->next()) {
        group = new Group(query->value(1).toString());
        delete query;
        return group;
    } else {
        cerr << "Group:select_group:"
                "Entry does not exist." << endl;
        delete query;
        return nullptr;
    }
}

Group* Group_DB::select_group(QString name) {
    Group* group;
    query = new QSqlQuery(db);
    query->prepare("SELECT DISTINCT * FROM groups WHERE groupName=:name");
    query->bindValue(":name", name);
    query->exec();

    if(query->next()) {
        group = new Group(query->value(1).toString());
        group->id = query->value(0).toInt();
        delete query;
        return group;
    } else {
        cerr << "Entry does not exist." << endl;
        delete query;
        return nullptr;
    }
}

int Group_DB::find_group(int userId) {
    int groupId;
    query = new QSqlQuery(db);
    query->prepare("SELECT DISTINCT * FROM userGroups WHERE user_id=:userId");
    query->bindValue(":userId", userId);
    query->exec();

    if(query->next()) {
        groupId =  query->value(1).toInt();
        delete query;
        return groupId;
    } else {
        cerr << "Entry does not exist." << endl;
        delete query;
        return -1;
    }
}



void Group_DB::add_to_group(User* user, Group* group) {
    cout<< user->id<< group->id<<"addto group\n";
    if(user->id != -1 && group->id != -1) {
        query = new QSqlQuery(db);
        query->prepare("INSERT INTO userGroups (user_id, group_id) VALUES(:user, :group);");
        query->bindValue(":user",user->id);
        query->bindValue(":group", group->id);
        if(query->exec()){
            cout<<"add_to_group succeeded"<<endl;
        }else{
            cout<<"add_to_group failed"<<endl;
            qDebug() << query->lastError();
        }
    } else {
        cerr << "ID from database has not yet been assigned.";
    }
}

// Lists all the members of a certain group
// Note: make sure you delete all the pointers as you iterate over the users in the group
vector<User*> Group_DB::get_group_members(Group* g) {
    vector<User*> user_list;
    query = new QSqlQuery(db);
    query->prepare("SELECT users.id, firstName, lastName, username, role FROM userGroups INNER JOIN users ON userGroups.user_id=users.id WHERE userGroups.group_id=:id;");
    query->bindValue(":id", g->id);
    query->exec();
    User* user;
    while(query->next()) {
        user = new User(query->value(1).toString(), query->value(2).toString(),query->value(3).toString(), ((Role)query->value(4).toInt()));
        user->id = query->value(0).toInt();
        user_list.push_back(user);
    }

    return user_list;
}

vector<Group*> Group_DB::get_groups() {
    vector<Group*> group_list;
    query = new QSqlQuery(db);
    query->prepare("SELECT * FROM groups;");
    query->exec();
    Group *g;
    while(query->next()) {
        g = new Group(query->value(1).toString(), query->value(2).toString());
        g->id = query->value(0).toInt();
        group_list.push_back(g);
    }
    return group_list;
}


