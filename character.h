#ifndef CHARACTER_H
#define CHARACTER_H

#include"info.h"
#include"object.h"

struct PlayerInfo;

class Character: public Object{
    Info information;
	public:
	Character(int hp, int atk, int def, int row, int col, Style style);
	virtual Info& getInfo();
	virtual ~Character() = default;
};




#endif
