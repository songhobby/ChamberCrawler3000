#include"nightelf.h"
#include "type.h"
#include "potion.h"
#include "dlc_gamecontroller.h"


// nightelf can be invisible
NightElf::NightElf(int row, int col):
  Player{111, 29, 17, row, col, NIGHTELF}{}

bool NightElf::visit (Object &object, Type type) {
    if((numOfTurn / 20) % 2 == 0){
	  getInfo().hp += 5;
    }
    return object.be_visit (*this, type);
}
Info& NightElf::getInfo () {
    if(!getPlayerInfo().potion){
		if(Character::getInfo().hp < 0){
			Character::getInfo().hp = 0;
		}
     	if(Character::getInfo().hp > 111){
	     	Character::getInfo().hp = 111;
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
	if(modifyInfo.hp > 111){
		modifyInfo.hp = 111;
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
