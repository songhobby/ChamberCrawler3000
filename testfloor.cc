#include <iostream>
#include <cmath>
#include <algorithm>
#include "testfloor.h"
#include "type.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "style.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"

#include "restore_health.h"
#include "boost_atk.h"
#include "boost_def.h"
#include "poison_health.h" 
#include "wound_atk.h" 
#include "wound_def.h"
	
#include "cell.h"
#include "space.h"
#include "vertical_wall.h"
#include "horizontal_wall.h"
#include "door.h"
#include "tile.h"
#include "passage.h"
#include "stair.h"

#include "window.h"
#include "panel.h"
#include "observer.h"

#include "enemy.h"
#include "human.h"
#include "dwarf.h"
#include "halfling.h"
#include "elf.h"
#include "orc.h"
#include "merchant.h"
#include "dragon.h"

#include "item.h"
#include "treasure.h"
#include "small_hoard.h"
#include "normal_hoard.h"
#include "merchant_hoard.h"
#include "dragon_hoard.h"

#include "buff.h"
#include "display.h"
#include "visitexcept.h"
	using namespace std;
#include "curses.h"

class Enemy;


void T_Floor::clearFloor(bool cleanplayer){
	//	cout << "enter clear" << endl;
	if (cleanplayer){
		thePlayer = nullptr;
		Merchant::revenge = false;
	} else {
		if (thePlayer->getPlayerInfo().level == 5){
			throw 'w';
		}
		thePlayer->levelUp();
	}
	board.clear();
	theEnemy.clear();
//	cout << "out clear" << endl;
}
		

T_Floor::T_Floor(Display& display): theDisplay{display},height{25}, width{79}, stop{false} {}
		

void T_Floor::initHelper(string file){
	ifstream given {file};

	ofstream level1 {"level1.txt"};
	ofstream level2 {"level2.txt"};
	ofstream level3 {"level3.txt"};
	ofstream level4 {"level4.txt"};
	ofstream level5 {"level5.txt"};

	string ss;
	for(int i = 0; i < height; i++){
		getline(given,ss);
		level1 << ss;
		level1 << endl;
	}
	level1.close();

	for(int i = 0; i < height; i++){
		getline(given,ss);
		level2 << ss;
		level2 << endl;
	}
	level2.close();

	for(int i = 0; i < height; i++){
		getline(given,ss);
		level3 << ss;
		level3 << endl;
	}
	level3.close();

	for(int i = 0; i < height; i++){
		getline(given,ss);
		level4 << ss;
		level4 << endl;
	}
	level4.close();

	for(int i = 0; i < height; i++){
		getline(given,ss);
		level5 << ss;
		level5 << endl;
	}
	level5.close();
}
	



