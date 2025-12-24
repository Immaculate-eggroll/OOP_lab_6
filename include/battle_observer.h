#ifndef BATTLE_OBSERVER_H
#define BATTLE_OBSERVER_H

#include "observer.h"
#include <vector>
#include <memory>

class BattleObserver {
private:
    std::vector<std::shared_ptr<Observer>> observers;
public:
    void addObserver(std::shared_ptr<Observer> observer);
    void notifyKill(const std::string& killer, const std::string& victim);
};

#endif
