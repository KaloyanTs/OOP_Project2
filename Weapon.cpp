#include "Weapon.hpp"

Weapon::Weapon(unsigned y, unsigned x, unsigned bot, unsigned top, bool onBoard)
    : HeroEquipment(&GameAssets::attack_icon, y, x, top, bot, onBoard) { WeaponNameGenerator::getInstance().generateWord(name); }

void Weapon::print() const
{
    HeroEquipment::print();
    Constants::STDOUT(name)('\n');
    Equipment::print();
    Constants::STDOUT('\n');
}