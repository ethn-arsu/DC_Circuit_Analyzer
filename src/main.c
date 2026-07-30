#include <stdio.h>

#include "resistor.h"


int main()
{

    Resistor r1 =
            create_resistor(1, 100);


    Resistor r2 =
            create_resistor(2, 200);


    printf("Resistor %d: %.2f ohms\n",
           r1.id,
           get_resistance(r1));


    printf("Resistor %d: %.2f ohms\n",
           r2.id,
           get_resistance(r2));


    return 0;
}