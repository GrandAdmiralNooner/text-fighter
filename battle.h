#include <iostream>
#include <cstdlib>
#include <ctime>

//function type matters
// int, char, void, bool - use the right one
// does it makes sense? default should be void not int

//new assignment read functions and returns more

//break habits
//Reminder: character - name, [skill], hp, attack, defense
//Reminder: skills - name, cd, add attack, add defense, add health

constexpr const char* RANDOM_CHOICE_A_MESSAGE = "Your Opponent chooses to [ATTACK]! \n";
constexpr const char* RANDOM_CHOICE_B_MESSAGE = "Your Opponent chooses to [BLOCK]! \n";
constexpr const char* RANDOM_CHOICE_S_MESSAGE = "Your Opponent uses a [SKILL]! \n";
constexpr const char* PLAYER_HIT_FIRST_MESSAGE = "You strike first! \n";
constexpr const char* OPPONENT_RETALIATION_MESSAGE = "Your opponent strikes you back! \n";
constexpr const char* NO_DAMAGE_MESSAGE = "No damage was exchanged. \n";
constexpr const char* PLAYER_SKILL_MESSAGE = "You cast your skill: ";
constexpr const char* OPPONENT_SKILL_MESSAGE = "Your opponent casts their skill: ";

void printHealth(int currentOpponentHP, int currentPlayerHP) {
    std::cout << "Your opponent's HP is: " << std::max(currentOpponentHP, 0) << "\n";
    std::cout << "Your HP is: " << std::max(currentPlayerHP, 0) << "\n";
}

char getRandomAction() // should be constants - at top of file
{
    int num = rand() % 99;
    // std::cout << num << '\n';
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
// write a test driver - automation
bool handleAttack(Character& Player, Character& Opponent)
{
    int currentPlayerHP = Player.getHealth();
    int currentOpponentHP = Opponent.getHealth();
    int playerAttack = Player.getAttack();
    int opponentAttack = Opponent.getAttack();

    switch (getRandomAction())
    {
    case 'A':
        std::cout << RANDOM_CHOICE_A_MESSAGE;
        // opponent hp - player attack
        currentOpponentHP -= playerAttack;
        Opponent.setHealth(currentOpponentHP);
        // player hp - opponent attack
        currentPlayerHP -= opponentAttack;
        Player.setHealth(currentPlayerHP);
        std::cout << PLAYER_HIT_FIRST_MESSAGE;
        std::cout << OPPONENT_RETALIATION_MESSAGE;
        printHealth(currentOpponentHP, currentPlayerHP);
    break;
    case 'B':
        std::cout << RANDOM_CHOICE_B_MESSAGE;
        // opphp - (player atk - opponent def)
        if (playerAttack > Opponent.getDefense())
        {
            int plaDmg = playerAttack - Opponent.getDefense();
            currentOpponentHP -= plaDmg;
            Opponent.setHealth(currentOpponentHP);
            std::cout << "A part of your attack went through. \n";
            printHealth(currentOpponentHP, currentPlayerHP);
        }
        else
            std::cout << NO_DAMAGE_MESSAGE;     
    break;
    case 'S':
        std::cout << RANDOM_CHOICE_S_MESSAGE;
        // player atk*2 - opponent hp
        currentOpponentHP -= playerAttack * 2;
        Opponent.setHealth(currentOpponentHP);
        std::cout << "You deal double the damage.\n";
        printHealth(currentOpponentHP, currentPlayerHP);
        if (currentOpponentHP > 0)
        {
        // opponet skill use
        std::cout << OPPONENT_SKILL_MESSAGE << Opponent.getSkill() <<"\n";
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
    int currentPlayerHP = Player.getHealth();
    int currentOpponentHP = Opponent.getHealth();
    int playerAttack = Player.getAttack();
    int opponentAttack = Opponent.getAttack();
    
    switch (getRandomAction())
    {
    case 'A':
        std::cout << RANDOM_CHOICE_A_MESSAGE;
        // (opponent atk - player def) - player hp 
        if (opponentAttack > Player.getDefense())
        {
            int oppDmg = opponentAttack - Player.getDefense();
            currentPlayerHP -= oppDmg;
            Player.setHealth(currentPlayerHP);
            std::cout << "A part of their attack went through. \n";
            printHealth(currentOpponentHP, currentPlayerHP);
        }
        else
            std::cout << NO_DAMAGE_MESSAGE;

    break;
    case 'B':
        std::cout << RANDOM_CHOICE_B_MESSAGE;
        std::cout << "You idiots both blocked. Congrats! Nothing happens. \n";
        printHealth(currentOpponentHP, currentPlayerHP);
    break;
    case 'S':
        std::cout << RANDOM_CHOICE_S_MESSAGE;
        std::cout << OPPONENT_SKILL_MESSAGE << Opponent.getSkill() <<"\n";
        std::cout << "You successfully block. \n";
        printHealth(currentOpponentHP, currentPlayerHP);      
    break;
    default:
        return true;
    }
    return false; //return bool for character death
    }

bool handleSkill(Character& Player, Character& Opponent)
    {
    int currentPlayerHP = Player.getHealth();
    int currentOpponentHP = Opponent.getHealth();
    int playerAttack = Player.getAttack();
    int opponentAttack = Opponent.getAttack();

    switch (getRandomAction())
    {
    case 'A':
        std::cout << RANDOM_CHOICE_A_MESSAGE;
        // opponent atk*2 - player hp
        // player skill use
        currentPlayerHP -= opponentAttack * 2;
        Player.setHealth(currentPlayerHP);
        std::cout << "You take double the damage.\n";
        printHealth(currentOpponentHP, currentPlayerHP);
        if (currentPlayerHP > 0)
        {
        // player skill use
        std::cout << PLAYER_SKILL_MESSAGE << Player.getSkill() <<"\n";
        }
        else
            break;        
    break;
    case 'B':
        std::cout << RANDOM_CHOICE_B_MESSAGE;
        // opponent use block
        // player skill use
        std::cout << PLAYER_SKILL_MESSAGE<< Player.getSkill() <<"\n";
        std::cout << "Your opponent successfully blocks. \n";
        printHealth(currentOpponentHP, currentPlayerHP);
    break;
    case 'S':
        std::cout << RANDOM_CHOICE_S_MESSAGE;
        // player skill use
        // opp skill use
        std::cout << PLAYER_SKILL_MESSAGE<< Player.getSkill() <<"\n";
        std::cout << OPPONENT_SKILL_MESSAGE << Opponent.getSkill() <<"\n";
        std::cout << "The skills cancel each other out! \n";
        printHealth(currentOpponentHP, currentPlayerHP);       
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
        handleBlock(Player, Opponent);
        return 'B';
    }
    else if(choice == 'S' || choice == 's'){
        handleSkill(Player, Opponent);
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
            Opponent.setHealth(0);
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