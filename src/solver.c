#include "solver.h"

// Calculates the equivalent resistance of a series circuit
double solve_series_resistance(const Circuit *circuit)
{
    double totalResistance = 0.0;
    int count = get_resistor_count(circuit);

    for (int i = 0; i < count; i++){
        Resistor resistor = get_resistor(circuit, i);
        totalResistance += get_resistance(resistor);
    }

    return totalResistance;
}

// Calculates the equivalent resistance of a parallel circuit
double solve_parallel_resistance(const Circuit *circuit){
    int count = get_resistor_count(circuit);
    if (count == 0){
        return 0.0;
    }

    double reciprocal = 0.0;
    for (int i = 0; i < count; i++){
        Resistor resistor = get_resistor(circuit, i);
        double resistance = get_resistance(resistor);

        if (resistance <= 0.0){
            return 0.0;
        }

        reciprocal += 1.0 / resistance;
    }

    return 1.0 / reciprocal;
}


// Solve for current
double solve_current(double voltage, double resistance){
    if (resistance <= 0.0){
        return 0.0;
    }

    return voltage / resistance;
}

// Solve for voltage
double solve_voltage(double current, double resistance) {
    return current * resistance;
}

// Solve for resistance
double solve_resistance(double voltage, double current){
    if (current <= 0.0){
        return 0.0;
    }

    return voltage / current;
}

// Solve for powerR
double solve_power(double voltage, double current) {
    return voltage * current;
}