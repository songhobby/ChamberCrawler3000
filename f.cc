#include <iostream>
#include "floor1.h"
#include "type.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "style.h"
#include "shade.h"
//#include "drow.h"
//#include "vampire.h"
//#include "troll.h"
//#include "goblin.h"
//#include "restore_health.h"
//#include "boost_atk.h"
//#include "boost_def.h"
//#include "poison_health.h" //#include "wound_atk.h" //#include "wound_def.h"
//#include "cell.h"
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

#include "item.h"
#include "treasure.h"
#include "small_hoard.h"
#include "normal_hoard.h"
#include "dragon_hoard.h"
using namespace std;

class Enemy;



int Floor::getRandom(int min, int max){
	int n = max - min + 1;
	int rn = rand() % n + min;
	return rn;
}

void Floor::clearFloor(){
	cout << "enter clear" << endl;
	if (w != nullptr) {
		thePlayer->levelUp(); //player add a method levelUp.
		w = nullptr;
		p = nullptr;
		board.clear();
	}
	cout << "out clear" << endl;
}
	

Floor::Floor(): height{25}, width{79}, stop{false} {}
	

//Floor::~Floor() {} //smart pointer will delete. so try use default.

void Floor::init(string file){ // set up the board according to the given floor in the file.
	cout << "enter init" << endl;
	clearFloor();
//	height = 25;
//	width = 79;
	w = make_shared<Window>(file);
	p = make_shared<Panel>(nullptr);
	ifstream f {file};
	string line;
    shared_ptr<Object> o;
	for (int i = 0; i < height; i++){
		vector<shared_ptr<Object>> arr;
		getline(f, line);
		for (int j = 0; j < width; j++){
			if (line[j] == '.') {
				o = make_shared<Tile>(j,i); //这个TILE可以不用输入的。
                //o->setAttributes(i, j, TILE, false, nullptr);
			} else if (line[j] == '-') {
				o = make_shared<Horizontal_Wall>(j,j);
               // o->setAttributes(i, j, HORIZONTAL_WALL, false, nullptr);
			} else if (line[j] == '|') {
				o = make_shared<Vertical_Wall>(j,i);
                //o->setAttributes(i, j, VERTICAL_WALL, false, nullptr);
			} else if (line[j] == '+') {
				o = make_shared<Door>(j,i);
                //o->setAttributes(i, j, DOOR, false, nullptr);
			} else if (line[j] == '#') {
				o = make_shared<Passage>(j,i);
                //o->setAttributes(i, j, PASSAGE, false, nullptr);
			} else {
				o = make_shared<Space>(j,i);
               // o->setAttributes(i, j, SPACE, false, nullptr);
			}
			//add more conditions to achieve read another type of floor (all set).
            
            //attach the neighbours.
//            if (i - 1 >= 0) {
//                board[i][j]->attach(board[i-1][j]);
//                if (j -1 >= 0){
//                    board[i][j]->attach(board[i-1][j-1]);
//                }
//                if (j +1 < width){
//                    board[i][j]->attach(board[i-1][j+1]);
//                }
//            }
//            if (i + 1 < height){
//                board[i][j]->attach(board[i+1][j]);
//                if (j - 1 >= 0){
//                    board[i][j]->attach(board[i+1][j-1]);
//                }
//                if (j + 1 < width) {
//                    board[i][j]->attach(board[i+1][j+1]);
//                }
//            }
//            if (j - 1 >= 0) {
//                board[i][j]->attach(board[i][j-1]);
//            }
//            if (j + 1 < width) {
//                board[i][j]->attach(board[i][j+1]);
//            }
			o->attach(w);
			arr.emplace_back(o);
		}
		board.emplace_back(arr);
	}
	cout << "befor chamber" << endl;
	//detect chamber;
    for (int t = 0; t < 5; t++) {
		//cout << " here " << t<< endl;
		int row,col;
		do {
			row = getRandom(0, height - 1);
			col = getRandom(0, width - 1);
			//cout << row <<" " << col << endl;
//			cout << board[row][col]->getPos().posx << " " << row <<" " << col << endl;
		} while (board[row][col]->getPos().style != TILE || (board[row][col]->getPos().isRead)); //check if it is read
		Chamber cham;
		setChamber(row, col, cham.c);
		//cout << cham.c.size() << endl;
		theChamber.emplace_back(cham);
	}
	cout << "out init" << endl;
}

void Floor::setChamber(int r, int c, vector<shared_ptr<Object>*>& arr) {
	//cout << "setChamber" << board[r][c]->getPos().isRead << endl;
	//cout << board[r][c]->getPos().style;
	board[r][c]->flip();
	arr.emplace_back(&board[r][c]);
	if (board[r-1][c]->getPos().style == TILE && !(board[r-1][c]->getPos().isRead)) {
		setChamber(r-1, c, arr);
	}
	if (board[r+1][c]->getPos().style == TILE && !(board[r+1][c]->getPos().isRead)) {
		setChamber(r+1,c, arr);
	}
	if (board[r][c-1]->getPos().style == TILE && !(board[r][c-1]->getPos().isRead)){ 
		setChamber(r,c-1, arr);
	}
	if (board[r][c+1]->getPos().style == TILE && !(board[r][c+1]->getPos().isRead)) {
		setChamber(r,c+1, arr);
	}
}
	

