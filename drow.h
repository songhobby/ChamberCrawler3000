#ifndef __DROW_H_
#define __DROW_H_
#include "player.h"
#include "type.h"

class Drow: public Player{
  public: 
   	Drow(int row, int col);
     	bool visit(Object&, Type t);
	Info &getInfo() override;
};

#endif
