#ifndef __ORC_H_
#define __ORC_H_
#include"enemy.h"
#include "style.h"
#include "type.h"

class Object;

class Orc: public Enemy{
  public: 
  	Orc(int row, int col);
    bool visit (Object &object, Type type);
};

#endif
