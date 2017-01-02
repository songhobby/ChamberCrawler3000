#ifndef __WINDOW_H_
#define __WINDOW_H_
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>
#include "observer.h"
#include "subject.h"
#include "subscriptions.h"

class Object;

class Window: public Observer {
	std::vector<std::vector<char>> theDisplay;
	const int width,height;
	Pos p {-1,-1, SHADE};

	public:
    Window(std::string file);
	
	void notify(Subject &whoNotify) override;
	//since we there is only one type of observer in the program.
	//SubscriptionType subType() const override;

	~Window();
    
    //SubscriptionType subType() const override;

	std::string outPut();
	std::vector<std::vector<char>> colorOutPut();
	friend std::ostream &operator<<(std::ostream &out, const Window &w);
};

#endif

