#ifndef __AARON_H__
#define __AARON_H__
#include "player.h"
#include "type.h"
class Object;

class Aaron :public Player {
	public:
    Aaron(int row, int col);
    bool visit(Object&, Type type);
};

#endif
