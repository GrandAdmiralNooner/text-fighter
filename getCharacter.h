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

//Reminder: skills - name, cd, add attack, add defense, add health

Character getCharacter() {
  using namespace std;
  static vector<Character> Characters
  {
    {"Fighter", {"Two-Weapon", 2, 4, 0, 0}, 50, 8, 6},
    {"Ranger", {"Breaker", 2, 5, 0, 0}, 50, 7, 5},
    {"Cleric", {"Intervention", 2, 4, 2, 12}, 50, 4, 6},
    {"Sorcerer", {"Fireball", 3, 12, 0, 0}, 50, 6, 4}
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