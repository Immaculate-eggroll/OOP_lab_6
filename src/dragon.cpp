#include "dragon.h"
#include "npc_visitor.h"

Dragon::Dragon(const std::string& name, int x, int y) : NPC(name, x, y) {}

void Dragon::accept(NPCVisitor& visitor) {
    visitor.visit(*this);
}

std::string Dragon::getType() const {
    return "Dragon";
}
