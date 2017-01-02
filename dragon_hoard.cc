#include "dragon_hoard.h"
#include "type.h"
#include "buff.h"
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


using namespace std;

Dragon_Hoard::Dragon_Hoard (int row, int col)
	:Treasure{row, col, DRAGON_HOARD, 6} {}


void Dragon_Hoard::notify(Subject &whoNotified){ 
    free_pick = true;
}


bool Dragon_Hoard::be_visit (Shade &player, Type type) {
	if(type != MOVE || free_pick){
	  return be_visit_by (*this, player, type);
	} else {
	    player.getPlayerInfo().action = "PC cannot pick up DH when D is alive. ";
	    return true;
	}
}	
bool Dragon_Hoard::be_visit (Drow &player, Type type) {
	if(type != MOVE || free_pick){
	  return be_visit_by (*this, player, type);
	} else {
	    player.getPlayerInfo().action = "PC cannot pick up DH when D is alive. ";
	    return true;
	}
}	
bool Dragon_Hoard::be_visit (Troll &player, Type type) {
	if(type != MOVE || free_pick){
	  return be_visit_by (*this, player, type);
	} else {
	    player.getPlayerInfo().action = "PC cannot pick up DH when D is alive. ";
	    return true;
	}
}	
bool Dragon_Hoard::be_visit (Vampire&player, Type type) {
	if(type != MOVE || free_pick){
	  return be_visit_by (*this, player, type);
	} else {
	    player.getPlayerInfo().action = "PC cannot pick up DH when D is alive. ";
	    return true;
	}
}	
bool Dragon_Hoard::be_visit (Goblin &player, Type type) {
	if(type != MOVE || free_pick){
	  return be_visit_by (*this, player, type);
	} else {
	    player.getPlayerInfo().action = "PC cannot pick up DH when D is alive. ";
	    return true;
	}
}	

bool Dragon_Hoard::be_visit (Eason &player, Type type) {
	if(type != MOVE || free_pick){
	  return be_visit_by (*this, player, type);
	} else {
	    player.getPlayerInfo().action = "PC cannot pick up DH when D is alive. ";
	    return true;
	}
}

bool Dragon_Hoard::be_visit (NightElf &player, Type type) {
	if(type != MOVE || free_pick){
	  return be_visit_by (*this, player, type);
	} else {
	    player.getPlayerInfo().action = "PC cannot pick up DH when D is alive. ";
	    return true;
	}
}
