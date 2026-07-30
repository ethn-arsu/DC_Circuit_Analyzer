#include "resistor.h"


Resistor create_resistor(int id, double resistance){
    Resistor resistor;
    resistor.id = id;
    resistor.resistance = resistance;
    return resistor;
}

double get_resistance(Resistor resistor){
    return resistor.resistance;
}