#ifndef SUBJECT_H
#define SUBJECT_H
#include "observer.h"
#include <vector>

class Subject {
  protected:
    std::vector<Observer*> observers;
  public:
    void attach(Observer* ob);
    void detach(Observer* ob);
    void notify();
};

#endif