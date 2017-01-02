#ifndef DRAGON_H
#define DRAGON_H
#include "enemy.h"
#include "type.h"
#include "style.h"
#include<string>
//#include "subject.h"

class Object;
class Shade;

class Dragon: public Enemy{
    int hoardx;
    int hoardy;
public:
    Dragon(int, int);
	bool visit(Object&, Type t) override;
	int &getHoardX();
	int &getHoardY();	

};

#endif
