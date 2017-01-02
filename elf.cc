#include"elf.h"
#include "shade.h"

Elf::Elf(int row, int col):
  Enemy{140, 30, 10, row, col, ELF}{}

bool Elf::visit (Object &object, Type type) {
	return object.be_visit (*this, type);
}

