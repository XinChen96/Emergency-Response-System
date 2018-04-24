#include <iostream>
#include <vector>
#include "gtest/gtest.h"
#include "server.h"
#include "client.h"

// The fixture for testing class DBTest
class ServerTest : public ::testing::Test {

    ServerTest() {
    }
 protected:
  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, you can define the following methods:
  virtual void SetUp() {
  }

  virtual void TearDown() {
  }
};

TEST(StartServerTest, TESTSIMPLE) {
    Server *s = new Server();
    Client *c = new Client();
    c->request_new_message();
    delete c;
    delete s;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
