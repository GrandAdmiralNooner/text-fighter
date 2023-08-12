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
    chooseClass();
    Character player = getCharacter();
    chooseOpponent();
    Character opponent = getCharacter();

    // int compare = mirrorMatch (player.getName(), opponent.getName());
    // while (compare == -1) 
    // {
    //     opponent = getCharacter();
    //     compare = mirrorMatch (player.getName(), opponent.getName());
    // }

    while (player == opponent)
    {
        std::cout << "That match is not allowed. \n";
        std::cout << "You will need to choose your opponent again. \n";
        chooseOpponent();
        opponent = getCharacter();
    }
        std::cout << "This will be an interesting battle. Good luck. \n";
        std::cout << "Prepare. Your battle begins soon. \n";

    battle(player, opponent);

}