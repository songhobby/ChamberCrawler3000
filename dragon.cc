#include"dragon.h"
#include "info.h"
#include "shade.h"


Dragon::Dragon(int r, int c): Enemy(150,20,20,r,c, DRAGON) {}

int &Dragon::getHoardX(){
	return hoardx;

}

int &Dragon::getHoardY(){
	return hoardy;
}


bool Dragon::visit(Object& obj, Type type){
	return obj.be_visit(*this, type);
}


