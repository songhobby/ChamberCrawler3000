#ifndef __ELF_H_
#define __ELF_H_
#include"enemy.h"
#include "style.h"
#include "type.h"

class Object;

class Elf: public Enemy{
  public: 
  	Elf (int row, int col);
    bool visit (Object &object, Type type);

};

#endif
