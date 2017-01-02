#ifndef __PLAYER_H_
#define __PLAYER_H_
#include<string>
#include "character.h"
#include "playerinfo.h"
#include "type.h"
#include "style.h"

class Human;
class Dwarf;
class Halfling;
class Elf;
class Orc;
class Dragon;
class Merchant;
class BloodElf;
class Worgen;
class ForSaken ;

class Player: public Character{
  	PlayerInfo playerInfo;
  public: 
    	Player(int hp, int atk, int def, int row, int col, Style style);
    	virtual ~Player() = default;
	
	virtual Info& getInfo () override;//from character class
    	PlayerInfo& getPlayerInfo();// gold, level, potion, action
   	void levelUp();

	// player has be_visit method for every enemy
	// every concrete player will have visit method
	virtual bool be_visit(Human& , Type t) override;
	virtual bool be_visit(Dwarf& , Type t) override;
	virtual bool be_visit(Halfling& , Type t) override;
	virtual bool be_visit(Elf& , Type t) override;
	virtual bool be_visit(Orc& , Type t) override;
	virtual bool be_visit(Dragon& , Type t) override;
	virtual bool be_visit(Merchant& , Type t) override;
	virtual bool be_visit(BloodElf& , Type t) override;
	virtual bool be_visit(ForSaken& , Type t) override;
	virtual bool be_visit(Worgen& , Type t) override;

};

#endif
