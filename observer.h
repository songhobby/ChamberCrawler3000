#ifndef _OBSERVER_H_
#define _OBSERVER_H_
#include "subscriptions.h"

class Subject;

class Observer {
 public:
    virtual void notify(Subject &whoNotified){};
    virtual ~Observer() = default;
};

#endif
