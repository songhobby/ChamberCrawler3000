#include"human.h"
#include "shade.h"

Human::Human(int row, int col):
  Enemy{140, 20, 20, row, col, HUMAN}{}

bool Human::visit (Object &object, Type type) {
	return object.be_visit (*this, type);
}

