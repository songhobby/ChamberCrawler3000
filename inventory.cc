#include "inventory.h"
#include "style.h"
#include "playerinfo.h"
#include "pos.h"
#include <sstream>
using namespace std;

Inventory::Inventory(vector<shared_ptr<Object>>& playerInvent) :invent{playerInvent} {}
	
/*void Inventory::notify() {
	vector<shared_ptr<Object>>& theInven = player->getPlayerInfo().inventory;
	string space1 = getString(theInven[0]->getPos().style);
	string space2 = getString(theInven[1]->getPos().style);
	string space3 = getString(theInven[2]->getPos().style);
	string space4 = getString(theInven[3]->getPos().style);
	string space5 = getString(theInven[4]->getPos().style);
	string space6 = getString(theInven[5]->getPos().style);
	string space7 = getString(theInven[6]->getPos().style);
	string space8 = getString(theInven[7]->getPos().style);
	string space9 = getString(theInven[8]->getPos().style);
	string space10 = getString(theInven[9]->getPos().style);
	string space11 = getString(theInven[10]->getPos().style);
	string space12 = getString(theInven[11]->getPos().style);
}*/
	
//Inventory::~Inventory();


ostream &operator<<(ostream &out, const Inventory &invent){
	string base = "|--|";
	for(int i = 0; i < 25; i++){
		if (i % 2 = 1) {
			base.replace(1, 2, getstring(invent[i]->getpos().style));
			out << base;
			out << endl;
		} else {	
			base.replace(1, 2, "--");
			out << base;
			out << endl;
		}
	}
	return out;
}

string Inventory::outPut(){
	ostringstream ss;
    string base = "|--|";
	for(int i = 0; i < 25; i++){
		if (i % 2 = 1) {
			base.replace(1, 2, getstring(invent[i]->getpos().style));
			ss << base;
			ss << endl;
		} else {	
			base.replace(1, 2, "--");
			ss << base;
			ss << endl;
		}
	}
	string rs = ss.str();
	return rs;
}
