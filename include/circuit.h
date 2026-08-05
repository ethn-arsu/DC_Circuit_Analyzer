#ifndef CIRCUIT_H
#define CIRCUIT_H
#include "resistor.h"
#define MAX_RESISTORS 100

typedef enum {
    SERIES,
    PARALLEL
} CircuitType;

typedef struct {
    CircuitType type;
    double supplyVoltage;
    double equivalentResistance;
    double totalCurrent;
    double totalPower;
    Resistor *resistors;
    int resistorCount;
    int capacity;
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

// Circuit result accessors
double get_equivalent_resistance(const Circuit *circuit);
double get_total_current(const Circuit *circuit);
double get_total_power(const Circuit *circuit);
double get_supply_voltage(const Circuit *circuit);
CircuitType get_circuit_type(const Circuit *circuit);

// Release memory
void destroy_circuit(Circuit *circuit);

#endif