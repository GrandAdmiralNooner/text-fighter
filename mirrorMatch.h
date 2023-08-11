#include <iostream>

int mirrorMatch(std::string x, std::string y)
{
    if (x == y)
    {
        std::cout << "That match is not allowed. \n";
        std::cout << "You will need to choose your opponent again. \n";
        return -1;
    } else {
        std::cout << "This will be an interesting battle. Good luck. \n";
        std::cout << "Prepare. Your battle begins soon. \n";
        return 0;
        }
}