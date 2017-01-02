#ifndef __GOBLIN_H_
#define __GOBLIN_H_
#include "player.h"
#include "type.h"

class Goblin: public Player{
  public:
  	Goblin(int row, int col); 
  	bool visit(Object&, Type t);
	Info &getInfo() override;
};

#endif
