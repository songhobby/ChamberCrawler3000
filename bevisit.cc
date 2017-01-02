#include"bevisit.h"
#include"player.h"
#include"enemy.h"
#include <string>
#include "character.h"
#include "playerinfo.h"
#include "type.h"
#include "style.h"


template<typename Visit, typename Bevisit, typename Type>
bool be_visit_by(Visit & v1, Bevisit & v2, Type t){
    if(t == ATTACK){
	return be_attack(v1, v2);
    }
    return false;
}



void be_attack(Player &player, Enemy &enemy){
    int damage = player.getDamage(enemy.getInfo().atk, player.getInfo().def);
    player.getInfo().hp -= damage;
    std::string newAction = getString(enemy.getPos().style) + 
           " deals (" + std::to_string(damage) + ") damage to PC. ";
    player.getPlayerInfo().action += newAction;
    if(player.getInfo().hp <= 0){
	throw true;
    } else {
	return true;
    }
}

void be_attack(Enemy &enemy, Player &player){  
  int damage = enemy.getDamage(player.getInfo().atk, enemy.getInfo().def);
    enemy.getInfo().hp -= damage;
    std::string newAction = "PC deals (" + std::to_string(damage) +
               ") damage to " + getString(enemy.getPos().style)  + ". ";
    player.getPlayerInfo().action += newAction;
    if(enemy.getInfo().hp <= 0){
	//visitexcept
    } else {
	return true;
    }
}
