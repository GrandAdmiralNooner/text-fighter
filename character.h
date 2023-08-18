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

  bool operator==(const Statblock& Other) {
    return (m_health == Other.m_health && 
      m_attack == Other.m_attack && 
      m_defense == Other.m_defense); //write the boiler plate
  }
};

class Character {
public:
// writing the actual function for creating the character
  Character (std::string name, Skill skill, float hp, float atk, float def)
    : m_name(name), m_skill(skill), m_stats(hp, atk, def) {}    
    
  friend std::ostream& operator <<(std::ostream& os, const Character& character) {
    os << character.m_name;
    return os;
  }
  
  bool operator==(const Character& Other) {
    return m_name == Other.m_name && 
    m_stats == Other.m_stats && 
    m_skill == Other.m_skill;
  }

    void printStats() const {
      std::cout << "Health: " << m_stats.m_health << "\n";
      std::cout << "Attack: " << m_stats.m_attack << "\n";
      std::cout << "Defense: " << m_stats.m_defense << "\n";
	    m_skill.printStats();
    }

     void setSkill(const Skill& skill) {
        m_skill = skill;
    }

    const Skill& getSkill() const {
        return m_skill;
    }

    std::string getName() const {
    return m_name;
    }

    float getHealth() const {
    return m_stats.m_health;
    }

    float& getAttack() {
    return m_stats.m_attack;
    }

    float& getDefense() {
    return m_stats.m_defense;
    }

    void setHealth(float healthUpdate) {
      m_stats.m_health = healthUpdate;
    }

private:
	std::string m_name{}; // curly brace initialization
	Statblock m_stats {}; // struct class in another class, nesting
	Skill m_skill{};
};