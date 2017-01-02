#include <iostream>
#include "display.h"
#include "window.h"
#include "panel.h"
//#include "inventory.h"

using namespace std;


void Display::display(shared_ptr<Window> w){
	cout << *w;
}

void Display::display(shared_ptr<Panel> p){
	cout << *p;
}

//void Display::display(shared_ptr<Inventory> i){
//	cout << *i;
//}

void Display::display(){
	display(this->w);
	display(this->p);
}

