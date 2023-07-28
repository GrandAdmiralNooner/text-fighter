#include <iostream>
#include <string>

#include "skills.h"

struct Statblock {
  Statblock(float hp,float atk, float def)
    : m_health(hp), m_attack(atk), m_defense(def){}
  
  Statblock() : Statblock(50, 5, 5){} // Delegating constructor
  
	float m_health{};
  float m_attack{};
	float m_defense{};
};

class Character {
public:
// writing the actual function for creating the character
  Character (std::string name, Skill skill, float hp, float atk, float def)
    : m_name(name), m_stats(hp, atk, def), m_skill(skill){}    
  
  friend std::ostream& operator <<(std::ostream& os, const Character& character) {
    os << character.m_name;
    return os;
  }
  
    void printStats() const {
      std::cout << "Health: " << m_stats.m_health << "\n";
      std::cout << "Attack: " << m_stats.m_attack << "\n";
      std::cout << "Defense: " << m_stats.m_defense << "\n";
	  m_skill.printStats();
    }

    std::string getName() const {
    return m_name;
    }

    float getHealth() const {
    return m_stats.m_health;
    }

    float getAttack() const {
    return m_stats.m_attack;
    }

    float getDefense() const {
    return m_stats.m_defense;
    }

    void setHealth(float healthChange) {
      m_stats.m_health = healthChange;
    }

private:
	std::string m_name{}; // curly brace initialization
	Statblock m_stats {}; // struct class in another class, nesting
	Skill m_skill{};
};
