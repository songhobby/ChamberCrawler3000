#include"dwarf.h"
#include "shade.h"

Dwarf::Dwarf(int row, int col):
  Enemy{100, 20, 30, row, col, DWARF}{}

bool Dwarf::visit (Object &object, Type type) {
	return object.be_visit (*this, type);
}

