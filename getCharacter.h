// welcome
// choose 1 of 4 classes - fighter, cleric, ranger, sorc
// choose 1 of 4 opponent - same
// no mirror matches
// choose to fight, or choose to runaway - program end
// ---
// fight - battle system
// ran away - program would end
// battle system 
//     - attack
//     - block
//     - skill
//         - skill was based on

#include <vector>
#include "character.h"

void printWelcome() {
    std::cout << "Welcome to the Arena!" << '\n';
}

void chooseClass() {
  std::cout << "You will be choosing your class. \n";
}

void chooseOpponent() {
  std::cout << "You will be choosing your opponent. \n";
}

Character getCharacter() {
  using namespace std;
  static vector<Character> Characters
  {
    {"Fighter", {"Two-Weapon", 4, 6, 0, 0}, 50, 8, 6}, // static - this is known
    {"Ranger", {"Breaker", 4, 4, 0, 0}, 50, 7, 5},
    {"Cleric", {"Intervention", 4, 4, 2, 12}, 50, 4, 6},
    {"Sorcerer", {"Fireball", 4, 12, 0, 0}, 50, 6, 4}
  };

    std::cout << "Which class interests you most? \n"; // seperation of concerns. pick smallest scope first
    // old school for loop
    for (int i = 0; i < Characters.size(); ++i)
    {
      std::cout << i+1 << ". " << Characters[i] << '\n';
    }
    std::cout << "Each class is as unique as they get. \n";
    
    int choice;
    std::cin >> choice;
    //error may appear - segmentation fault, a number outside of scope
    // is choice - 1 a valid choice?
    
    if (choice <= 0 || choice > Characters.size()) 
    {
      std::cout << "Please pick a relevant number. \n";
      return getCharacter(); //recursion
    }
    std::cout << "The ["<< Characters[choice-1] <<"] has been chosen. \n";
    Characters[choice-1].printStats();

    return Characters[choice-1];

    // skill in the character class
    // break all functions 

}