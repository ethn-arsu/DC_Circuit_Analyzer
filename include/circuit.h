#ifndef CIRCUIT_H
#define CIRCUIT_H
#include "resistor.h"
#define MAX_RESISTORS 100

typedef struct {
    Resistor resistors[MAX_RESISTORS];
    int resistorCount;
} Circuit;

// Initialization
void initialize_circuit(Circuit* circuit);

// Component management
int add_resistor(Circuit *circuit,Resistor resistor);

// Circuit calculations
double calculate_series_resistance(const Circuit *circuit);

// Accessors
int get_resistor_count(const Circuit* circuit);
Resistor get_resistor(const Circuit* circuit, int index);

#endif