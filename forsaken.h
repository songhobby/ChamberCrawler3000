#ifndef __FORSAKEN_H_
#define __FORSAKEN_H_
#include"enemy.h"
#include "style.h"
#include "type.h"

class Object;

class ForSaken: public Enemy{
  public: 
  	ForSaken(int row, int col);
        bool visit (Object &object, Type type);
};


#endif
