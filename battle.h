// If they choose [F]ight - enter the battleMenu
    // option 1 is to attack
        // attack stat subtracts from the hp stat
    // option 2 is to block
        // check if block stat is higher than attack stat
        // if block >= attack then no damage
        // if block < attack then subtract different from hp stat
    // option 3 is to use a skill
        // depends on class chosen
        // skill adds to hp, atk, or def
// if they choose [R]un away - the program ends
// if they pick another key, it loops back to the [F] or [R] option

#include <iostream>
#include <cstdlib>
#include <ctime>

//function type matters
// int, char, void, bool - use the right one
// does it makes sense? default should be void not int

//new assignment read functions and returns more

//break habits 
char playerChoice()
{
    char choice = ' ';
    std::cout << "Battle Menu: [A]ttack - [B]lock - [S]kill \n";
    std::cin >> choice;
    
    if(choice == 'A' || 'a'){
        return 'A';
    }
    else if(choice == 'B' || 'b'){
        return 'B';
    }
    else if(choice == 'S' || 's'){
        return 'S';
    }
    else
        return playerChoice();
}

void battle (Character& Player, Character& Opponent) //params - passed in
{
    char answer = ' ';
    bool inBattle = true;
    
    while (inBattle)
    {
        std::cout << "Fight [F] or Runaway [R].\n";
        std::cin >> answer;
        switch (answer)
        {
        case 'F':
        case 'f':
            std::cout << "Your battle starts now! \n";
            playerChoice();
            inBattle = false;
        break;
        case 'R':
        case 'r':
            std::cout << "You ran away. Good call. \n";
            inBattle = false;
        break;
        default:
            std::cout << "That was neither. Try again! \n";
            inBattle = true;
        break;
        }
    }

    // while (inBattle)
    // {
    //     std::cout << "Choose your action!\n";
    //     switch (answer)
    //     {
    //     case 'A':
    //         inBattle = handleAttack(Player, Opponent);
    //         break;
    //     case 'B':
    //         inBattle = handleBlock(x, y, z);
    //         break;
    //     case 'S':
    //         inBattle = handleSkill(Player, Player.getSkill());
    //         break;
    //     default:
    //         std::cout << "That was neither. Try again! \n";
    //         break;

    //     }
    // }

}

char getRandomAction()
{
    int num = rand() % 3;
    if (num == 0){
        return 'A';
    }
    else if (num == 1){
        return 'B';
    }
    else
        return 'S';
}

bool handleAttack(Character& Health, Character& Attack)
{
    switch (getRandomAction())
    {
    case 'A':
        /*
        player attack - opponent hp
        opponent attack - player hp
        */
    break;
    case 'B':
        /*
        (player atk - opponent def) - opp hp 
        */
    break;
    case 'S':
        /*
        player atk*2 - opponent hp
        opponet skill use
        */
    break;
    default:
        return true;
    }
    return false; //return bool for character death
}

bool handleBlock(Character& Defense, Character& Health, Character& Attack)
{
    switch (getRandomAction())
    {
    case 'A':
        /*
        (opponent atk - player def) - player hp 
        */
    break;
    case 'B':
        /*
        std::cout << "You idiots both blocked. Congrats nothing happens. \n"
        */
    break;
    case 'S':
        /*
        (player atk - opponent def) - opp hp 
        */
    break;
    default:
        return true;
    }
    return false; //return bool for character death
    }

bool handleSkill(Character& Character, Skill& Skill)
    {
    switch (getRandomAction())
    {
    case 'A':
        /*
        opponent atk*2 - player hp
        player skill use
        */
    break;
    case 'B':
        /*
        opponent use block
        player skill use
        */
    break;
    case 'S':
        /*
        player skill use
        opp skill use
        */
    break;
    default:
        return true;
    }
    return false; //return bool for character death    
}


