#include "frog.h"
#include "npc_visitor.h"

Frog::Frog(const std::string& name, int x, int y) : NPC(name, x, y) {}

void Frog::accept(NPCVisitor& visitor) {
    visitor.visit(*this);
}

std::string Frog::getType() const {
    return "Frog";
}
