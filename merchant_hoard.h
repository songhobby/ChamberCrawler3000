#ifndef __MERCHANT_HOARD_H__
#define __MERCHANT_HOARD_H__
#include "treasure.h"
#include "type.h"
class Object;
class Shade;

class Merchant_Hoard final:public Treasure {
	public:
	Merchant_Hoard (int row, int col);
};

#endif 

