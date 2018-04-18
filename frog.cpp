#include "frog.h"

string Frog::render(int line){
    
    switch(line){
        case 0: return ".___________.";
        case 1: return "|    Frog   |";
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

Frog::Frog(string name, int manaCost, int attack, int defense){ 
    name = "Frog";
    manaCost = 1;
    attack = 100;
    defense = 200;
}
