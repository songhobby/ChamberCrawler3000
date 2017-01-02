#include "stair.h"
#include "visitexcept.h"
#include "aaron.h"
#include "worgen.h"
#include "forsaken.h"
#include "bloodelf.h"
#include "eason.h"
#include "nightelf.h"


Stair::Stair (int posx, int posy):Cell{posx, posy, STAIR} {}


bool Stair::be_visit (Aaron& player, Type type){
	if (type == MOVE){
	    throw VisitExcept{"stair",0};
	}
    return false;
}
bool Stair::be_visit (Shade& player, Type type){
	if (type == MOVE){
	    throw VisitExcept{"stair",0};
	}
    return false;
}
bool Stair::be_visit (Drow& player, Type type){
	if (type == MOVE){
	    throw VisitExcept{"stair",0};
	}
    return false;
}

bool Stair::be_visit (Vampire& player, Type type){
	if (type == MOVE){
	    throw VisitExcept{"stair",0};
	}
    return false;
}
bool Stair::be_visit (Troll& player, Type type){
	if (type == MOVE){
	    throw VisitExcept{"stair",0};
	}
    return false;
}

bool Stair::be_visit (Goblin& player, Type type){
	if (type == MOVE){
	    throw VisitExcept{"stair",0};
	}
    return false;
}
bool Stair::be_visit (Eason& enemy, Type type){
	if (type == MOVE)  {
	    throw VisitExcept{"stair",0};
	}
    return false;
}
bool Stair::be_visit (NightElf& enemy, Type type){
	if (type == MOVE)  {
	    throw VisitExcept{"stair",0};
	}
    return false;
}

