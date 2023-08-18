#include <iostream>
#include <cstdlib>
#include <ctime>

// g++ test-driver.cpp -o test-driver.exe
// * are pointers
// & are references

constexpr float NUMBER_OF_TESTS = 1000;
constexpr int CHANCE_FOR_ATTACK = 65;
constexpr int CHANCE_FOR_BLOCK = 90;


char getRandomAction() 
{
int num = rand() % 99 + 1;
    
if (num <= CHANCE_FOR_ATTACK) {
    return 'A';
} else if (num <= CHANCE_FOR_BLOCK) {
    return 'B';
} else { // anything above 90 will execute the Opponent's Skill
    return 'S';
}
}

//https://www.programiz.com/cpp-programming/library-function/cstdio/printf#google_vignette

int main() 
{
    // Seed the random number generator with the current time
    srand(time(nullptr));

    int aCount = 0;
    int bCount = 0;
    int sCount = 0;

    // Test the behavior of getRandomAction()
    for (int i = 0; i < NUMBER_OF_TESTS; ++i) {
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

    printf("A Count: %d - %.2f%.\n", aCount, aCount/NUMBER_OF_TESTS * 100);
    printf("B Count: %d - %.2f%.\n", bCount, bCount/NUMBER_OF_TESTS * 100);
    printf("S Count: %d - %.2f%.\n", sCount, sCount/NUMBER_OF_TESTS * 100);
    // std::cout << "A count: " << aCount << "\n";
    // std::cout << "B count: " << bCount << "\n";
    // std::cout << "S count: " << sCount << "\n";

    return 0;
}