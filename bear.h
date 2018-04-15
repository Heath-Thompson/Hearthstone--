#ifndef BEAR_H
#define BEAR_H

#include <iostream>
#include "card.h"

using namespace std;

class Bear : public Card {
   // private:
    
    public:
    Bear(string, int, int, int);
    virtual string render(int);    
};

#endif