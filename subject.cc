#include "subject.h"
#include "observer.h"

void Subject::attach(std::shared_ptr<Observer> ob) {
	observers.emplace_back(ob);
}

void Subject::notifyObservers() {
    for(auto o : observers) {
        o->notify(*this);
    }
}

