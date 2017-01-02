#ifndef __BLOODELF_H_
#define __BLOODELF_H_
#include"enemy.h"
#include "style.h"
#include "type.h"

class Object;

class BloodElf: public Enemy{
  public: 
  	BloodElf(int row, int col);
        bool visit (Object &object, Type type);
};


#endif
