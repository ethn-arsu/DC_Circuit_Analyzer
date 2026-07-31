#include <stdio.h>

#include "circuit.h"
#include "resistor.h"


int main(){
    Circuit circuit;
    initialize_circuit(&circuit);
    add_resistor(&circuit, create_resistor(1, 100));
    add_resistor(&circuit, create_resistor(2, 220));
    add_resistor(&circuit, create_resistor(3, 330));

    printf("Number of resistors: %d\n", circuit.resistorCount);
    printf("Equivalent series resistance: %.2f ohms\n", calculate_series_resistance(&circuit));


    return 0;
}