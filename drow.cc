#include"drow.h"
#include "style.h"
#include "object.h"
#include "potion.h"
Drow::Drow(int row, int col):
  Player{150, 25, 15, row, col, DROW}{}

bool Drow::visit (Object &object, Type type) {
	return	object.be_visit (*this, type);
}

Info& Drow::getInfo () {
    if(!getPlayerInfo().potion){
		if(Character::getInfo().hp < 0){
			Character::getInfo().hp = 0;
		}
     	if(Character::getInfo().hp > 150){
	     	Character::getInfo().hp = 150;
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
//		modifyInfo.atk = 0;
//	}
	if(modifyInfo.hp > 150){
		modifyInfo.hp = 150;
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
