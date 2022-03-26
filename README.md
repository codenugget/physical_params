# Physical Params

## periodic_table.h
This simple header file was added to get easier access the periodic table parameters of the known atoms.

If you want to use this you need to define the flag PERIODIC_TABLE_IMPLEMENTATION as follows in **ONE** C or C++ implementation file in your project.
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

int foo() {
	printf("Atomic weight of %s is %f\n", periodic_table[PT_LEAD].name, periodic_table[PT_LEAD].atomic_weight);
}
```

