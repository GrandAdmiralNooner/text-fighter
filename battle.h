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

char getRandomAction()
{
    return 'A'; // perfectly random
}

bool battleMenu()
{
    char fight = ' ';
    std::cout << "Battle Menu: [A]ttack - [B]lock - [S]kill \n";
    std::cin >> fight;
    switch (fight)
    {
    case 'A':
    case 'a':
        std::cout << "You have chosen [A]ttack\n";
        getRandomAction();
        // logic for opponent action
        // if op logic is attack
            //deal damage to both health
        // if op logic is block
            // block action gets priority
            // determine block v attack values
            // if block > attack = no damage
            // if block < attack = % - op health
        // if op logic is skill
            // pl deals double damage
            // op uses skill
    break;
    case 'B':
    case 'b':
        std::cout << "You have chosen [B]lock\n";
        // block action gets priority
        // logic for opponent action
        // if op logic is attack
            // determine block v attack values
            // if block > attack = no damage
            // if block < attack = % - pl health
        // if op logic is block
            // no damage
        // if op logic is skill
            // op uses skill
    break;
    case 'S':
    case 's':
        std::cout << "You have chosen [S]kill use\n";
        // logic for opponent action
        // if op logic is attack
            // deal double damage to pl
        // if op logic is block
            // no damage
        // if op logic is skill
            // op uses skill
        
    break;
    default:
        return battleMenu();
    }
    return false;
}

bool handleAttack(Character& Health, Character& Attack)
{

}

bool handleBlock(Character& Defense, Character& Health, Character& Attack)
{

}

bool handleSkill(Character& Character, Skill& Skill)
{
    
}
 

int battle (Character& Player, Character& Opponent)
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
            battleMenu();
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

    while (inBattle)
    {
        std::cout << "Choose your action!\n";
        switch (answer)
        {
        case 'A':
            inBattle = handleAttack(Player, Opponent);
            break;
        case 'B':
            inBattle = handleBlock(x, y, z);
            break;
        case 'S':
            inBattle = handleSkill(Player, Player.getSkill());
            break;
        default:
            std::cout << "That was neither. Try again! \n";
            break;

        }
    }

    return 0;
}
