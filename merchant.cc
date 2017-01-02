#include"merchant.h"
#include "shade.h"
#include "buff.h"
#include "eason.h"
#include "nightelf.h"
#include "aaron.h"

Merchant::Merchant(int row, int col):
  Enemy{30, 70, 5, row, col, MERCHANT}{}

bool Merchant::revenge = false;

bool Merchant::visit (Object &object, Type type) {
	if(type == MOVE || revenge){
      return object.be_visit (*this, type);
    } else {
	return false;
    }
}



bool Merchant::be_visit(Shade& player, Type type){
    if(type == ATTACK){
      revenge = true;
    }
    return  be_visit_by(*this, player, type);
}

bool Merchant::be_visit(Drow& player, Type type){
    if(type == ATTACK){
      revenge = true;
    }
    return  be_visit_by(*this, player, type);
}

bool Merchant::be_visit(Vampire& player, Type type){
    if(type == ATTACK){
      revenge = true;
    }
    return  be_visit_by(*this, player, type);
}


bool Merchant::be_visit(Troll& player, Type type){
    if(type == ATTACK){
      revenge = true;
    }
    return  be_visit_by(*this, player, type);
}

bool Merchant::be_visit(Goblin& player, Type type){
    if(type == ATTACK){
      revenge = true;
    }
    return  be_visit_by(*this, player, type);
}

bool Merchant::be_visit(Aaron& player, Type type){
    if(type == ATTACK){
      revenge = true;
    }
    return  be_visit_by(*this, player, type);
}

bool Merchant::be_visit(Eason& player, Type type){
    if(type == ATTACK){
      revenge = true;
    }
    return  be_visit_by(*this, player, type);
}

bool Merchant::be_visit(NightElf& player, Type type){
    if(type == ATTACK){
      revenge = true;
    }
    return  be_visit_by(*this, player, type);
}
