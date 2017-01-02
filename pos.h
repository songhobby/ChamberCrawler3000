#ifndef _POS_H_
#define _POS_H_
#include "style.h"

class Object;

struct Pos{
    int posx, posy;
    Style style;
    bool isRead;
    int chamber_num;
};

#endif
