#include "door.h"
#include "eason.h"
#include "nightelf.h"



Door::Door(int posx, int posy):Cell(posx, posy, DOOR) {}

bool Door::be_visit (Shade& player, Type type){
	if (type == MOVE) return true;
    return false;
}
bool Door::be_visit (Drow& player, Type type){
	if (type == MOVE) return true;
    return false;
}
bool Door::be_visit (Vampire& player, Type type){
	if (type == MOVE) return true;
    return false;
}
bool Door::be_visit (Troll& player, Type type){
	if (type == MOVE) return true;
    return false;
}
bool Door::be_visit (Goblin& player, Type type){
	if (type == MOVE) return true;
    return false;
}


bool Door::be_visit (Eason& enemy, Type type){
	if (type == MOVE) return true;
    return false;
}
bool Door::be_visit (NightElf& enemy, Type type){
	if (type == MOVE) return true;
    return false;
}
bool Door::be_visit (ForSaken& enemy, Type type){
	if (type == MOVE) return true;
    return false;
}
bool Door::be_visit (Worgen& enemy, Type type){
	if (type == MOVE) return true;
    return false;
}

