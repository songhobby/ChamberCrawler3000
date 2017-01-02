#include "cell.h"

bool Cell::be_visit (Aaron& player, Type type){
	if (type == MOVE) return true;
    return false;
}
