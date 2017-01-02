#include <iostream>
#include "buff.h"
#include <sstream>
#include <curses.h>
#include <memory>
#include <string>
#include <cstdlib>
#include <ctime>
#include "object.h"
#include "test_gamecontroller.h"
#include "quit.h"
#include "window.h"
#include "panel.h"
using namespace std;

T_GameController::T_GameController():t_floor{display}{}
//	display.display(display.w);


void T_GameController::play(string file){
	srand(time(NULL));
	t_floor.initHelper(file);	
	t_floor.init("level1.txt");
	display.display();
	string cmd;
	while (true) {
		try {
			cin >> cmd;
			string direction;
		   	if (cmd == "u") {
                cin >> direction;
				t_floor.floorVisit(direction, PICKUP);
			} else if (cmd == "a") {
                cin >> direction;
				t_floor.floorVisit(direction, ATTACK);
			} else if (cmd == "f") {
				t_floor.pause();
			} else if (cmd == "r") {
				t_floor.clearFloor(true);
				t_floor.init("level1.txt"); //remember to generate from level one again
			} else if (cmd == "q") {
				throw 'q';
			} else {
				t_floor.floorVisit(cmd, MOVE);
			}
			display.display();
		}
		catch (char message) {
			if (message == 'd') {
				t_floor.windowPreprocessor("endwindow.txt", 23, 30);
				shared_ptr<Window> endWindow = make_shared<Window>("modified_window.txt");
				display.display(endWindow);
			} else if (message == 'w'){
				t_floor.windowPreprocessor("win.txt", 23, 30);
				shared_ptr<Window> winWindow = make_shared<Window>("modified_window.txt");
				display.display(winWindow);
			} else {
				throw;
			}
        }
    }
}
				

