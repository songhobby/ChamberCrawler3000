#include "gamecontroller.h"
#include "display.h"
#include "panel.h"
#include "window.h"

using namespace std;

GameController::GameController():display{make_shared<Window>("welcome.txt"), make_shared<Panel>(nullptr)}{}
//	display.display(display.w);
