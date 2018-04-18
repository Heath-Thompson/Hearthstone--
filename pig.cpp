#include "pig.h"

string Pig::render(int line){
    
    switch(line){
        case 0: return ".___________.";
        case 1: return "|    Pig    |";
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

Pig::Pig(string name, int manaCost, int attack, int defense):Card(name, manaCost, attack, defense){ 
  
}