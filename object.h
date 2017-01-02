#ifndef __OBJECT_H_
#define __OBJECT_H_
#include <vector>
#include "subject.h"
#include "observer.h"
#include "pos.h"
#include "type.h"
#include "Headers_Class.h"

class Object: public Subject, public Observer{
	Pos pos;
public:
	Pos& getPos();
	Object () = default;
	Object (int posx, int posy, Style style);
	void flip ();// change the isRead in Pos to help floor generate object
	
	// these are all virtual methods and implemented in a default behavior
	virtual bool visit_objects(Type type);
	virtual bool visit(Object &object, Type type);
	//be_visit
	virtual bool be_visit(Aaron& aaron, Type type);
	virtual bool be_visit(Shade& shade, Type type);
	virtual bool be_visit(Drow& drow, Type type);
	virtual bool be_visit(Vampire& vampire, Type type);
	virtual bool be_visit(Troll& typeroll, Type type);
	virtual bool be_visit(Goblin& goblin, Type type);
	virtual bool be_visit(Human& human, Type type);
	virtual bool be_visit(Dwarf& dwarf, Type type);
	virtual bool be_visit(Halfling& halfling, Type type);
	virtual bool be_visit(Elf& elf, Type type);
	virtual bool be_visit(Orc& orc, Type type);
	virtual bool be_visit(Dragon& dragon, Type type);
	virtual bool be_visit(Merchant& merchant, Type type);
	virtual bool be_visit(Small_Hoard& small_hoard, Type type);
	virtual bool be_visit(Normal_Hoard& normal_hoard, Type type);
	virtual bool be_visit(Dragon_Hoard& dragon_hoard, Type type);
	virtual bool be_visit(Merchant_Hoard& merchant_hoard, Type type);
	virtual bool be_visit(NightElf&, Type type);
	virtual bool be_visit(BloodElf&, Type type);
	virtual bool be_visit(Worgen&, Type type);
	virtual bool be_visit(ForSaken&, Type type);
	virtual bool be_visit(Eason&, Type type);
	virtual ~Object() = 0;
    
};

#endif
