#ifndef SUBJECT_H
#define SUBJECT_H

#include "observer.h"

class Subject {
  public:
    virtual void attach(Observer *);
    virtual void detach(Observer *);
    virtual void notify();
};

#endif