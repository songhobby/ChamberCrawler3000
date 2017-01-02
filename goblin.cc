#include"goblin.h"
#include "object.h"
#include "potion.h"

Goblin::Goblin(int row, int col):
  Player{110, 15, 20, row, col, GOBLIN}{}

bool Goblin::visit (Object &object, Type type) {
	object.be_visit (*this, type);
}
Info& Goblin::getInfo () {
    if(!getPlayerInfo().potion){
		if(Character::getInfo().hp < 0){
			Character::getInfo().hp = 0;
		}
     	if(Character::getInfo().hp > 110){
	     	Character::getInfo().hp = 110;
	    }

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
//	if(modifyInfo.hp < 0){
//		modifyInfo.hp = 0;
//	}
	if(modifyInfo.hp > 110){
		modifyInfo.hp = 110;
	}

	if(modifyInfo.atk < 0){
		modifyInfo.atk = 0;
	}
	if(modifyInfo.def < 0){
		modifyInfo.def = 0;
	}
	return modifyInfo;
    }
}
