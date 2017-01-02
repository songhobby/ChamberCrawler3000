#ifndef __HORIZONTAL_WALL_H__
#define __HORIZONTAL_WALL_H__
#include "cell.h"
class Shade;
class Drow;
class Vampire;
class Troll;
class Goblin;
class Eason;




class Horizontal_Wall final:public Cell {
	public:
	Horizontal_Wall (int posx, int posy):Cell{posx, posy, HORIZONTAL_WALL} {}
	bool be_visit (Shade& player, Type type);
	bool be_visit (Aaron& player, Type type);
	bool be_visit (Eason& player, Type type);
	bool be_visit (Drow& player, Type type);
	bool be_visit (Vampire& player, Type type);
	bool be_visit (Troll& player, Type type);
	bool be_visit (Goblin& player, Type type);


};

#endif