void T_Floor::init(string file){
	//theDisplay.w = make_shared<Window>(file);
	int r,c;
	string line;
	theDisplay.w = make_shared<Window>(file);
	ifstream f {file};
	shared_ptr<Object> o;
	for (int i = 0; i < height; i++){
		vector<shared_ptr<Object>> arr;
		getline(f, line);
		for (int j = 0; j < width; j++){
			if (line[j] == '.') {
				o = make_shared<Tile>(j,i);
			} else if (line[j] == '-') {
				o = make_shared<Horizontal_Wall>(j,i);
			} else if (line[j] == '|') {
				o = make_shared<Vertical_Wall>(j,i);
			} else if (line[j] == '\\') {
				o = make_shared<Stair>(j,i);
			} else if (line[j] == '+') {
				o = make_shared<Door>(j,i);
			} else if (line[j] == '#') {
				o = make_shared<Passage>(j,i);
			} else if (line[j] == ' ') {
				o = make_shared<Space>(j,i);
			} else if (line[j] == '0') {
				o = make_shared<Restore_Health>(j,i);
			} else if (line[j] == '1') {
				o = make_shared<Boost_Atk>(j,i);
			} else if (line[j] == '2') {
				o = make_shared<Boost_Def>(j,i);
			} else if (line[j] == '3') {
				o = make_shared<Poison_Health>(j,i);
			} else if (line[j] == '4') {
				o = make_shared<Wound_Atk>(j,i);
			} else if (line[j] == '5') {
				o = make_shared<Wound_Def>(j,i);
			} else if (line[j] == '6') {
				o = make_shared<Normal_Hoard>(j,i);
			} else if (line[j] == '7') {
				o = make_shared<Small_Hoard>(j,i);
			} else if (line[j] == '8') {
				o = make_shared<Merchant_Hoard>(j,i);
			} else if (line[j] == '9'){
				o = make_shared<Dragon_Hoard>(j,i);
			
			} else if (line[j] == 'H') {
				o = make_shared<Human>(j,i);
				theEnemy.emplace_back(o);
			} else if (line[j] == 'W') {
				o = make_shared<Dwarf>(j,i);
				theEnemy.emplace_back(o);
			} else if (line[j] == 'E') {
				o = make_shared<Elf>(j,i);
				theEnemy.emplace_back(o);
			} else if (line[j] == 'O') {
				o = make_shared<Orc>(j,i);
				theEnemy.emplace_back(o);
			} else if (line[j] == 'M') {
				o = make_shared<Merchant>(j,i);
				theEnemy.emplace_back(o);
			} else if (line[j] == 'D') {
				o = make_shared<Dragon>(j,i);
				theEnemy.emplace_back(o);
			} else if (line[j] == 'L') {
				o = make_shared<Halfling>(j,i);
				theEnemy.emplace_back(o);
			} else { //'@'
				o = make_shared<Tile>(j,i);
				r = i;
				c = j;
			}
			o->attach(theDisplay.w);
			arr.emplace_back(o);
			theDisplay.w->notify(*o);
		}
		board.emplace_back(arr);
	}
	thePlayer = make_shared<Shade>(c,r);
	theDisplay.p = make_shared<Panel>(thePlayer.get());
	theDisplay.w->notify(*thePlayer);
	theDisplay.p->notify(*thePlayer);
}


	void T_Floor::floorVisit(string s, Type type){
		//cout << "enter floorvisit" << endl;
		int r = thePlayer->getPos().posy;
	//	cout << "here!!" << endl;
		int c = thePlayer->getPos().posx;
		int target_r, target_c;
	//	cout << "here " << endl;
		if (s == "no") {
			target_r = r-1;
			target_c = c;
		} else if (s == "so") {
			target_r = r+1;
			target_c = c;
		} else if (s == "ea") {
			target_r = r;
			target_c = c+1;
		} else if (s == "we") {
			target_r = r;
			target_c = c-1;
		} else if (s == "ne"){
			target_r = r-1;
			target_c = c+1;
		} else if (s == "nw"){
			target_r = r-1;
			target_c = c-1;
		} else if (s == "se"){
			target_r = r+1;
			target_c = c+1;
		} else {
			target_r = r+1;
			target_c = c-1;
		}
		//cout << "row :" << target_r << "col: " << target_c << endl;
		bool isSuccess;
		try{
		   isSuccess = 
				thePlayer->visit(*board[target_r][target_c], type); //catch throw
		   if (thePlayer->getInfo().hp <= 0 && type == PICKUP){
			   throw 'd';
		   }
		}
		catch (VisitExcept& exc) {
			//cout << "here!!!!!" << endl;
			isSuccess = true;
			if (exc.state == "stair"){
				clearFloor(false);
				int nextlevel = thePlayer->getPlayerInfo().level + 1;
				string nextfile = "level" + to_string(nextlevel) + ".txt";
				init(nextfile);
				// reduce the gabage
			} else if (exc.state == "pickup_potion"){
					board[target_r][target_c] = make_shared<Tile>(target_c,target_r);
					if (thePlayer->getInfo().hp <= 0){
						throw 'd';
					}
					//aaron have to return visitExcept with "string"
					//throw;		
			//	theDisplay.w->notify(*board[target_r][target_c]);
			} else if (exc.state == "pickup_gold"){
					board[target_r][target_c] = make_shared<Tile>(target_c,target_r);
			} else if(exc.state == "dragon_hoard"){
				 auto deadDragon = find(theDragon.begin(),theDragon.end(),board[target_r][target_c]);
			  	theDragon.erase(deadDragon);
				board[target_r][target_c] = make_shared<Tile>(target_c, target_r);
				 //theDisplay.w->notify(*board[target_r][target_c]);
			} else {
			// enemy is dead {
			     //delete enemy
			     auto deadEnemy = find(theEnemy.begin(),theEnemy.end(),board[target_r][target_c]);
			     theEnemy.erase(deadEnemy);
				if (exc.state == "small_hoard") {
					board[target_r][target_c] = make_shared<Small_Hoard>(target_c, target_r);
				} else if (exc.state == "merchant_hoard"){
					board[target_r][target_c] = make_shared<Merchant_Hoard>(target_c, target_r);	
				}else if (exc.state == "normal_hoard"){
					while (exc.num > 1) {
					board[target_r][target_c] = make_shared<Normal_Hoard>(target_c, target_r);
					int randr, randc;
					do {
						randr = getRandom (-1, 1) + target_r;
						if (randr == 0) {
							randc = getRandom (0, 1) * 2 -1 + target_c;
						} else randc = getRandom (-1, 1) + target_c;
					} while (!board[target_r][target_c]->visit(*board[randr][randc], MOVE));
						swap(board[randr][randc]->getPos().posx, board[target_r][target_c]->getPos().posx);
						swap(board[randr][randc]->getPos().posy, board[target_r][target_c]->getPos().posy);
						swap(board[randr][randc], board[target_r][target_c]);
						theDisplay.w->notify(*board[randr][randc]);
						--exc.num;
					}
						board[target_r][target_c] = make_shared<Normal_Hoard>(target_c, target_r);
						
				} else {// merchant_hoard


//merchant dragon drop 
				}
			}
		}

		theDisplay.w->notify(*board[target_r][target_c]);
		if (!isSuccess) {
				//cout << "false" << endl;
		} else {
			if (type == MOVE){
				//cout << "true" << endl;
				thePlayer->getPos().posx = target_c;
				thePlayer->getPos().posy = target_r;
			//	theDisplay.w->notify(*thePlayer);
			//	theDisplay.p->notify(*thePlayer);
				//	cout << *this;
			} else if (type == ATTACK) {
				theDisplay.p->notify(*thePlayer);
			} else {
				//cout << "PICKUP condition" << endl;
			}
		}
		theDisplay.w->notify(*thePlayer);
		theDisplay.w->notify(*board[target_r][target_c]);
		theDisplay.p->notify(*thePlayer);

	//enemy random move.
		sort(theEnemy.begin(), theEnemy.end(), compare);
		if (!stop) {
			int player_r = thePlayer->getPos().posy;
			int player_c = thePlayer->getPos().posx;
			bool playeraround = false;

		    //dragon case
		 for(int i = 0; i < theDragon.size(); i++){
		    int dragonr = theDragon[i]->getPos().posy;
		    int dragonc = theDragon[i]->getPos().posx;
		    int hoardr = theDragon[i]->getHoardY();
		    int hoardc = theDragon[i]->getHoardX();
			if ((abs(player_r - dragonr) <= 1 && abs(player_c - dragonc) <= 1) ||
			    (abs(player_r - hoardr) <= 1 && abs(player_c - hoardc) <= 1)){
				playeraround = true;
				try	{
				//cout << "player is attacked" << endl;
						theDragon[i]->visit(*thePlayer, ATTACK);
				}
				catch(VisitExcept & exc){
					if (exc.state == "deadplayer"){
						playeraround = true;
						throw 'd';
					}
				}
			}
			if(playeraround){
				theDisplay.p->notify(*thePlayer);
			}
		 }
		    // other enemy
			for (int i = 0; i < theEnemy.size(); i++){
		    playeraround = false;
				int r = theEnemy[i]->getPos().posy;
				int c = theEnemy[i]->getPos().posx;
				if (abs(player_r - r) <= 1 && abs(player_c - c) <= 1){
					playeraround = true;
					int attack = getRandom(0,1);
					try	{
					//cout << "player is attacked" << endl;
						if (attack == 1){
							theEnemy[i]->visit(*thePlayer, ATTACK);
						} else {
							thePlayer->getPlayerInfo().action += "Enemy missed";
						}
					}
					catch(VisitExcept & exc){
						if (exc.state == "deadplayer"){
							playeraround = true;
							throw 'd';
						}
					}
				}
				if (!playeraround){
					vector<bool> possibility(8, false);
						enemyMove(i, possibility);
				} else {
					theDisplay.p->notify(*thePlayer);
				}
			}
		}
	//	theDisplay.w->notify(*thePlayer);
	//	theDisplay.w->notify(*board[target_r][target_c]);
//		theDisplay.p->notify(*thePlayer);
		//		
		//theDisplay.display();
		thePlayer->getPlayerInfo().action = "";
	// "enemy random move complete" << endl;
	}

