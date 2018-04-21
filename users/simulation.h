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
     * @param type_value    type of simulation
     * @param lat_value     latitude value of emergency
     * @param lng_value     longitude value of emergency
     * @param radius_value  radius of emgergency
     * @param civ_value     number of civilians in emergency
     * @param trig_value    type of emergency
     */
    Simulation(QString name_value, int type_value, int lat_value, int lng_value, int radius_value, int civ_value, int trig_value): DBItem(-1) {
        type_sim = type_value;
        name = name_value;
        lat = lat_value;
        lng = lng_value;
        radius = radius_value;
        num_civilians = civ_value;
        trigger = trig_value;
    }

    //setters
    void set_name(QString value);
    void set_lat(int value);
    void set_lng(int value);
    void set_radius(int value);
    void set_civilians(int value);
    void set_trigger(int value);

    //variables used in all simulations
    int type_sim;
    QString name;
    int lat;
    int lng;

    //emergency planner / first responder simulation variables
    int radius;
    int num_civilians;

    //emergency planner / civilian simulation variables
    int trigger;

};

#endif // SIMULATION_H
