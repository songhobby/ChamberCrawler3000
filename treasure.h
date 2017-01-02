#ifndef __TREASURE_H__
#define __TREASURE_H__
#include "item.h"
#include "type.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
class Aaron;
class Eason;
class NightElf;

class Treasure :public Item {
	int gold;
	public:
	int getGold ();
	Treasure (int pos, int posy, Style style, int gold);
	// all the treasure can be visited by player
	virtual bool be_visit(Shade &player, Type type);
	virtual bool be_visit(Aaron&player, Type type);
	virtual bool be_visit(Vampire&player, Type type);
	virtual bool be_visit(Drow&player, Type type);
	virtual bool be_visit(Troll&player, Type type);
	virtual bool be_visit(Goblin &player, Type type);
	virtual bool be_visit(Eason &player, Type type);
	virtual bool be_visit(NightElf &player, Type type);
	virtual ~Treasure () = default;
};

#endif
