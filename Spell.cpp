#include "Spell.hpp"

Spell::Spell(unsigned y, unsigned x, unsigned bot, unsigned top, bool onBoard, unsigned c)
    : HeroEquipment(&GameAssets::spell_icon, y, x, top, bot, onBoard), cost(c)
{
    Constants::spell_name_generator.generateWord(name);
}

void Spell::print() const
{
    HeroEquipment::print();
    Constants::STDOUT(name)('\n');
    Equipment::print();
    Constants::STDOUT("\tCost: ")(cost)('\n');
}