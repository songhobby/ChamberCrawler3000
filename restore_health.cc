#include "restore_health.h"
#include "buff.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
#include "visitexcept.h"


Restore_Health::Restore_Health (int posx, int posy)
:Potion{posx, posy, RESTORE_HEALTH} {}

