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

    add_resistor(&circuit,
                 create_resistor(1,100));

    add_resistor(&circuit,
                 create_resistor(2,220));

    add_resistor(&circuit,
                 create_resistor(3,330));

    double voltage = 12.0;

    double series =
            solve_series_resistance(&circuit);

    double parallel =
            solve_parallel_resistance(&circuit);

    double current =
            solve_current(voltage,
                          series);

    double power =
            solve_power(voltage,
                        current);

    printf("Series Resistance : %.2f ohms\n",
           series);

    printf("Parallel Resistance : %.2f ohms\n",
           parallel);

    printf("Current : %.4f A\n",
           current);

    printf("Power : %.4f W\n",
           power);

    return 0;
}