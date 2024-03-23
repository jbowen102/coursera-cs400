#include <iostream>
#include "Cube.h"


int main() {
	Cube c;

	c.setLength(5.3);

	double volume = c.getVolume();
	std::cout << "Volume: " << volume << std::endl;

	return 0;
}
