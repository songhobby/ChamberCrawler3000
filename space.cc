#include "space.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
#include "aaron.h"
#include "visitexcept.h"
#include "eason.h"

bool Space::be_visit (Aaron& player, Type type){
	if (type == MOVE){
	    player.getPlayerInfo().action += "PC cannot go into the space ";
	} else if (type == PICKUP) {
		throw VisitExcept{"build2", 1};
	}
    return false;
}
bool Space::be_visit (Shade& player, Type type){
	if (type == MOVE){
	    player.getPlayerInfo().action += "PC cannot go into the space ";
	}
    return false;
}
bool Space::be_visit (Drow& player, Type type){
	if (type == MOVE){
	    player.getPlayerInfo().action += "PC cannot go into the space ";
	}
    return false;
}

bool Space::be_visit (Vampire& player, Type type){
	if (type == MOVE){
	    player.getPlayerInfo().action += "PC cannot go into the space ";
	}
    return false;
}
bool Space::be_visit (Troll& player, Type type){
	if (type == MOVE){
	    player.getPlayerInfo().action += "PC cannot go into the space ";
	}
    return false;
}

bool Space::be_visit (Goblin& player, Type type){
	if (type == MOVE){
	    player.getPlayerInfo().action += "PC cannot go into the space ";
	}
    return false;
}
bool Space::be_visit (Eason& player, Type type){
	if (type == MOVE){
		return true;
	}
    return false;
}
