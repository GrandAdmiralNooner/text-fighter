#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstdio>

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
    for (int i = 12; i >= 1; i--) {
        std::string action = getRandomAction();
        // std::cout << i << ". " << action << ".\n";
        printf("Pick #%d: Owner: %s.\n", i, action.c_str());
    }
}