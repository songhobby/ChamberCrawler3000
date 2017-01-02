#ifndef __EASON_H_
#define __EASON_H_
#include"player.h"
#include "style.h"
#include "type.h"

class Object;

//drop atk by 1 every turn
class Eason: public Player{
public:
    Eason(int row, int col);
    bool visit(Object&, Type type);
	Info &getInfo() override;

};

#endif
