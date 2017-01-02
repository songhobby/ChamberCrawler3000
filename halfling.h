#ifndef __HALFLING_H_
#define __HALFLING_H_
#include"enemy.h"
#include "style.h"
#include "type.h"

class Object;

class Halfling: public Enemy{
  public: 
  	Halfling(int row, int col);
    bool visit (Object &object, Type type);
};


#endif
