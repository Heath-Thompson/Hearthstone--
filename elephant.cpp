#include "elephant.h"

string Elephant::render(int line){
    
    switch(line){
        case 0: return ".___________.";
        case 1: return "|  Elephant |";
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

Elephant::Elephant(string name, int manaCost, int attack, int defense):Card(name, manaCost, attack, defense){ 
  
}