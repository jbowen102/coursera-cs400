#pragma once

namespace uiuc {
    class Cube {
        public:
            double getVolume();
            double getSurfaceArea();
            double getLength();
            void setLength(double);

            Cube(); // custom default constructor
            Cube(double); // one-param constructor

            // Cube(const Cube &); // copy constructor
            Cube & operator=(const Cube &); // assignment operator

            ~Cube(); // custom destructor

        private:
            double length_;
    };
}