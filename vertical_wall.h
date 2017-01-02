#ifndef __VERTICAL_WALL_H__
#define __VERTICAL_WALL_H__
#include "cell.h"
class Shade;
class Eason;
class Drow;
class Aaron;
class Vampire;
class Troll;
class Goblin;

class Vertical_Wall final:public Cell {
	public:
	Vertical_Wall (int posx, int posy) :Cell{posx, posy, VERTICAL_WALL} {}
	bool  be_visit (Shade& player, Type type);
	bool  be_visit (Drow& player, Type type);
	bool  be_visit (Vampire& player, Type type);
	bool  be_visit (Troll& player, Type type);
	bool  be_visit (Goblin& player, Type type);
	bool  be_visit (Eason& player, Type type);
	bool  be_visit (Aaron& player, Type type);
};
#endif
