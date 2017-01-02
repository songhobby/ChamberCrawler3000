#include <iostream>
#include "buff.h"
#include <sstream>
#include <curses.h>
#include <memory>
#include <string>
#include <cstdlib>
#include <ctime>
#include "object.h"
#include "normal_gamecontroller.h"
#include "quit.h"
#include "window.h"
#include "panel.h"
using namespace std;

N_GameController::N_GameController():n_floor{display}{}
//	display.display(display.w);


void N_GameController::play(string file){
	srand(time(NULL));
	shared_ptr<Window> theWindow = make_shared<Window>("normal_version.txt");
	display.display(theWindow);
	
	n_floor.init(file);
	display.display();
	string cmd;
	while (true) {
		try {
			cin >> cmd;
			string direction;
		   	if (cmd == "u") {
                cin >> direction;
				n_floor.floorVisit(direction, PICKUP);
			} else if (cmd == "a") {
                cin >> direction;
				n_floor.floorVisit(direction, ATTACK);
			} else if (cmd == "f") {
				n_floor.pause();
			} else if (cmd == "r") {
				n_floor.clearFloor(true);
				n_floor.init(file); //remember to generate enemies again
			} else if (cmd == "q") {
				throw 'q';
			} else {
				n_floor.floorVisit(cmd, MOVE);
			}
			display.display();
		}
		catch (char message) {
			if (message == 'd') {
				n_floor.windowPreprocessor("endwindow.txt", 23, 30);
				shared_ptr<Window> endWindow = make_shared<Window>("modified_window.txt");
				display.display(endWindow);
			} else if (message == 'w'){
				n_floor.windowPreprocessor("win.txt", 23, 30);
				shared_ptr<Window> winWindow = make_shared<Window>("modified_window.txt");
				display.display(winWindow);
			} else {
				throw;
			}
        }
    }
}

