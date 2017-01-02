#ifndef _BUFF_H_
#define _BUFF_H_
#include <cstdlib>
#include <iostream>
#include <vector>
#include <memory>
#include "type.h"
#include "style.h"
#include <string>
#include "treasure.h"
#include "merchant.h"
#include "treasure.h"

class VisitExcept;
class Potion;
class VisitExcept;
class Merchant;
class Object;
class Player;
class Enemy;
class Item;
class Dragon;
class Aaron;
class Eason;
class NightElf;
class BloodElf;
class Worgen;
class ForSaken;

// these are useful tools we used in this project
std::vector<std::pair<int, int>> findChar(std::vector<std::vector<char>> s, char c);

// give the window actual color layer
void colorLayer(std::vector<std::pair<int, int>> thechar, char c);

//void colorWindow(std::string s);

// it cleans the screen
void clearScreen();


// it can randomly generate a number from min to max
int getRandom(int min, int max);

// use the display window to display a message
std::string messageOut(std::string message);


// calculate the damage by take in atk and def
int getDamage(int, int);

//it compares two objects and return true if ob1 goes before ob2 
bool compare(std::shared_ptr<Object> ob1,std::shared_ptr<Object> ob2);


// it gives the distance of two objects
int distance(int r1, int c1, int r2, int c2);

// it helps generate a random map
void generate_map (std::string map0 = "plainfloor.txt", int times = 100);











//template
// be_visit_by is the template for most player, enemy and item
// it can be called in be_visit method
// this template can distinguish different types of visit
// this template needs helper function for each pair of relationship
// e.g. be_attack(Player, Enemy), player is attacked by enemy


template<typename Bevisit , typename Visit , typename Type>
bool be_visit_by(Bevisit & v1, Visit & v2, Type t){
    if(t == ATTACK){
	return be_attack(v1, v2);
    }
    if(t == PICKUP){
	return be_pick_up(v1, v2);
    }
    if(t == MOVE){
	return be_go_over(v1, v2);
    }
    return false;
}


bool be_attack(Player &player, Enemy &enemy);
bool be_attack(Enemy &enemy, Player &player);  
bool be_attack(Item &item, Player &player);

bool be_pick_up(Treasure &treasure, Player &player);
bool be_pick_up(Potion &potion, Player &player);
bool be_pick_up(Enemy &enemy, Player &player);
bool be_pick_up(Player &player, Enemy &enemy);

bool be_go_over(Potion &potion, Player &player);
bool be_go_over(Enemy &enemy, Player &player);
bool be_go_over(Player &player, Enemy &enemy);
bool be_go_over(Treasure &treasure, Player &player);

#endif
