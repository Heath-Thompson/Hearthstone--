#ifndef COW_H
#define COW_H

#include <iostream>
#include "card.h"

using namespace std;

class Cow : public Card {
   // private:
    
    public:
    Cow(string, int, int, int);
    virtual string render(int);    
};

#endif