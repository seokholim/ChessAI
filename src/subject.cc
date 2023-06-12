#include "subject.h"

void Subject::attach(Observer* ob) {
    this->observers.push_back(ob);
}

void Subject::detach(Observer* ob) {
    for (auto it = observers.begin(); it != observers.end(); ++it) {
        if (*it == ob) {
            observers.erase(it);
            break;
        }
    }
}

void Subject::notify() {
    for (auto it = observers.begin(); it != observers.end(); ++it) {
        (*it)->update();
    }
}