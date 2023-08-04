// welcome
// choose 1 of 4 classes - fighter, cleric, ranger, sorc
// choose 1 of 4 opponent - same
// no mirror matches
// choose to fight, or choose to runaway - program end
// ---

#include <iostream>
#include "getCharacter.h"
#include "mirrorMatch.h"
#include "battle.h"

// g++ main.cpp -o main.exe

int main() 
{

    printWelcome();

    std::cout << "You will be choosing your class. \n";
    Character player = getCharacter();

    std::cout << "You will be choosing your opponent. \n";
    Character opponent = getCharacter();

    int compare = mirrorMatch (player.getName(), opponent.getName());
    while (compare == -1) 
    {
        Character opponent = getCharacter();
        compare = mirrorMatch (player.getName(), opponent.getName());
    }

    battle(player, opponent);

}