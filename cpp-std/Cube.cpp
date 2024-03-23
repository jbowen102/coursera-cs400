/**
 * Simple C++ class for representing a Cube.
 * 
 * @author
 *   Wade Fagen-Ulmschneider <waf@illinois.edu>
 */

// #include "Cube.h"
#include "Cube.h"
#include <iostream>

namespace uiuc {
  Cube::Cube() {
    length_ = 1;
  }
  Cube::Cube(double length) {
    length_ = length;
  }

  Cube::~Cube() {
    length_ = 0;
    // std::cout << "Destroyed. Length: " << length_ << std::endl;
  }

  Cube & Cube::operator=(const Cube & obj) {
    length_ = obj.length_;
    return *this;
  } // assignment operator


  double Cube::getLength() {
    return length_;
  }

  double Cube::getVolume() {
    return length_ * length_ * length_;
  }

  double Cube::getSurfaceArea() {
    return 6 * length_ * length_;
  }

  void Cube::setLength(double length) {
    length_ = length;
  }
}
