#include"shade.h"
#include "visitexcept.h"
#include "object.h"
#include "potion.h"

using namespace std;



Shade::Shade(int row, int col):
  Player{125, 25, 25, row, col, SHADE}{}

bool Shade::visit(Object & obj, Type type){
	return obj.be_visit(*this, type);
}


Info& Shade::getInfo () {
    if(!getPlayerInfo().potion){
		if(Character::getInfo().hp < 0){
			Character::getInfo().hp = 0;
		}
     	if(Character::getInfo().hp > 125){
	     	Character::getInfo().hp = 125;
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
//	if(modifyInfo.hp <= 0){ //potion can kill the player
//		throw VisitExcept{"deadplayer", 0};
//	}
	if(modifyInfo.hp > 125){
		modifyInfo.hp = 125;
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
