#ifndef RABBIT_H
#define RABBIT_H

#include <iostream>
#include "card.h"

using namespace std;

class Rabbit : public Card {
   // private:
    
    public:
    Rabbit(string, int, int, int);
    virtual string render(int);    
};

#endif