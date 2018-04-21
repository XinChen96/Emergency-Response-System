#include "simulation.h"

/** setters */

/**
 * Sets the name of the simulation.
 *
 * @param value name of the simulation
 */
void Simulation::set_name(QString value) {
    name = value;
}

/**
 * Sets the latitude value of the emergency.
 *
 * @param value latitude value of the emergency
 */
void Simulation::set_lat(double value) {
    lat = value;
}

/**
 * Sets the longitude value of the emergency.
 *
 * @param value longitude value of the emergency
 */
void Simulation::set_lng(double value) {
    lng = value;
}

/**
 * Sets the radius of the emergency.
 *
 * @param value radius of the emergency
 */
void Simulation::set_radius(double value) {
    radius = value;
}

/**
 * Sets the number of civilians in the emegency.
 *
 * @param value number of civilians involved
 */
void Simulation::set_civilians(int value) {
    num_civilians = value;
}

/**
 * Sets the trigger (type of emergency) value of the emergency.
 *
 * @param value trigger (type of emegency)
 */
void Simulation::set_trigger(int value) {
    trigger = value;
}
