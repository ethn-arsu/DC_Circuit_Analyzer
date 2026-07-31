#include "solver.h"

double solve_series_resistance(const Circuit *circuit) {
    return calculate_series_resistance(circuit);
}

double solve_parallel_resistance(const Circuit *circuit) {
    if (circuit -> resistorCount == 0) {
        return 0.0;
    }
    double reciprocal = 0.0;
    for (int i = 0; i < circuit -> resistorCount; i++) {
        if (circuit -> resistors[i].resistance == 0) {
            return 0.0;
        }
        reciprocal += 1.0 / circuit -> resistors[i].resistance;
    }
    return 1.0 / reciprocal;
}

double solve_current(double voltage, double resistance) {
    return voltage / resistance;
}

double solve_voltage(double current, double resistance) {
    return current * resistance;
}

double solve_resistance(double voltage, double current) {
    return voltage / current;
}

double solve_power(double voltage, double current) {
    return voltage * current;
}