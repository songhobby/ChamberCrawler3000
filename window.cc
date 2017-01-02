#include "window.h"
#include "style.h"
#include <fstream>

using namespace std;

Window::Window(string file): width{79}, height{25} {
	string s;
	ifstream f {file};
	for (int i = 0; i < height; i++) {
		getline(f, s);
		vector<char> arr;
		for (int j = 0; j < width; j++){
			arr.emplace_back(s[j]);
		}
		theDisplay.emplace_back(arr);
	}
	//cout << "window ctor works fine" << endl;
}	
	

void Window::notify(Subject &whoNotify){
	int r = whoNotify.getPos().posy;
	int c = whoNotify.getPos().posx;
	int t = whoNotify.getPos().style;
	switch (t){
        case SHADE:
		case AARON:
        case DROW:
        case VAMPIRE:
        case TROLL:
        case GOBLIN:
	case EASON:
	case NIGHTELF:
			p.posx = whoNotify.getPos().posx;
			p.posy = whoNotify.getPos().posy;
		//	theDisplay[r][c] = '@';
			break;
		case HUMAN:
			theDisplay[r][c] = 'H';
			break;
 		case DWARF:
			theDisplay[r][c] = 'W';
			break;
		case ELF:
			theDisplay[r][c] = 'E';
			break;
		case ORC:
			theDisplay[r][c] = 'O';
			break;
		case MERCHANT:
			theDisplay[r][c] = 'M';
			break;
		case DRAGON:
			theDisplay[r][c] = 'D';
			break;
		case HALFLING:
			theDisplay[r][c] = 'L';
			break;
		case RESTORE_HEALTH:
        case BOOST_ATK:
        case BOOST_DEF:
        case POISON_HEALTH:
        case WOUND_ATK:
        case WOUND_DEF:
			theDisplay[r][c] = 'P';
			break;
		case NORMAL_HOARD:
        case SMALL_HOARD:
        case MERCHANT_HOARD:
        case DRAGON_HOARD:
			theDisplay[r][c] = 'G';
			break;
		case STAIR:
			theDisplay[r][c] = '\\';
			break;
		case DOOR:
			theDisplay[r][c] = '+';
			break;
		case PASSAGE:
			theDisplay[r][c] = '#';
			break;
		case TILE:
			theDisplay[r][c] = '.';
			break;
		case BLOODELF:
			theDisplay[r][c] = 'B';
			break;
		case WORGEN:
			theDisplay[r][c] = 'R';
			break;
		case FORSAKEN:
			theDisplay[r][c] = 'F';
			break;
		case SPACE:
			theDisplay[r][c] = ' ';
			break;
		case VERTICAL_WALL:
			theDisplay[r][c] = '|';
			break;




	}
}

Window::~Window(){}


//SubscriptionType Window::subType() const {
  //  return SubscriptionType::All;
//}

ostream &operator<<(ostream &out, const Window &w){
	//clear screen;
	for (int i = 0; i < 100; i++){
		cout << endl;
	}
	int c = w.width;
	int r = w.height;
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			if (i == w.p.posy && j == w.p.posx){
				out << '@';
			} else out << w.theDisplay[i][j];
		}
		out << endl;
	}
	return out;
}

string Window::outPut(){
	ostringstream ss;
	int c = width;
	int r = height;
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			if (i == p.posy && j == p.posx){
				ss << '@';
			} else ss << theDisplay[i][j];
		}
		ss << endl;
	}
	string rs = ss.str();
	return rs;
}

vector<vector<char>> Window::colorOutPut(){
	vector<vector<char>> rv = theDisplay;//(theDisplay.size(), vector<char> (theDisplay[0].size()));
	for(int i = 0; i < theDisplay.size(); i++){
		for (int j = 0; j < theDisplay[0].size(); j++){
			if (i == p.posy && j == p.posx){
				rv[i][j] = '@';
			} else rv[i][j] == theDisplay[i][j];
		}
	}
	return rv;
}

