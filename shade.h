#ifndef __SHADE_H_
#define __SHADE_H_
#include"player.h"
#include "style.h"
#include "type.h"
class Object;


class Shade: public Player{
public:
    Shade(int row, int col);
    bool visit(Object&, Type type);
	Info &getInfo() override;
};

#endif
