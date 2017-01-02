#ifndef __RESTORE_HEALTH_H__
#define __RESTORE_HEALTH_H__
#include "potion.h"
#include "info.h"
class Shade;
class Drow;
class Vampire;
class Troll;
class Goblin;

class Restore_Health final:public Potion {
	public:

	Restore_Health (int posx, int posy);
};

#endif


