#ifndef __DRAGON_HOARD_H__
#define __DRAGON_HOARD_H__
#include "treasure.h"
#include "style.h"
#include "type.h"
//#include "observer.h"
//#include "item.h"
//#include "object.h"
class Object;
class Shade;
class Drow;
class Vampire;
class Troll;
class Goblin;
class Eason;
class NightElf;


class Object;

class Dragon_Hoard final:public Treasure {
    bool free_pick = false;
	public:
	  Dragon_Hoard(int row, int col);
        void notify(Subject &whoNotified) override;
	bool  be_visit (Shade &player, Type type);
	bool  be_visit (Drow &player, Type type) ;
	bool  be_visit (Troll &player, Type type) ;
	bool  be_visit (Vampire&player, Type type) ;
	bool  be_visit (Goblin &player, Type type);
	bool  be_visit (Eason &player, Type type);
	bool  be_visit (NightElf &player, Type type);
};
#endif
