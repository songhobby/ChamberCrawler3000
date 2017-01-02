#ifndef _GAMECONTROLLER_H_
#define _GAMECONTROLLER_H_
#include <iostream>
#include <string>
#include "floor1.h"
#include "display.h"

class GameController{
	protected:
	Display display;
	public:
	GameController();
	virtual void play(std::string file) = 0;
	virtual ~GameController() = default;
};

#endif
