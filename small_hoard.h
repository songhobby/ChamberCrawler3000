#ifndef __SMALL_HOARD_H__
#define __SMALL_HOARD_H__
#include "treasure.h"
#include "type.h"
class Object;
class Shade;

class Small_Hoard final:public Treasure {
	public:
	Small_Hoard (int row, int col);
};

#endif 

