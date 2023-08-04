#include <iostream>
#include <string>

struct Skillblock {
  Skillblock(float cd, float add_atk, float add_def, float add_hp)
    : m_cooldown(cd), m_add_attack(add_atk), m_add_defense(add_def), m_add_health(add_hp){}
  
  Skillblock() : Skillblock(0, 0, 0, 0){} // Delegating constructor
  
  float m_cooldown{};
  float m_add_attack{};
  float m_add_defense{};
  float m_add_health{};
};

class Skill
{
public:
    Skill() : m_sname(""), m_skills(0, 0, 0, 0) {}
    Skill (std::string sname,float cd, float add_atk, float add_def, float add_hp)
        : m_sname (sname), m_skills(cd, add_atk, add_def, add_hp){}

friend std::ostream& operator <<(std::ostream& os, const Skill& skills) {
    os << skills.m_sname;
    return os;
}

void printStats() const {
    std::cout << "Skill: " << m_sname << '\n';
}

std::string getSname() const {
return m_sname;
}

float getCooldown() const {
    return m_skills.m_cooldown;
    }
float getAddAttack() const {
    return m_skills.m_add_attack;
    }
float getAddDefense() const {
    return m_skills.m_add_defense;
    }
float getAddHP() const {
    return m_skills.m_add_health;
    }

private:
    std::string m_sname{};
    Skillblock m_skills{};

};