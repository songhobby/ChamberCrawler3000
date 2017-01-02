#ifndef __INVENT_H_
#define __INVENT_H_
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include "observer.h"
#include "player.h"

class Subject;
class Object;

class Inventory final:public Observer {
	std::vector<std::shared_ptr<Object>>& invent;
	public:
	Inventory(std::vector<std::shared_ptr<Object>> playerInventory);
   // void notify(Subject &whoNotified) override;
	//SubscriptionType subType() const override;

	//~Inventory();

	std::string outPut();
	friend std::ostream &operator<<(std::ostream &out, const Inventory &invent);
};

#endif
