#include "resistor.h"


Resistor create_resistor(int id, double resistance){
    Resistor resistor;

    resistor.id = id;
    resistor.resistance = resistance;

    resistor.voltage = 0.0;
    resistor.current = 0.0;
    resistor.power = 0.0;

    return resistor;
}

double get_resistance(Resistor resistor){
    return resistor.resistance;
}