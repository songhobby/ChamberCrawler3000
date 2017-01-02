#include "poison_health.h"
#include "buff.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
#include "visitexcept.h"

using namespace std;

Poison_Health::Poison_Health (int posx, int posy)
:Potion{posx, posy, POISON_HEALTH} {}
