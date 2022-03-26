# Physical Params

## periodic_table.h
This simple header file was added to easier get access the periodic table the known atoms.

If you want to use this you need to define a flag as follows in ONE c or c++ implementation file.
A good example would be in i.e. main.c or main.cpp

#include <stdlib.h>
#define PERIODIC_TABLE_IMPLEMENTATION
#include "periodic_table.h"

int main(int argc, char** argv) {
	printf("Atomic weight of %s is %f\n", periodic_table[PT_IRON].name, periodic_table[PT_IRON].atomic_weight);
	return 0;
}

