#ifndef PIG_H
#define PIG_H

#include <iostream>
#include "card.h"

using namespace std;

class Pig : public Card {
   // private:
    
    public:
    Pig(string, int, int, int);
    virtual string render(int);    
};

#endif