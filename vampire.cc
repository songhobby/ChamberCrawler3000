#include"vampire.h"
#include "visitexcept.h"
#include "object.h"
#include "potion.h"

Vampire::Vampire(int row, int col):
  Player{50, 25, 25, row, col, VAMPIRE}{}

bool Vampire::visit (Object &object, Type type) {
    return object.be_visit (*this, type);
}
Info& Vampire::getInfo () {
    if(!getPlayerInfo().potion){
		if(Character::getInfo().hp < 0){
			Character::getInfo().hp = 0;
		}
//     	if(Character::getInfo().hp > 50){ //vampire has no top hp limit.
//	     	Character::getInfo().hp = 50;
//	    }

		if(Character::getInfo().atk < 0){
			Character::getInfo().atk = 0;
		} 
		if(Character::getInfo().def < 0){
			Character::getInfo().def = 0;
		}
      return Character::getInfo();
    } else {
	auto &modifyInfo = getPlayerInfo().potion->modify();
	Character::getInfo().hp = modifyInfo.hp;
//	if(modifyInfo.hp <= 0){ //potion can kill the player.
//		throw VisitExcept{"deadplayer", 0};
//	}
//	if(modifyInfo.hp > 50){ //vampire has no hp limit.
//		modifyInfo.hp = 50;
//	}

	if(modifyInfo.atk < 0){
		modifyInfo.atk = 0;
	}
	if(modifyInfo.def < 0){
		modifyInfo.def = 0;
	}
	return modifyInfo;
    }
}
