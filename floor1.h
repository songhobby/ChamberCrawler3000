#ifndef _N_FLOOR_H_
#define _N_FLOOR_H_
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "type.h"
#include "object.h"
#include "chamber.h"
#include "player.h"
class Dragon;
class Window;
class Panel;
class Player;
class Enemy;
class Display;

class N_Floor{
	std::vector<std::vector<std::shared_ptr<Object>>> board; //the board
	std::shared_ptr<Player> thePlayer;
	std::vector<std::shared_ptr<Dragon>> theDragon;
	std::vector<std::shared_ptr<Enemy>> theEnemy;
	std::vector<Chamber> theChamber; //store the chamber
	Display& theDisplay;
	int height;
	int width;
	bool stop;
	bool enemyMove(int n, std::vector<bool>& possibility);
	public:	
	N_Floor(Display& display);
	void floorVisit(std::string s, Type type);// take in a direction string s and an action type to achieve
	// a turn move
	void clearFloor(bool cleanPlayer);// deal with restart and next floor case
    void init(std::string file = "plainfloor.txt"); // set up the board according to the given floor in the file.
    void setChamber(int r, int c, std::vector<std::shared_ptr<Object>*>& arr); // automatically read in any
	// kinds of chamber
	void spawnAction();// deal with all the spawning actions
	void selectPlayer();
	void setPlayer(); // generate player.
	void setStair(); //generate stairway.
	void setPotion(); //generate potion
	void setTreasure(); //generate gold.
	void setEnemy(); //generate enemy.
	void windowPreprocessor(std::string message, int r, int c);
	void pause();
	std::string outPut();
	
	friend std::ostream &operator<<(std::ostream &out, const N_Floor &f);
};

#endif
