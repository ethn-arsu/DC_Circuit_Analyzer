#include "circuit.h"

void initialize_circuit(Circuit* circuit) {
    circuit->resistorCount = 0;
}

int add_resistor(Circuit *circuit, Resistor resistor) {
    if (circuit->resistorCount >= MAX_RESISTORS) {
        return 0;
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