void Floor::setPlayer(){ // generate player.
    int n = getRandom(0,4);
    int pos = getRandom(0,theChamber[n].c.size() - 1);
    Pos position = (*theChamber[n].c[pos])->getPos(); //object 的pos 里头要加一个field tmp
    //thePlayer->setAttributes(position.posy, position.posx,);
    shared_ptr<Player> thePlayer;

	//selectplayer.
	while (true){
	 //put this part in to display later.
		cout << "Choose your player: (s, d, v, g, t)" << endl;
		char player_select;
		cin >> player_select;
		if (player_select == 's'){
            thePlayer = make_shared<Shade>(position.posx, position.posy); //the hp atk .. is assigned in ctor.
            //thePlayer->setAttributes(position.posy, position.posx, SHADE, false, nullptr);
//		} else if (player == 'd') {
//			thePlayer = make_shared<Drow>(position.posy, position.posx, DROW);
//            //thePlayer->setAttributes(position.posy, position.posx, DROW, false, nullptr);
//		} else if (player == 'v') {
//			thePlayer = make_shared<Vampire>(position.posy, position.posx, VAMPIRE);
//            //thePlayer->setAttributes(position.posy, position.posx,VAMPIRE, false, nullptr);
//		} else if (player == 'g') {
//			thePlayer = make_shared<Goblin>(position.posy, position.posx, GOBLIN);
//           //thePlayer->setAttributes(position.posy, position.posx, GOBLIN, false, nullptr);
//		} else if (player == 't') {
//			thePlayer = make_shared<Troll>(position.posy, position.posx, TROLL);  //add auto ???
//           // thePlayer->setAttributes(position.posy, position.posx, TROLL, false, nullptr);
		} else {
			//thePlayer = make_shared<Shade>();
			continue;
        }
		break;
	}
    p = make_shared<Panel>(thePlayer); //create a panel here
    thePlayer->attach(this->p); //attach panel to each player.
	thePlayer->notifyObservers();
    thePlayer->getPos().last = *(theChamber[n].c[pos]); //重新核实一下
	*(theChamber[n].c[pos]) = thePlayer;
	w->notify(*(*theChamber[n].c[pos]));
	theChamber[n].c.erase(theChamber[n].c.begin() + pos);
}

void Floor::setStair(){ //generate stairway.
	int n = getRandom(0,4);
	int pos = getRandom(0, theChamber[n].c.size() - 1);
    Pos position = (*theChamber[n].c[pos])->getPos();
	auto o = make_shared<Stair>(position.posx, position.posy);
	
	//o->setAttributes(position.posy, position.posx, STAIR, false, nullptr);
	//theStair = o;
	*(theChamber[n].c[pos]) = o;
	w->notify(*(*theChamber[n].c[pos]));
	theChamber[n].c.erase(theChamber[n].c.begin() + pos);
	cout << "setStair works fine" << endl;
}

//void Floor::setPotion(){ //generate potion
//	int n = getRandom(0, 4);
//	int pos = getRandom(0, theChamber[n].c.size() - 1);
//	int p = getRandom(1,6);
//	shared_ptr<Object> o;
//	switch (p){
//		case 1: 
//			o = make_shared<Restore_Health>(); //ctor should take in x y to set position.
//			break;
//		case 2:
//			o = make_shared<Boost_Atk>();
//			break;
//		case 3:
//			o = make_shared<Boost_Def>();
//			break;
//		case 4: 
//			o = make_shared<Poison_Health>();
//			break;
//		case 5:
//			o = make_shared<Wound_Atk>();
//			break;
//		case 6:
//			o = make_shared<Wound_Def>();
//			break;
//	}
//	Pos position = (*theChamber[n].c[pos])->getPos();
//	o->setCoordinate(position.posy, position.posx);
//	//thePotion.emplace_back(o);
//	*(theChamber[n].c[pos]) = o; // put this object in to the board.
//	theChamber[n].c.erase(theChamber[n].c.begin() + pos);
//}

void Floor::setTreasure(){ //generate gold.
	int n = getRandom(0, 4);
	int pos = getRandom(0, theChamber[n].c.size() - 1);
	Pos position = (*theChamber[n].c[pos])->getPos();
	int p = getRandom(1,8);
	shared_ptr<Treasure> o;
	switch (p){
		case 1: 
		case 2:
		case 3:
		case 4: 
		case 5:
			o = make_shared<Normal_Hoard>(position.posx, position.posy);
			break;
		case 6:
        case 7: 
			o = make_shared<Small_Hoard>(position.posx, position.posy);
			break;
		case 8:
			o = make_shared<Dragon_Hoard>(position.posx, position.posy); //I expect the ctor of DH spawn a dragon here!!!!
			break;
	}
	//o->setCoordinate(position.posy, position.posx);
	//theTreasure.emplace_back(o);
	*(theChamber[n].c[pos]) = o;
	w->notify(*(*theChamber[n].c[pos]));
	theChamber[n].c.erase(theChamber[n].c.begin() + pos);
}


