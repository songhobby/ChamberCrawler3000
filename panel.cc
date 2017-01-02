#include "panel.h"
#include "style.h"
#include "playerinfo.h"
#include "pos.h"
#include <sstream>
using namespace std;

Panel::Panel(Player *player) :player{player} {}
	
void Panel::notify(Subject &whoNotify) {
	gold = player->getPlayerInfo().gold;
	floor = player->getPlayerInfo().level;
	hp = player->getInfo().hp;
	atk = player->getInfo().atk;
	def = player->getInfo().def;
	race = getString (player->getPos().style);
	action = player->getPlayerInfo().action;
	if (whoNotify.getPos().style == AARON) {
		action = "Aaron is the most powerful man and no one could ever beat him";
	}
}
	
//Panel::~Panel();


ostream &operator<<(ostream &out, const Panel &panel){
	string line1 = "Race : " 
		+ panel.race + " Gold: " 
		+ to_string (panel.gold);
	line1.resize (69, ' ');
	line1 += "Floor " + to_string (panel.floor);
	cout << line1 << endl;
	out << "HP: " << panel.hp << endl;
	out << "Atk: " << panel.atk << endl;
	out << "Def: " << panel.def << endl;
	out << "Action: " << panel.action << endl;
	return out;
}

string Panel::outPut(){
	ostringstream ss;
	string line1 = "Race : " 
		+ race + " Gold: " 
		+ to_string (gold);
	line1.resize (69, ' ');
	line1 += "Floor " + to_string (floor);
	ss << line1 << endl;
	ss << "HP: " << hp << endl;
	ss << "Atk: " << atk << endl;
	ss << "Def: " << def << endl;
	ss << "Action: " << action << endl;
	string rs = ss.str();
	return rs;
}
