#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
#include <memory>
#include "observer.h"

class Subject { // TODO: position
public:
    void attach(std::shared_ptr<Observer> ob);
    void detach(std::shared_ptr<Observer> ob);
    void notify();    
protected:
    std::vector<std::shared_ptr<Observer>> observers;
};

#endif