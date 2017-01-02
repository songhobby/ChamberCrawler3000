#ifndef __POTION_H__
#define	__POTION_H__
#include "item.h"
#include "info.h"


class Shade;
class Vampire;
class Drow;
class Troll;
class Goblin;
class Player;
class Aaron;
class Eason;
class NightElf;


class Potion :public Item {
	protected:
	Info info;
	std::shared_ptr<Potion> potion;// apply decorator pattern
	public:
	Info &modify ();
	std::shared_ptr<Potion> & getPotion();
	Potion (int row, int col, Style style);
	// all the treasure can be visited by player
	virtual bool be_visit(Aaron&player, Type type);
	virtual bool be_visit(Shade &player, Type type);
	virtual bool be_visit(Vampire&player, Type type);
	virtual bool be_visit(Drow&player, Type type);
	virtual bool be_visit(Troll&player, Type type);
	virtual bool be_visit(Goblin &player, Type type);
	virtual bool be_visit(Eason &player, Type type);
	virtual bool be_visit(NightElf &player, Type type);
	
	virtual ~Potion () = default;
};

#endif




