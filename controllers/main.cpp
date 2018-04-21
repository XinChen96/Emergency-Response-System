#include <iostream>
#include "maincontroller.h"
using namespace std;

int main()
{
    MainController* ctrl = new MainController();
        QString first("ff");
        QString last("ffff");
        QString user("me");

       ctrl->add_user(first,last,user,civilian);

    return 0;
}
