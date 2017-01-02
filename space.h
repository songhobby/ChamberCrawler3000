#ifndef __SPACE_H__
#define __SPACE_H__
#include "cell.h"
class Aaron;
class Eason;

class Space final:public Cell{
	public:
	Space (int posx, int posy):Cell{posx, posy, SPACE} {}
	bool  be_visit (Shade& player, Type type);
	bool  be_visit (Aaron& player, Type type);
	bool  be_visit (Drow& player, Type type);
	bool  be_visit (Vampire& player, Type type);
	bool  be_visit (Troll& player, Type type);
	bool  be_visit (Goblin& player, Type type);
	bool  be_visit (Eason& player, Type type);

};

#endif
