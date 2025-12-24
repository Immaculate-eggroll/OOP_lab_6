#include "battle_observer.h"

void BattleObserver::addObserver(std::shared_ptr<Observer> observer) {
    observers.push_back(observer);
}

void BattleObserver::notifyKill(const std::string& killer, const std::string& victim) {
    for (auto& obs : observers) {
        obs->onKill(killer, victim);
    }
}
