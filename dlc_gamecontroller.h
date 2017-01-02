#ifndef _D_GAME_H_
#define _D_GAME_H_
#include <iostream>
#include <string>
#include "floor2.h"
#include "gamecontroller.h"

class D_GameController: public GameController{
	D_Floor d_floor;
	public:
	D_GameController();
	void play(std::string file) override;
};


extern	int numOfTurn; 
#endif
