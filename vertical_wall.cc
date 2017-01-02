#include "vertical_wall.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
#include "aaron.h"
#include "visitexcept.h"
#include "eason.h"

bool Vertical_Wall::be_visit (Shade& player, Type type){
	if (type == MOVE){
	    player.getPlayerInfo().action += "PC cannot go through the wall. ";
	}
    return false;
}
bool Vertical_Wall::be_visit (Aaron& player, Type type){
	if (type == MOVE){
	    player.getPlayerInfo().action += "PC cannot go through the wall. ";
	}
	else if (type == ATTACK){
		throw VisitExcept{"destroy", 1};
	}
	return false;
}
bool Vertical_Wall::be_visit (Drow& player, Type type){
	if (type == MOVE){
	    player.getPlayerInfo().action += "PC cannot go through the wall. ";
	}
    return false;
}

bool Vertical_Wall::be_visit (Vampire& player, Type type){
	if (type == MOVE){
	    player.getPlayerInfo().action += "PC cannot go through the wall. ";
	}
    return false;
}
bool Vertical_Wall::be_visit (Troll& player, Type type){
	if (type == MOVE){
	    player.getPlayerInfo().action += "PC cannot go through the wall. ";
	}
    return false;
}

bool Vertical_Wall::be_visit (Goblin& player, Type type){
	if (type == MOVE){
	    player.getPlayerInfo().action += "PC cannot go through the wall. ";
	}
    return false;
}
bool Vertical_Wall::be_visit (Eason& player, Type type){
	if (type == MOVE){
		return true;
	}
    return false;
}
