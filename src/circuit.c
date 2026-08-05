#include <stdlib.h>
#include "circuit.h"

void initialize_circuit(Circuit *circuit){

    // Default circuit configuration
    circuit->type = SERIES;

    // Circuit values
    circuit->supplyVoltage = 0.0;
    circuit->equivalentResistance = 0.0;
    circuit->totalCurrent = 0.0;
    circuit->totalPower = 0.0;

    circuit->resistorCount = 0;
    circuit->capacity = 5;
    circuit->resistors = malloc(circuit->capacity * sizeof(Resistor));
}

void destroy_circuit(Circuit *circuit){
    free(circuit->resistors);
    circuit->resistors = NULL;
    circuit->resistorCount = 0;
    circuit->capacity = 0;
}

int add_resistor(Circuit *circuit, Resistor resistor) {
    if (circuit->resistorCount >= circuit->capacity){
        circuit->capacity *= 2;

        Resistor *temp = realloc(circuit->resistors,circuit->capacity * sizeof(Resistor));

        if (temp == NULL){
            return 0;
        }

        circuit->resistors = temp;
    }

    circuit->resistors[circuit->resistorCount] = resistor;
    circuit->resistorCount++;

    return 1;
}

double calculate_series_resistance(const Circuit *circuit) {
    double total = 0.0;

    for (int i = 0; i < circuit->resistorCount; i++) {
        total += circuit->resistors[i].resistance;
    }

    return total;
}

int get_resistor_count(const Circuit* circuit) {
    return circuit->resistorCount;
}

Resistor get_resistor(const Circuit* circuit, int index) {
    return circuit->resistors[index];
}

double get_equivalent_resistance(const Circuit *circuit){
    return circuit->equivalentResistance;
}

double get_total_current(const Circuit *circuit){
    return circuit->totalCurrent;
}

double get_total_power(const Circuit *circuit){
    return circuit->totalPower;
}

double get_supply_voltage(const Circuit *circuit){
    return circuit->supplyVoltage;
}

CircuitType get_circuit_type(const Circuit *circuit){
    return circuit->type;
}