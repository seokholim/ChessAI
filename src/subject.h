#ifndef SUBJECT_H
#define SUBJECT_H

#include "observer.h"

class Subject {
  
  public:
    void notifyObservers();
    void attachObserver(Observer *);
    void detachObserver(Observer *);
};

#endif