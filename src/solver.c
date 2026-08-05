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

// Solve for power
double solve_power(double voltage, double current) {
    return voltage * current;
}

// Void function for analyzing series circuit
void analyze_series_circuit(Circuit *circuit){
    circuit->equivalentResistance = solve_series_resistance(circuit);
    circuit->totalCurrent = solve_current(circuit->supplyVoltage, circuit->equivalentResistance);

    calculate_series_voltage_drops(circuit);
    calculate_series_power(circuit);

    circuit->totalPower = solve_power(circuit->supplyVoltage, circuit->totalCurrent);
}

// Void function for analyzing parallel circuit
void analyze_parallel_circuit(Circuit *circuit){
    circuit->equivalentResistance = solve_parallel_resistance(circuit);
    calculate_parallel_currents(circuit);
    circuit->totalCurrent = 0.0;

    int count = get_resistor_count(circuit);

    for (int i = 0; i < count; i++){
        circuit->totalCurrent += circuit->resistors[i].current;
    }

    calculate_parallel_power(circuit);

    circuit->totalPower = solve_power(circuit->supplyVoltage, circuit->totalCurrent);
}

// Void function to calculate series voltage drops
void calculate_series_voltage_drops(Circuit *circuit){
    int count = get_resistor_count(circuit);

    for(int i = 0; i < count; i++){
        circuit->resistors[i].voltage = solve_voltage(circuit->totalCurrent, circuit->resistors[i].resistance);
    }
}

// Void function to calculate series power
void calculate_series_power(Circuit *circuit){
    int count = get_resistor_count(circuit);

    for(int i = 0; i < count; i++){
        circuit->resistors[i].current = circuit->totalCurrent;
        circuit->resistors[i].power = solve_power(circuit->resistors[i].voltage, circuit->resistors[i].current);
    }
}

// Void function to calculate parallel current
void calculate_parallel_currents(Circuit *circuit){
    int count = get_resistor_count(circuit);

    for (int i = 0; i < count; i++){
        circuit->resistors[i].voltage = circuit->supplyVoltage;
        circuit->resistors[i].current = solve_current(circuit->supplyVoltage, circuit->resistors[i].resistance);
    }
}

// Void function to calculate parallel power
void calculate_parallel_power(Circuit *circuit){
    int count = get_resistor_count(circuit);

    for (int i = 0; i < count; i++){
        circuit->resistors[i].power = solve_power(circuit->resistors[i].voltage, circuit->resistors[i].current);
    }
}

// Void function to analyze circuit type
void analyze_circuit(Circuit *circuit){
    if (circuit->type == SERIES){
        analyze_series_circuit(circuit);
    } else {
        analyze_parallel_circuit(circuit);
    }
}