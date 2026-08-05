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

#endif