void T_Floor::pause(){
	if (stop) stop = false;
	else stop = true;
}

bool T_Floor::enemyMove(int n, vector<bool>& possibility) {
	int r = theEnemy[n]->getPos().posy;
	int c = theEnemy[n]->getPos().posx;
	int target_r, target_c;
	int i = getRandom(1,8); //0 means the enemy don't move this round(don't know if it is necessary).
	if (i == 1) {
		target_r = r-1;
		target_c = c;
		possibility[i] = true;
	} else if (i == 2) {
		target_r = r+1;
		target_c = c;
		possibility[i] = true;
	} else if (i == 3) {
		target_r = r;
		target_c = c+1;
		possibility[i] = true;
	} else if (i == 4) {
		target_r = r;
		target_c = c-1;
		possibility[i] = true;
	} else if (i == 5){
		target_r = r-1;
		target_c = c+1;
		possibility[i] = true;
	} else if (i == 6){
		target_r = r-1;
		target_c = c-1;
		possibility[i] = true;
	} else if (i == 7){
		target_r = r+1;
		target_c = c+1;
		possibility[i] = true;
	} else {
		target_r = r+1;
		target_c = c-1;
		possibility[i] = true;
	}
    if (theEnemy[n]->visit(*board[target_r][target_c], MOVE)){
		swap(theEnemy[n]->getPos().posx, board[target_r][target_c]->getPos().posx);
		swap(theEnemy[n]->getPos().posy, board[target_r][target_c]->getPos().posy);
		swap(board[r][c], board[target_r][target_c]);
		theDisplay.w->notify(*theEnemy[n]);
		theDisplay.w->notify(*board[r][c]);
	  	return true;
	} else if (!(possibility[1] &&  possibility[2] &&  possibility[3] &&
		   	possibility[4] && possibility[5] && possibility[6] &&
		   	possibility[7] && possibility[8])) {
		enemyMove(n, possibility);
	} else {
		enemyMove(n, possibility);
	}
    return false;
}

void T_Floor::windowPreprocessor(string message, int r, int c){
	ifstream f {message};
	ofstream after {"modified_window.txt"};
	string line;
	for (int i = 0; i < height; i++){
		getline(f, line);
		if (i == r){
			int gold = thePlayer->getPlayerInfo().gold;
			string s = "Your score is: " + to_string(gold);
			line.replace (c,s.length(),s);
			after << line;
			after << endl;
		} else {
			after << line;
			after << endl;	
		}
	}
	after.close();
}
	
ostream &operator<<(ostream &out, const T_Floor &f){
	out << *f.theDisplay.w; //this is window.
	out << *f.theDisplay.p; //this is plane.
	return out;
}

