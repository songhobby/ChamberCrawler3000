#include"worgen.h"
#include "type.h"


Worgen::Worgen(int row, int col):
  Enemy{130, 26, 13, row, col, WORGEN}{}

bool Worgen::visit (Object &object, Type type) {
	return object.be_visit (*this, type);
}

