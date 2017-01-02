#ifndef __WORGEN_H_
#define __WORGEN_H_
#include"enemy.h"
#include "style.h"
#include "type.h"

class Object;

class Worgen: public Enemy{
  public: 
  	Worgen(int row, int col);
        bool visit (Object &object, Type type);
};


#endif
