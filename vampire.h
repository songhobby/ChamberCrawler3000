#ifndef __VAMPIRE_H_
#define __VAMPIRE_H_
#include "player.h"
#include "type.h"
class Vampire: public Player{
  public:
  	Vampire(int row, int col); 
   	bool visit(Object&, Type t);
	Info &getInfo() override;

};

#endif
