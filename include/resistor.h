#ifndef RESISTOR_H
#define RESISTOR_H

typedef struct{
    int id;
    double resistance;
} Resistor;


// Creates a resistor object
Resistor create_resistor(int id, double resistance);

// Returns resistance value
double get_resistance(Resistor resistor);

#endif