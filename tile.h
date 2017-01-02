#ifndef __TILE_H__
#define __TILE_H__
#include "cell.h"
#include "style.h"
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
class Normal_Hoard;
class Aaron;
class Eason;
class NightElf;
class Worgen;
class ForSaken;
class BloodElf;

class Tile final:public Cell {
	public:
    Tile (int posx, int posy);
        bool be_visit (Shade &player, Type type) override;
	bool be_visit (Drow &player, Type type) override;
	bool be_visit (Aaron&player, Type type) override;
	bool be_visit (Vampire &player, Type type) override;
	bool be_visit (Troll &player, Type type) override;
	bool be_visit (Goblin &player, Type type) override;
	bool be_visit (Human &enemy, Type type) override;
	bool be_visit (Dwarf &enemy, Type type) override;
	bool be_visit (Halfling &enemy, Type type) override;
	bool be_visit (Elf &enemy, Type type) override;
	bool be_visit (Orc &enemy, Type type) override;
	bool be_visit (Small_Hoard &hoard, Type type) override;
	bool be_visit (Normal_Hoard &hoard, Type type) override;
	bool be_visit (Dragon &enemy, Type type) override;
	bool be_visit (Merchant_Hoard &hoard, Type type) override;
	bool be_visit (Merchant &hoard, Type type) override;
	bool be_visit (Eason &enemy, Type type) override;
	bool be_visit (NightElf &enemy, Type type) override;
	bool be_visit (Worgen &enemy, Type type) override;
	bool be_visit (ForSaken &enemy, Type type) override;
	bool be_visit (BloodElf &enemy, Type type) override;
};

#endif
