#ifndef SOLVER_H
#define SOLVER_H
#include "circuit.h"

// Equivalent resistance
double solve_series_resistance(const Circuit *circuit);
double solve_parallel_resistance(const Circuit *circuit);

// Ohm's Law
double solve_current(double voltage, double resistance);
double solve_voltage(double current, double resistance);
double solve_resistance(double voltage, double current);

// Power
double solve_power(double voltage, double current);

// Complete circuit analysis
void analyze_series_circuit(Circuit *circuit);
void analyze_parallel_circuit(Circuit *circuit);

// Calculate voltage drop in a series circuit
void calculate_series_voltage_drops(Circuit *circuit);

// Calculate power in a series circuit
void calculate_series_power(Circuit *circuit);

// Calculate current in a parallel circuit
void calculate_parallel_currents(Circuit *circuit);

// Calculate power in a parallel circuit
void calculate_parallel_power(Circuit *circuit);

// Performs an analysis of the circuit's type
void analyze_circuit(Circuit *circuit);

#endif
