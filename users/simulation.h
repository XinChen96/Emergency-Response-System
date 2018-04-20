#ifndef SIMULATION_H
#define SIMULATION_H

#include <QString>

class Simulation
{
public:

    Simulation();
    Simulation(int type);

    //setters
    void set_name(QString value);
    void set_lat(int value);
    void set_lng(int value);
    void set_radius(int value);
    void set_civilians(int value);
    void set_trigger(int value);

private:

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
