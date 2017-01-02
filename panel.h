#ifndef __PANEL_H_
#define __PANEL_H_
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include "observer.h"
#include "player.h"

class Subject;
class Object;

class Panel final:public Observer {
	std::string race, action;
	int gold,floor,hp,atk,def;
    Player *player;
	public:
	Panel(Player* player);
    void notify(Subject &whoNotified) override;
	//SubscriptionType subType() const override;

	//~Panel();

	std::string outPut();
	friend std::ostream &operator<<(std::ostream &out, const Panel &panel);
};

#endif
