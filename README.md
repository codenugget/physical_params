# Physical Parameters

Right now I only have one file for the periodic table entries of the atoms.

## periodic\_table.h
This header file was added to get access to some of the periodic table parameters of known atoms.
The parameters you can access are:
* Atomic Number
* Group
* Period
* Weight (amu = g / mol)
* Density (g / cm3)
* Melting Point (degrees in C, cUnknownTemperature if not known)
* Boiling Point (degrees in C, cUnknownTemperature if not known)
* Ionization Energy (eV, 0 when unknown)
* Earth Abundance (0 if unknown)
* Block
* Name (the long name, i.e. 'Helium' etc.)
* Symbol (the short name such as 'H', 'He', 'C' etc)
* Electronic Configuration (NOTE: experimental syntax due to ASCII-limitations)
* Extended Information (Called 'special', contains a semi-colon separated list of known attributes, i.e. "nonmetal;reactive;chalcogen" for Oxygen)
<br />
If you want to use this header file you need to define the flag ```PERIODIC_TABLE_IMPLEMENTATION``` as follows in **ONE** C or C++ implementation file in your project.
A good example would be in i.e. main.c or main.cpp
In other project files you should only include the header file without the define statement.

### main.c ###
```C
#include <stdio.h>
#define PERIODIC_TABLE_IMPLEMENTATION
#include "periodic_table.h"

int main(int argc, char** argv) {
	printf("Atomic weight of %s is %f\n", periodic_table[PT_IRON].name, periodic_table[PT_IRON].atomic_weight);
	return 0;
}
```

### other.c ###
```C
#include <stdio.h>
#include "periodic_table.h"

void foo() {
	printf("Atomic weight of %s is %f\n", periodic_table[PT_LEAD].name, periodic_table[PT_LEAD].atomic_weight);
}
```

