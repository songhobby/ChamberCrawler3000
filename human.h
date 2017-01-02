#ifndef __HUMAN_H_
#define __HUMAN_H_
#include"enemy.h"
#include "style.h"
#include "type.h"

class Object;

class Human: public Enemy{
  public: 
  	Human(int row, int col);
    bool visit (Object &object, Type type);
};

#endif
