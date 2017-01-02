#include"bloodelf.h"
#include "type.h"


BloodElf::BloodElf(int row, int col):
  Enemy{50, 26, 13, row, col, BLOODELF}{}

bool BloodElf::visit (Object &object, Type type) {
	return object.be_visit (*this, type);
}

