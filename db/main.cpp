#include <iostream>

#include "gtest/gtest.h"
#include "db_manager.h"
#include "user_db.h"
#include "group_db.h"

// The fixture for testing class Foo.
class DBTest : public ::testing::Test {
    DBTest() {
    }
 protected:
  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, you can define the following methods:
  virtual void SetUp() {

  }

  virtual void TearDown() {
    // Code here will be called immediately after each test (right
    // before the destructor).
  }
};

TEST(InsertTest, TESTSIMPLE) {
    DB_Manager *db;
    db = new User_DB(QString("../db.sqlite"));
    //db->create_row();

}


int main(int argc, char **argv) {

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
