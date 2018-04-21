#include <iostream>
#include "maincontroller.h"
using namespace std;

int main()
{
    MainController* ctrl = new MainController("../db.sqlite");
        QString first("ff");
        QString last("ffff");
        QString user("me");

       ctrl->add_user(first,last,user);

    return 0;
}
