// The program was initially conceived and developed in a procedural approach.
// However, as the program evolved and the elements required from the UI mockup in MATLAB,
// taking an object-oriented approach instead is more beneficial
// as it allows different files to do their respective roles/functions.

#include <stdio.h>
#include "solver.h"

int main()
{
    Circuit circuit;
    initialize_circuit(&circuit);

    // Circuit configurations
    circuit.type = SERIES;
    circuit.supplyVoltage = 12.0;

    // Add resistors
    add_resistor(&circuit,create_resistor(1, 100));

    add_resistor(&circuit,create_resistor(2, 220));

    add_resistor(&circuit,create_resistor(3, 330));

    // Engineering calculations
    if (circuit.type == SERIES){
        circuit.equivalentResistance =
            solve_series_resistance(&circuit);
    }
    else
    {
        circuit.equivalentResistance =
            solve_parallel_resistance(&circuit);
    }

    circuit.totalCurrent =
        solve_current(
            circuit.supplyVoltage,
            circuit.equivalentResistance);

    circuit.totalPower =
        solve_power(
            circuit.supplyVoltage,
            circuit.totalCurrent);

    // Display results
    printf("=====================================\n");
    printf("      DC Circuit Analyzer\n");
    printf("=====================================\n\n");

    printf("Circuit Type : %s\n",
           circuit.type == SERIES ? "Series" : "Parallel");

    printf("Supply Voltage : %.2f V\n\n", circuit.supplyVoltage);

    printf("Number of Resistors : %d\n\n", get_resistor_count(&circuit));

    printf("Equivalent Resistance : %.2f ohms\n", circuit.equivalentResistance);

    printf("Total Current : %.4f A\n", circuit.totalCurrent);

    printf("Total Power : %.4f W\n", circuit.totalPower);

    return 0;
}