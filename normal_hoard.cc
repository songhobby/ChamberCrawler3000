#include "normal_hoard.h"
#include "type.h"
#include "shade.h"
#include "object.h"


Normal_Hoard::Normal_Hoard (int row, int col)
	:Treasure{row, col, NORMAL_HOARD, 2} {}
bool Normal_Hoard::visit (Object&object, Type type) {
	object.be_visit(*this, type);
}
