#include"eason.h"
#include "type.h"
#include "potion.h"
Eason::Eason(int row, int col):
  Player{2, 2, 2, row, col, EASON}{}

bool Eason::visit (Object &object, Type type) {
//	if(getInfo().atk > 0){

     	getInfo().atk -= 1;
//	}
	return object.be_visit (*this, type);
}
Info& Eason::getInfo () {
    if(!getPlayerInfo().potion){
		if(Character::getInfo().hp < 0){
			Character::getInfo().hp = 0;
		}
     	if(Character::getInfo().hp > 2){
	     	Character::getInfo().hp = 2;
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
	if(modifyInfo.hp > 2){
		modifyInfo.hp = 2;
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
