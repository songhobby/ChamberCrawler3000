#include "tile.h"
#include "aaron.h"
#include "visitexcept.h"
#include "type.h"
#include "worgen.h"
#include "forsaken.h"
#include "bloodelf.h"
#include "eason.h"
#include "nightelf.h"

Tile::Tile(int posx, int posy):Cell{posx, posy, TILE} {}

bool Tile::be_visit (Aaron& player, Type type){
	if (type == MOVE) return true;
	if (type == PICKUP) throw VisitExcept{"build", 1};
    return false;
}
bool Tile::be_visit (Shade& player, Type type){
	if (type == MOVE) return true;
    return false;
}
bool Tile::be_visit (Drow& player, Type type){
	if (type == MOVE) return true;
    return false;
}
bool Tile::be_visit (Vampire& player, Type type){
	if (type == MOVE) return true;
    return false;
}
bool Tile::be_visit (Troll& player, Type type){
	if (type == MOVE) return true;
    return false;
}
bool Tile::be_visit (Goblin& player, Type type){
	if (type == MOVE) return true;
    return false;
}
bool Tile::be_visit (Human& enemy, Type type){
	if (type == MOVE) return true;
    return false;
}
bool Tile::be_visit (Dwarf& enemy, Type type){
	if (type == MOVE) return true;
    return false;
}
bool Tile::be_visit (Halfling& enemy, Type type){
	if (type == MOVE) return true;
    return false;
}
bool Tile::be_visit (Orc& enemy, Type type){
	if (type == MOVE) return true;
    return false;
}
bool Tile::be_visit (Elf& enemy, Type type){
	if (type == MOVE) return true;

    return false;
}
bool Tile::be_visit (Small_Hoard &hoard, Type type) {
	if (type == MOVE) return true;
	return false;
}
bool Tile::be_visit (Normal_Hoard &hoard, Type type) {
	if (type == MOVE) return true;
	return false;
}
bool Tile::be_visit (Merchant_Hoard &hoard, Type type) {
	if (type == MOVE) return true;
	return false;
}

bool Tile::be_visit (Dragon& enemy, Type type){
	if (type == MOVE) return true;
    return false;
}

bool Tile::be_visit (Merchant& enemy, Type type){
	if (type == MOVE) return true;
    return false;
}

bool Tile::be_visit (Eason& enemy, Type type){
	if (type == MOVE) return true;
    return false;
}

bool Tile::be_visit (NightElf& enemy, Type type){
	if (type == MOVE) return true;
    return false;
}

bool Tile::be_visit (ForSaken& enemy, Type type){
	if (type == MOVE) return true;
    return false;
}

bool Tile::be_visit (Worgen& enemy, Type type){
	if (type == MOVE) return true;
    return false;
}

bool Tile::be_visit (BloodElf& enemy, Type type){
	if (type == MOVE) return true;
    return false;
}

