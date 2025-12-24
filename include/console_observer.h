#ifndef CONSOLE_OBSERVER_H
#define CONSOLE_OBSERVER_H

#include "observer.h"

class ConsoleObserver : public Observer {
public:
    void onKill(const std::string& killer, const std::string& victim) override;
};

#endif
