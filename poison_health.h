#ifndef __POISON_HEALTH_H__
#define __POISON_HEALTH_H__
#include "potion.h"
#include "info.h"
class Shade;
class Drow;
class Vampire;
class Troll;
class Goblin;

class Poison_Health final:public Potion {
	public:
	Poison_Health (int posx, int posy);
};

#endif


