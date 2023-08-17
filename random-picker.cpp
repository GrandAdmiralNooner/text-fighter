#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

// g++ random-picker.cpp -o ran-pick.exe

std::vector<std::string> names = {"Nino", "Rol", "Ben", "Nick", "Noah", "Chris", "Angelo", "Nico", "Jacob", "RB", "Coy", "Cason"};

std::string getRandomAction() 
{
    if (names.empty()) {
        return "No names left!";
    }

    int num = rand() % names.size();
    std::string picked_name = names[num];

    // Remove the picked name from the list
    names.erase(names.begin() + num);

    return picked_name;
}

int main() 
{
    // Seed the random number generator with the current time
    srand(time(nullptr));
    int index = 0;
    for (int i = 0; i < 12; ++i) {
        std::string action = getRandomAction();
        index +=1;
        std::cout << index << ". " << action << ".\n";
    }
    return 0;
}