#include "npc.h"
#include <cmath>

NPC::NPC(const std::string& name, int x, int y) : name(name), x(x), y(y) {}

std::string NPC::getName() const {
    return name;
}

int NPC::getX() const {
    return x;
}

int NPC::getY() const {
    return y;
}

void NPC::setPosition(int x, int y) {
    this->x = x;
    this->y = y;
}

bool NPC::inRange(const NPC& other, int range) const {
    int dx = x - other.x;
    int dy = y - other.y;
    return std::sqrt(dx*dx + dy*dy) <= range;
}
