#ifndef CHICKEN_HH
#define CHICKEN_HH

#include"bird.hh"
#include <string>
class Owl: public Bird
{
public:
    Owl();
    void hoot(std::ostream& output) const;

};

#endif // CHICKEN_HH
