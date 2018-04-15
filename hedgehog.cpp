#include "hedgehog.h"

string Hedgehog::render(int line){
    
    switch(line){
        case 0: return ".___________.";
        case 1: return "| Hedgehog  |";
        case 2: return "|           |";
        case 3: return "|           |";
        case 4: return "|           |";
        case 5: return "|           |";
        case 6: return "|           |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}

Hedgehog::Hedgehog(string name, int manaCost, int attack, int defense){ 
    name = "Hedgehog";
    manaCost = 2;
    attack = 300;
    defense = 100;
}
