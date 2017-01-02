#ifndef __TROLL_H_
#define __TROLL_H_
#include "player.h"
#include "type.h"

class Troll: public Player{
  public:
  	Troll(int row, int col); 
     	bool visit(Object&, Type t);

	Info &getInfo() override;

};

#endif
