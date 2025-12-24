#include "console_observer.h"
#include <iostream>

void ConsoleObserver::onKill(const std::string& killer, const std::string& victim) {
    std::cout << "[CONSOLE] " << killer << " killed " << victim << std::endl;
}
