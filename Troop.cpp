#include "Troop.hpp"

void Troop::print(float attackBonus) const
{
    // p(GameAssets::stats_header, GameAssets::stats_count);
    Constants::STDOUT("HEALTH\tATTACK\tMAGIC\n")(health)('\t')((1 + attackBonus) * attack)('\t')(mana)('\n');
}

float Troop::determineStat(unsigned lvl, float init, float perLevel) const
{
    for (unsigned i = 1; i < lvl; ++i)
        init *= perLevel;
    return init;
}

void Troop::takeDamage(float dmg)
{
    if (dmg > health)
        health = 0;
    health -= dmg;
}
