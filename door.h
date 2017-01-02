#ifndef __DOOR_H__
#define __DOOR_H__
#include "cell.h"
#include "style.h"
#include "type.h"
class Character;
class Shade;
class Drow;
class Vampire;
class Troll;
class Goblin;
class Human;
class Dwarf;
class Halfling;
class Elf;
class Orc;
class Dragon;
class Merchant;
class Eason;
class NightElf;
class Worgen;
class ForSaken;
class BloodElf;

class Door final:public Cell {
	public:
    Door(int, int);
        bool be_visit (Shade &player, Type type) override;
	bool be_visit (Drow &player, Type type) override;
	bool be_visit (Vampire &player, Type type) override;
	bool be_visit (Troll &player, Type type) override;
	bool be_visit (Goblin &player, Type type) override;
	bool be_visit (Eason &enemy, Type type) override;
	bool be_visit (NightElf &enemy, Type type) override;
	bool be_visit (Worgen &enemy, Type type) override;
	bool be_visit (ForSaken &enemy, Type type) override;


};

#endif
