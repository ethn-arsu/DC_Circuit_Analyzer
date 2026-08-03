#ifndef RESISTOR_H
#define RESISTOR_H

typedef struct{
    int id;

    double resistance;
    double voltage;
    double current;
    double power;
} Resistor;


// Creates a resistor object
Resistor create_resistor(int id, double resistance);

// Returns resistance value
double get_resistance(Resistor resistor);

#endif