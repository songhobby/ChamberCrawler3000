#include "potion.h"
#include <memory>
#include "pos.h"
#include "player.h"
#include "playerinfo.h"
#include "shade.h"
#include "drow.h"
#include "troll.h"
#include "vampire.h"
#include "goblin.h"
#include "visitexcept.h"
#include "buff.h"
#include "style.h"
#include "type.h"
#include "aaron.h"
#include "eason.h"
#include "nightelf.h"

using namespace std;

Potion::Potion (int posx, int posy, Style style)
	:Item{posx, posy, style} {}


Info &Potion::modify(){
    return info;
}

shared_ptr<Potion> &Potion::getPotion(){
    return potion;
}

bool Potion::be_visit (Aaron&player, Type type) {
	return be_visit_by(*this, player, type);
}	
bool Potion::be_visit (Shade &player, Type type) {
	return be_visit_by(*this, player, type);
}	

bool Potion::be_visit (Drow &player, Type type) {
	return be_visit_by(*this, player, type);

}	

bool Potion::be_visit (Troll &player, Type type) {
 	return be_visit_by(*this, player, type);

}	

bool Potion::be_visit (Vampire&player, Type type) {
 	return be_visit_by(*this, player, type);

}	

bool Potion::be_visit (Goblin &player, Type type) {
	return be_visit_by(*this, player, type);

}



bool Potion::be_visit (NightElf &player, Type type) {
	return be_visit_by(*this, player, type);

}


bool Potion::be_visit (Eason&player, Type type) {
	return be_visit_by(*this, player, type);

}



