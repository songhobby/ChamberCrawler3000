#include "aaron.h"
#include "object.h"
#include "style.h"

Aaron::Aaron (int row, int col):
  Player{1000, 1000, 1000, row, col, AARON}{}

bool Aaron::visit(Object & obj, Type type){
	return obj.be_visit(*this, type);
}

