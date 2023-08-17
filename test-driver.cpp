#include <iostream>
#include <cstdlib>
#include <ctime>

// g++ test-driver.cpp -o test-driver.exe

char getRandomAction() 
{
int num = rand() % 99 + 1;
if (num <= 65) {
    return 'A';
} else if (num >= 66 && num <= 90) {
    return 'B';
} else {
    return 'S';
}
}

int main() 
{
    // Seed the random number generator with the current time
    srand(time(nullptr));

    int aCount = 0;
    int bCount = 0;
    int sCount = 0;

    // Test the behavior of getRandomAction()
    for (int i = 0; i < 30; ++i) {
        char action = getRandomAction();
        // std::cout << "Random action: " << action << " " << static_cast<int>(action) << "\n";

        switch (action)
        {
            case 'A':
                ++aCount;
                break;
            case 'B':
                ++bCount;
                break;
            case 'S':
                ++sCount;
                break;
            default:
                break;
        }
    }

    std::cout << "A count: " << aCount << "\n";
    std::cout << "B count: " << bCount << "\n";
    std::cout << "S count: " << sCount << "\n";

    return 0;
}