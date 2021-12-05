#ifndef PLAYER_H
#define PLAYER_H
#include "Creature.h"

class Player : public Creature
{
private:
    int m_level{1};

public:
    Player(std::string name) : Creature{name, '@', 10, 1, 0}
    {
    }

    void levelUp()
    {
        ++m_level;
        ++m_damage;
    }

    int getLevel() const { return m_level; }

    bool hasWon() const
    {
        return (m_level >= 20);
    }
};

#endif