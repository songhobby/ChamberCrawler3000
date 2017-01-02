#include"player.h"
#include "potion.h"
#include <string>
#include "buff.h"
#include "human.h"
#include "dwarf.h"
#include "halfling.h"
#include "elf.h"
#include "orc.h"
#include "dragon.h"
#include "merchant.h"
#include "bloodelf.h"
#include "worgen.h"
#include "forsaken.h"

using namespace std;


Player::Player(int hp, int atk, int def, int row, int col, Style style):
Character{hp, atk, def, row, col, style}, playerInfo{0, 1, nullptr, ""}{}

void Player::levelUp(){
    playerInfo.potion = nullptr;
    playerInfo.level++;
}



Info& Player::getInfo () {
    if(!getPlayerInfo().potion){
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
	if(modifyInfo.atk < 0){
		modifyInfo.atk = 0;
	}
	if(modifyInfo.def < 0){
		modifyInfo.def = 0;
	}
	return modifyInfo;
    }
}

PlayerInfo& Player::getPlayerInfo(){
    return playerInfo;
}


bool Player::be_visit(Human& enemy, Type type){
    return be_visit_by(*this, enemy, type);
}

bool Player::be_visit(Orc& enemy, Type type){
   return be_visit_by(*this, enemy, type);

}
bool Player::be_visit(Dwarf& enemy, Type type){
   return be_visit_by(*this, enemy, type);


}
bool Player::be_visit(Halfling& enemy, Type type){
   return be_visit_by(*this, enemy, type);

}
bool Player::be_visit(Elf& enemy, Type type){
   return be_visit_by(*this, enemy, type);
}


bool Player::be_visit(Dragon& enemy, Type type){
   return be_visit_by(*this, enemy, type);

}

bool Player::be_visit(Merchant& enemy, Type type){
   return be_visit_by(*this, enemy, type);

}

bool Player::be_visit(Worgen &enemy, Type type){
    return be_visit_by(*this,enemy,type);
}
bool Player::be_visit(ForSaken &enemy, Type type){
    return be_visit_by(*this,enemy,type);
}
bool Player::be_visit(BloodElf &enemy, Type type){
    return be_visit_by(*this,enemy,type);
}