void Floor::setEnemy(){ //generate enemy.
	int n = getRandom(0, 4);
	int pos = getRandom(0, theChamber[n].c.size() - 1);
	int p = getRandom(1,18);
    Pos position = (*theChamber[n].c[pos])->getPos();
	shared_ptr<Enemy> o = nullptr;
	switch (p){
		case 1: 
		case 2:
		case 3:
		case 4: 
			o = make_shared<Human>(position.posx, position.posy);
            //o->setAttributes(position.posy, position.posx, HUMAN, false, nullptr);
			break;
		case 5:
		case 6:
		case 7: 
			o = make_shared<Dwarf>(position.posx, position.posy);
           // o->setAttributes(position.posy, position.posx, DWARF, false, nullptr);
			break;
		case 8:
		case 9:
		case 10: 
		case 11:
		case 12:
			o = make_shared<Halfling>(position.posx, position.posy);
           // o->setAttributes(position.posy, position.posx, HALFLING, false, nullptr);
			break;
		case 13: 
		case 14:
			o = make_shared<Elf>(position.posx, position.posy);
          //  o->setAttributes(position.posy, position.posx, ELF, false, nullptr);
			break;
		case 15:
		case 16: 
			o = make_shared<Orc>(position.posx, position.posy);
           // o->setAttributes(position.posy, position.posx, ORC, false, nullptr);
			break;
		case 17:
		case 18:
			o = make_shared<Merchant>(position.posx, position.posy);
           // o->setAttributes(position.posy, position.posx, MERCHANT, false, nullptr);
			break;
	}
	
	theEnemy.emplace_back(o);
	*(theChamber[n].c[pos]) = o;
	w->notify(*(*theChamber[n].c[pos]));
	theChamber[n].c.erase(theChamber[n].c.begin() + pos);
}

void Floor::floorVisit(string s, Type type){
	int r = thePlayer->getPos().posy;
	int c = thePlayer->getPos().posx;
	int target_r, target_c;
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
	if (thePlayer->visit(*board[target_r][target_c], type)) { //catch throw
		if (type == MOVE) {
            board[r][c] = thePlayer->getPos().last;
			thePlayer->getPos().last = board[target_r][target_c];
            board[target_r][target_c] = thePlayer;
		}
	}

//	//enemy random move.
//	if (!stop) {
//		for (int i = 0; i < theEnemy.size(); i++) {
//			enemyMove(i);
//		}
//	}
}

void Floor::pause(){
	if (stop) stop = true;
	else stop = false;
}
//
//bool Floor::enemyMove(int n) {
//	bool b1,b2,b3,b4,b5,b6,b7,b8;
//	b1 = b2 = b3 = b4 = b5 = b6 = b7 = b8 = false;
//	int r = theEnemy[n]->getPos().posy;
//	int c = theEnemy[n]->getPos().posx;
//	int target_r, target_c;
//	int i = getRandom(1,8); //0 means the enemy don't move this round(don't know if it is necessary).
//	if (i == 1) {
//		target_r = r-1;
//		target_c = c;
//		b1 = true;
//	} else if (i == 2) {
//		target_r = r+1;
//		target_c = c;
//		b2 = true;
//	} else if (i == 3) {
//		target_r = r;
//		target_c = c+1;
//		b3 = true;
//	} else if (i == 4) {
//		target_r = r;
//		target_c = c-1;
//		b4 = true;
//	} else if (i == 5){
//		target_r = r-1;
//		target_c = c+1;
//		b5 = true;
//	} else if (i == 6){
//		target_r = r-1;
//		target_c = c-1;
//		b6 = true;
//	} else if (i == 7){
//		target_r = r+1;
//		target_c = c+1;
//		b7 = true;
//	} else {
//		target_r = r+1;
//		target_c = c-1;
//		b8 = true;
//	}
//	//can move to that position for some reason).
////	if (i != 0) {
//    bool b = theEnemy[n]->visit(*board[target_r][target_c], MOVE);
//    board[r][c] = theEnemy[n]->getPos().last;
//    theEnemy[n]->getPos().last == board[target_r][target_c];
//    board[target_r][target_c] = theEnemy[n];
////	} else {
////		return true;
////	}
//	if (b) { //this part is to make sure all 8 positions have been checked.
//	   return true;
//	} else if (!(b1 && b2 && b3 && b4 && b5 && b6 && b7 && b8)) {
//		enemyMove(n);
//	} else {
//		return false;
//	}
//    return false; //still need to check here.
//}

ostream &operator<<(std::ostream &out, const Floor &f){
	out << *f.w; //this is window.
	out << *f.p; //this is plane.
	return out;
}







