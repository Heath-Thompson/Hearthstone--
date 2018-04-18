#include "giraffe.h"

string giraffe::render(int line){
    
    switch(line){
        case 0: return ".___________.";
        case 1: return "|  Giraffe  |";
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

Giraffe::Giraffe(string name, int manaCost, int attack, int defense){ 
    name = "Giraffe";
    manaCost = 5;
    attack = 400;
    defense = 500;
}
