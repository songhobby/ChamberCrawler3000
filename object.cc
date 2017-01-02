#include "object.h"
using namespace std;

Pos& Object::getPos() { return pos; }

Object::Object(int posx, int posy, Style style): pos{posx,posy, style, false}{}
    
Object::~Object () {}

void Object::flip () { pos.isRead = true; }

// these are all the default behavior of an object
bool Object::visit_objects(Type type){ return false; }
bool Object::visit(Object &object, Type type){ return false; }

//be_visit
bool Object::be_visit(Aaron& aaron, Type type){ return false; }
bool Object::be_visit(Shade& shade, Type type){ return false; }
bool Object::be_visit(Drow& drow, Type type){ return false; }
bool Object::be_visit(Vampire& vampire, Type type){ return false; }
bool Object::be_visit(Troll& typeroll, Type type){ return false; }
bool Object::be_visit(Goblin& goblin, Type type){ return false; }
bool Object::be_visit(Human& human, Type type){ return false; }
bool Object::be_visit(Dwarf& dwarf, Type type){ return false; }
bool Object::be_visit(Halfling& halfling, Type type){ return false; }
bool Object::be_visit(Elf& elf, Type type){ return false; }
bool Object::be_visit(Orc& orc, Type type){ return false; }
bool Object::be_visit(Dragon& dragon, Type type){ return false; }
bool Object::be_visit(Merchant& merchant, Type type){ return false; }
bool Object::be_visit(Small_Hoard& small_hoard, Type type){ return false; }
bool Object::be_visit(Normal_Hoard& normal_hoard, Type type){ return false; }
bool Object::be_visit(Merchant_Hoard& merchant_hoard, Type type){ return false; }
bool Object::be_visit(Dragon_Hoard& dragon_hoard, Type type){ return false; }
bool Object::be_visit(NightElf& nightelf, Type type){ return false; }
bool Object::be_visit(BloodElf& bloodelf, Type type){ return false; }
bool Object::be_visit(Worgen& worgen, Type type){ return false; }
bool Object::be_visit(ForSaken& forsaken, Type type){ return false; }
bool Object::be_visit(Eason &eason, Type type){ return false; }

