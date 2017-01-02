#include "GAME.h"
#include "buff.h"

int main(int argc, char* argv[]) {
    //iosfailure
    Game g{};
	try {
		if (argc == 1){
			g.selectVersion("plainfloor.txt");
		} else {
			g.selectVersion(argv[1]);
		}
	}
	catch (...){
		return 0;
	}
}
