#ifndef ELEPHANT_H
#define ELEPHANT_H

#include <iostream>
#include "card.h"

using namespace std;

class Elephant : public Card {
   // private:
    
    public:
    Elephant(string, int, int, int);
    virtual string render(int);    
};

#endif