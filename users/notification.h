#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include "dbitem.h"
#include <QString>

class Notification : public DBItem
{
public:

    Notification(): DBItem(-1) {}

    Notification(int sim_id) : DBItem(-1) {
        simulation_id = sim_id;
    }

    int simulation_id;
};
#endif // NOTIFICATION_H
