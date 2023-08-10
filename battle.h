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

char getRandomAction()
{
    int num = rand() % 99 + 1;
    if (num <=65 )
    {
        return 'A';
    }
    else if (num >=66 && num <= 90)
    {
        return 'B';
    }
    else
        return 'S';
}

bool handleAttack(Character& Player, Character& Opponent)
{
    int curPlaHP = Player.getHealth();
    int curOppHP = Opponent.getHealth();
    int plaAtk = Player.getAttack();
    int oppAtk = Opponent.getAttack();

    switch (getRandomAction())
    {
    case 'A':
        std::cout << "opponent choice [A]ttack \n";
        // opponent hp - player attack
        curOppHP -= plaAtk;
        Opponent.setHealth(curOppHP);
        // player hp - opponent attack
        curPlaHP -= oppAtk;
        Player.setHealth(curPlaHP);
        std::cout << "You strike your opponent first. Your opponent's HP is: "<<  (curOppHP > 0 ? curOppHP : 0) << "\n";
        std::cout << "Your opponent strikes you back. Your HP is: " << (curPlaHP > 0 ? curPlaHP : 0) << "\n";
    break;
    case 'B':
        std::cout << "opponent choice [B]lock \n";
        // opphp - (player atk - opponent def)
        if (plaAtk > Opponent.getDefense())
        {
            int plaDmg = plaAtk - Opponent.getDefense();
            curOppHP -= plaDmg;
            Opponent.setHealth(curOppHP);
            std::cout << "A part of the attack has gone through. \n";
            std::cout << "Your opponent's HP is: "<< (curOppHP > 0 ? curOppHP : 0) << "\n";
            std::cout << "Your HP is: " << (curPlaHP > 0 ? curPlaHP : 0) << "\n";
        }
        else
            std::cout << "No damage was exchanged \n";
                
    break;
    case 'S':
        std::cout << "opponent choice [S]kill. \n";
        // player atk*2 - opponent hp
        curOppHP -= plaAtk * 2;
        Opponent.setHealth(curOppHP);
        std::cout << "You deal double the damage.\n";
        std::cout << "Your opponent's HP is: "<< (curOppHP > 0 ? curOppHP : 0) << "\n";
        std::cout << "Your HP is: " << (curPlaHP > 0 ? curPlaHP : 0) << "\n";
        if (curOppHP > 0)
        {
        // opponet skill use
        std::cout << "Your opponent has successfully cast their skill:"<< Opponent.getSkill() <<"\n";
        }
        else
            break;

    break;
    default:
        return true;
    }
    return false; //return bool for character death
}

bool handleBlock(Character& Player, Character& Opponent)
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

bool handleSkill(Character& Player, Character& Opponent)
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

char playerChoice(Character& Player, Character& Opponent)
{
    char choice = ' ';
    std::cout << "Battle Menu: [A]ttack - [B]lock - [S]kill \n";
    std::cin >> choice;
    
    if(choice == 'A' || choice == 'a'){
        handleAttack(Player, Opponent);
        return 'A';
    }
    else if(choice == 'B' || choice == 'b'){
        return 'B';
    }
    else if(choice == 'S' || choice == 's'){
        return 'S';
    }
    else
        return playerChoice(Player, Opponent);
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
            playerChoice(Player, Opponent);
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

    // attempting to see if inBattle loops

    while (Player.getHealth() > 0 && Opponent.getHealth() > 0)
    {
       playerChoice(Player, Opponent);

    // Checking to see the win/loss message

        if (Player.getHealth() <=0)
        {
            std::cout << "You have lost.\n";
            std::cout << "Better luck next time.\n";
            inBattle = false;
        } 
        else if (Opponent.getHealth() <= 0)
        {
            std::cout <<"Congratulations!\n";
            std::cout <<"You are victorius!\n";
            inBattle = false;
        } 
        else if (Player.getHealth() <=0 && Opponent.getHealth() <= 0)
        {
            std::cout << "It was a tie!\n";
            std::cout << "... and you both lost ... \n";
            inBattle = false;
        }
    
    }

}