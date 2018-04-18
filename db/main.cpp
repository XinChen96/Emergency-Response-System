#include <iostream>

#include "gtest/gtest.h"
#include "db_manager.h"
#include "user_db.h"
#include "group_db.h"
#include "../users/user.h"
#include "../users/roles.h"

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

TEST(InsertTest, TESTSIMPLE) {
    DB_Manager *db = new User_DB("../test.sqlite");
    db->build_table();
    DBItem *entry = new Civilian(QString("Benny"), QString("Fuller"), QString("benfuller"), 1);
    db->create_row(entry); // Add entry
    
}


int main(int argc, char **argv) {

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
