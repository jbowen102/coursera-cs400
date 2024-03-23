/**
 * Simple C++ making use of std::cout and a `Cube` class.
 * 
 * @author
 *   Wade Fagen-Ulmschneider <waf@illinois.edu>
 */

#include <iostream>
#include "Cube.h"

int main() {
  uiuc::Cube c;
  uiuc::Cube c2(2);
  std::cout << "Length: " << c.getLength() << std::endl;
  std::cout << "Length2: " << c2.getLength() << std::endl;
  std::cout << std::endl; // newline

  c.setLength(2.4);
  std::cout << "Volume: " << c.getVolume() << std::endl;

  double surfaceArea = c.getSurfaceArea();
  std::cout << "Surface Area: " << surfaceArea << std::endl;

  std::cout << std::endl; // newline
  std::cout << "Length: " << c.getLength() << std::endl;
  std::cout << "Length2: " << c2.getLength() << std::endl;

  std::cout << "\n(Copy op)\n" << std::endl;
  c2 = c;
  std::cout << "Length: " << c.getLength() << std::endl;
  std::cout << "Length2: " << c2.getLength() << std::endl;

  return 0;
}
