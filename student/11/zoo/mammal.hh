#ifndef MAMMAL_HH
#define MAMMAL_HH

#include "animal.hh"
#include <string>
#include <iostream>

class Mammal: public Animal
{
public:
    Mammal();

    void suckle(std::ostream& output);


};

#endif // MAMMAL_HH
