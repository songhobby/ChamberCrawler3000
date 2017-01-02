#include"enemy.h"
#include <iostream>
#include "info.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
#include "aaron.h"
#include "eason.h"
#include "nightelf.h"
#include "buff.h"
#include "visitexcept.h"
using namespace std;

Enemy::Enemy(int hp, int atk, int def, int row, int col, Style style):
  Character{hp, atk, def, row, col, style} {}

bool Enemy::be_visit(Shade& player, Type type){ // default
  return  be_visit_by(*this, player, type);
}

bool Enemy::be_visit(Eason& player, Type type){ // default
return  be_visit_by(*this, player, type);
}

bool Enemy::be_visit(NightElf& player, Type type){ // default
return  be_visit_by(*this, player, type);
}

bool Enemy::be_visit(Aaron& player, Type type){ // default
return  be_visit_by(*this, player, type);
}

bool Enemy::be_visit(Drow& player, Type type){ // default
return  be_visit_by(*this, player, type);
}

bool Enemy::be_visit(Vampire& player, Type type){ // default
return  be_visit_by(*this, player, type);
}

bool Enemy::be_visit(Troll& player, Type type){ // default
return  be_visit_by(*this, player, type);
}

bool Enemy::be_visit(Goblin& player, Type type){ // default
return  be_visit_by(*this, player, type);
}

