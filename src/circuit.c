#include "circuit.h"


double calculate_series_resistance(double r1,double r2){
    return r1 + r2;
}

double calculate_current(double voltage,double resistance){
    return voltage / resistance;
}