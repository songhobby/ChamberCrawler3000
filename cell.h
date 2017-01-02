#ifndef __CELL_H__
#define __CELL_H__
#include "object.h"
#include "type.h"
class Aaron;

class Cell :public Object {
public:
 	Cell (int posx, int posy, Style style):Object(posx, posy, style){}
	virtual ~Cell () = default;
	virtual bool be_visit (Aaron &player, Type type) override;

};

#endif
