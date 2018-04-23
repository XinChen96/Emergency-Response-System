#ifndef SIMULATION_H
#define SIMULATION_H

#include <QString>
#include "dbitem.h"

class Simulation : public DBItem
{
public:

    Simulation(): DBItem(-1) {}

    /**
     * Constructs the simulation object and defines the type of simulation
     *
     * @param name_value    name of simulation
     * @param lat_value     latitude value of emergency
     * @param lng_value     longitude value of emergency
     * @param radius_value  radius of emgergency
     * @param civ_value     number of civilians in emergency
     * @param trig_value    type of emergency
     */
    Simulation(QString name_value, double lat_value, double lng_value, double radius_value, int civ_value, int trig_value): DBItem(-1) {
        name = name_value;
        lat = lat_value;
        lng = lng_value;
        radius = radius_value;
        num_civilians = civ_value;
        emergency_id = trig_value;
    }

    //variables used in all simulations
    QString name;
    double lat;
    double lng;
    double radius;
    int num_civilians;
    int emergency_id;

};

#endif // SIMULATION_H
