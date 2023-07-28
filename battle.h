#include <iostream>

int battle (std::string x, std::string y)
{
    char answer = ' ';
    bool loopBattle = true;
    
    while (loopBattle)
    {
        std::cout << "Fight [F] or Runaway [R].\n";
        std::cin >> answer;
        switch (answer)
    {
        case 'R':
        case 'r':
            std::cout << "You ran away. Good call. \n";
            loopBattle = false;
        break;
        case 'F':
        case 'f':
            std::cout << "Your battle will now start. Sike! \n";
            loopBattle = false;
        break;
        default:
            std::cout << "That was neither. Try again! \n";
        loopBattle = true;
        break;
    }
    }
    return 0;
}
