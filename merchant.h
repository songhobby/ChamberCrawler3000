#ifndef MERCHANT_H
#define MERCHANT_H
#include"enemy.h"
#include "style.h"
#include "type.h"
class Object;
class Shade;
class Drow;
class Vampire;
class Troll;
class Goblin;
class Eason;
class NightElf;
class Aaron;

class Merchant: public Enemy{
	public:
    static bool revenge;
  	Merchant (int row, int col);
        bool visit (Object &object, Type type);
	bool be_visit(Shade& , Type t);
	bool be_visit(Drow& , Type t);
	bool be_visit(Vampire& , Type t);
	bool be_visit(Troll& , Type t);
	bool be_visit(Goblin& , Type t);
	bool be_visit(Eason& , Type t);
	bool be_visit(NightElf& , Type t);
	bool be_visit(Aaron & , Type t);
	
};

#endif
