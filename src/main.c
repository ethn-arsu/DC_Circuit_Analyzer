#include <stdio.h>
#include "solver.h"

int main(){
    Circuit circuit;

    // Initialize circuit
    initialize_circuit(&circuit);

    // Configure circuit
    circuit.type = SERIES;
    circuit.supplyVoltage = 12.0;

    // Add resistors
    add_resistor(&circuit, create_resistor(1, 100));

    add_resistor(&circuit, create_resistor(2, 220));

    add_resistor(&circuit, create_resistor(3, 330));

    // Analyze the circuit
    if (circuit.type == SERIES){
        analyze_series_circuit(&circuit);
    }
    else
    {
        analyze_parallel_circuit(&circuit);
    }

    // Display results
    printf("=====================================\n");
    printf("       DC Circuit Analyzer\n");
    printf("=====================================\n\n");

    printf("Circuit Type: %s\n", circuit.type == SERIES ? "Series" : "Parallel");
    printf("Supply Voltage: %.2f V\n", circuit.supplyVoltage);
    printf("Number of Resistors: %d\n\n", get_resistor_count(&circuit));
    printf("Equivalent Resistance: %.2f ohms\n", circuit.equivalentResistance);
    printf("Total Current: %.4f A\n", circuit.totalCurrent);
    printf("Total Power: %.4f W\n", circuit.totalPower);

    return 0;
}