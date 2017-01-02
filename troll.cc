#include"troll.h"
#include "object.h"
#include "potion.h"

Troll::Troll(int row, int col):
  Player{120, 25, 15, row, col, TROLL}{}

bool Troll::visit (Object &object, Type type) {
   // gain 5 hp every turn
   int & hp = getInfo().hp;
   if(hp < 115){
       hp += 5;
       getPlayerInfo().action += "PC gains 5 HP every turn. ";
   } else if(115 <= hp && hp < 120){
       hp = 120;
       getPlayerInfo().action += "PC gains 5 HP every turn. ";
   }
    return object.be_visit (*this, type);
}

Info& Troll::getInfo () {
    if(!getPlayerInfo().potion){
		if(Character::getInfo().hp < 0){
			Character::getInfo().hp = 0;
		}
     	if(Character::getInfo().hp > 120){
	     	Character::getInfo().hp = 120;
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
	if(modifyInfo.hp > 120){
		modifyInfo.hp = 120;
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
