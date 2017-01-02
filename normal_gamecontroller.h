#ifndef _N_NGAME_H_
#define _N_NGAME_H_
#include <iostream>
#include <string>
#include "floor1.h"
#include "display.h"
#include "gamecontroller.h"

class Object;

class N_GameController: public GameController{
	N_Floor n_floor;
	public:
	N_GameController();
	void play(std::string file) override;
};

#endif
