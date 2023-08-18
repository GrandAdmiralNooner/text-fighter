#include <iostream>
#include <string>
#include "character.h"

//skills - name, cd, add attack, add defense, add health

// {"Fighter", {"Two-Weapon", 2, 4, 0, 0}, 50, 8, 6},
// {"Ranger", {"Breaker", 2, 5, 0, 0}, 50, 7, 5},
// {"Cleric", {"Intervention", 2, 4, 2, 12}, 50, 4, 6},
// {"Sorcerer", {"Fireball", 3, 12, 0, 0}, 50, 6, 4}

// need actionAvailable check for skills on cooldown
// need to return adjusted values back to default after 2 turns
// from battle.h, how would each class call the appropriate changes?

void useSkillFighter (Character& Player)
{
    // add a 2 turn cooldown
    // add +4 attack for 2 turns
}
void useSkillRanger (Skill& Opponent)
{
    // add a 2 turn cooldown
    // add +5 attack for 2 turns
}
void useSkillCleric (Skill& Skills)
{  
    // add a 2 turn cooldown
    // add +4 attack for 2 turns
    // add +2 defense for 2 turns
    // add +12 health self for 2 turns
}
void useSkillSorcerer (Skill& Skills)
{
    // add a 3 turn cooldown
    // deal 12 damage directly once
}