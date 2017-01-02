#include "GAME.h"
#include "window.h"

using namespace std;

void Game::selectVersion(string file){
	//shared_ptr<Window> startWindow;
	if (file != "plainfloor.txt"){
		t_game.play(file);
	} else {
	char version;
		std::cout << "choose n/d to use normal/dlc" << std::endl;
	cin >> version;
//	ifstream f {file};
		if (version == 'n'){
			n_game.play(file);
		} else if (version == 'd'){
			d_game.play(file);
		} else {
			t_game.play(file);
		}
	}
}
