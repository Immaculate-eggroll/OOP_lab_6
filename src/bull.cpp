#include "bull.h"
#include "npc_visitor.h"

Bull::Bull(const std::string& name, int x, int y) : NPC(name, x, y) {}

void Bull::accept(NPCVisitor& visitor) {
    visitor.visit(*this);
}

std::string Bull::getType() const {
    return "Bull";
}
