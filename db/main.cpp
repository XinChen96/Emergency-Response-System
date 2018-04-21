#include <iostream>
#include <vector>
#include "gtest/gtest.h"
#include "db_manager.h"
#include "user_db.h"
#include "group_db.h"
#include "simulation_db.h"
#include "../users/user.h"
#include "../users/roles.h"
#include "../users/simulation.h"

// The fixture for testing class DBTest
class DBTest : public ::testing::Test {

    DBTest() {
    }
 protected:
  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, you can define the following methods:
  virtual void SetUp() {
  }

  virtual void TearDown() {
  }
};

TEST(InsertSimulationTest, TESTSIMPLE) {
    DB_Manager *db = new Simulation_DB("../test.sqlite");
    db->build_table();
    Simulation* sim = new Simulation("Earthquake 1", 0, 40, -75, .005, 32, -1);
    db->create_row(sim); // Add entry
    //ASSERT_EQ(nullptr, ((User_DB*)db)->select_civilian("ralph")); // check if user does not exist
    ASSERT_EQ("Earthquake 1", ((Simulation_DB*)db)->select_simulation("Earthquake 1")->name); // username is unique

    delete sim;
    delete db;
}

TEST(InsertUserTest, TESTSIMPLE) {
    DB_Manager *db = new User_DB("../test.sqlite");
    db->build_table();
    DBItem *anotherentry = new Civilian("Ben", "Last", "firstlast");
    std::cout<<anotherentry->id<<std::endl;
    db->create_row(anotherentry); // Add entry
    ASSERT_EQ(nullptr, ((User_DB*)db)->select_user("ralph")); // check if user does not exist
    ASSERT_EQ("firstlast", ((User_DB*)db)->select_user("firstlast")->username); // username is unique

    delete anotherentry;
    delete db;
}

TEST(UpdateUserTest, TESTSIMPLE) {
    DB_Manager *db = new User_DB("../test.sqlite");
    db->build_table();
    DBItem *anotherentry = new Civilian("Nimajneb", "Last", "firstlast");
    db->create_row(anotherentry); // Add entry

    QString Fuller("Fuller");
    ASSERT_EQ("Last", ((User_DB*)db)->select_user("firstlast")->last_name);
    anotherentry = new Civilian("Ben", "Fuller", "firstlast");
    db->update_value(anotherentry);
    ASSERT_EQ(Fuller, ((User_DB*)db)->select_user("firstlast")->last_name);

    delete anotherentry;
    delete db;
}

TEST(InsertGroupTest, TESTSIMPLE) {
    DB_Manager *db = new Group_DB("../test.sqlite");
    db->build_table();
    DBItem *entry = new Group("The Rad Group");
    db->create_row(entry); // Add entry
    ASSERT_EQ("The Rad Group", ((Group_DB*)db)->select_group("The Rad Group")->name); // username is unique

    delete entry;
    delete db;
}

TEST(InsertUserGroupTest, TESTSIMPLE) {
    DB_Manager *db_u = new User_DB("../test.sqlite");
    User* user = ((User_DB*)db_u)->select_user("firstlast"); // Select user
    delete db_u;

    DB_Manager *db = new Group_DB("../test.sqlite");
    ((Group_DB*)db)->create_group_table(); // Creat group table
    DBItem *entry = new Group("The Rad Group");
    db->create_row(entry); // Add entry

    Group* g = ((Group_DB*)db)->select_group("The Rad Group");
    ((Group_DB*)db)->create_group_table(); // Create the table usersGroup
    ((Group_DB*)db)->add_to_group(user, g);

    std::vector<User*> user_list = ((Group_DB*)db)->get_group_members(g);
    ASSERT_EQ(user_list[0]->username, user->username);
    delete g;
    delete user;
    delete entry;
    delete db;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
