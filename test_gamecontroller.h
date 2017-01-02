#ifndef _T_TGAME_H_
#define _T_TGAME_H_
#include <iostream>
#include <string>
#include "testfloor.h"
#include "display.h"
#include "gamecontroller.h"

class Object;

class T_GameController: public GameController{
	T_Floor t_floor;
	public:
	T_GameController();
	void play(std::string file) override;
};

#endif
