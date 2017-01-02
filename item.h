#ifndef __ITEM_H__
#define __ITEM_H__
#include "object.h"

class Item :public Object {
	public:
	Item(int row, int col, Style style)
		:Object{row, col, style} {}
	virtual ~Item() = default;
};

#endif
