#include"orc.h"
#include "shade.h"

Orc::Orc(int row, int col):
  Enemy{180, 30, 25, row, col, ORC}{}

bool Orc::visit (Object &object, Type type) {
	return object.be_visit (*this, type);
}
