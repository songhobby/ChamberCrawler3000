#include "treasure.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
#include "buff.h"
#include "visitexcept.h"
#include "aaron.h"
#include "eason.h"
#include "nightelf.h"

Treasure::Treasure (int row, int col, Style style, int gold) 
		:Item{row, col, style}, gold{gold} {}

int Treasure::getGold () { return gold; }


bool Treasure::be_visit (Shade &player, Type type) {
	return be_visit_by (*this, player, type);
}	

bool Treasure::be_visit (Aaron &player, Type type) {
	return be_visit_by (*this, player, type);
}	

bool Treasure::be_visit (Drow &player, Type type) {
	return be_visit_by (*this, player, type);
}	

bool Treasure::be_visit (Troll &player, Type type) {
	return be_visit_by (*this, player, type);
}	

bool Treasure::be_visit (Vampire&player, Type type) {
	return be_visit_by (*this, player, type);
}	

bool Treasure::be_visit (Goblin &player, Type type) {
	return be_visit_by (*this, player, type);
}	

bool Treasure::be_visit (Eason &player, Type type) {
	return be_visit_by (*this, player, type);
}

bool Treasure::be_visit (NightElf &player, Type type) {
	return be_visit_by (*this, player, type);
}
