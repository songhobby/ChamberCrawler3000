#ifndef __DWARF_H_
#define __DWARF_H_
#include"enemy.h"
#include "style.h"
#include "type.h"

class Object;

class Dwarf: public Enemy{
  public: 
  	Dwarf(int row, int col);
   	bool visit(Object& object, Type type);
};


#endif
