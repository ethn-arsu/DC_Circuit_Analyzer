#include <stdio.h>
#include "circuit.h"


int main(){

    double voltage = 12.0;
    double r1 = 100.0;
    double r2 = 200.0;
    double totalResistance = calculate_series_resistance(r1,r2);
    double current = calculate_current(voltage, totalResistance);


    printf("DC Circuit Analyzer\n");
    printf("------------------\n");
    printf("Resistance: %.2f ohms\n",totalResistance);
    printf("Current: %.4f amps\n",
           current);
    
    return 0;
}