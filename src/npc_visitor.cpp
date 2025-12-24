#include "npc_visitor.h"
#include "dragon.h"
#include "bull.h"
#include "frog.h"

NPCVisitor::NPCVisitor(std::shared_ptr<BattleObserver> observer, int range) 
    : observer(observer), range(range) {}

void NPCVisitor::setCurrentNPC(NPCPtr npc) {
    currentNPC = npc;
}

void NPCVisitor::visit(Dragon& dragon) {
    auto other = std::dynamic_pointer_cast<Dragon>(currentNPC);
    if (other && other.get() != &dragon) {
        if (currentNPC->inRange(dragon, range)) {
            observer->notifyKill(currentNPC->getName(), dragon.getName());
        }
    }
}

void NPCVisitor::visit(Bull& bull) {
    if (currentNPC->getType() == "Dragon") {
        if (currentNPC->inRange(bull, range)) {
            observer->notifyKill(currentNPC->getName(), bull.getName());
        }
    }
}

void NPCVisitor::visit(Frog& frog) {
    if (currentNPC->getType() == "Bull") {
        if (currentNPC->inRange(frog, range)) {
            observer->notifyKill(currentNPC->getName(), frog.getName());
        }
    }
}

bool NPCVisitor::shouldAttack(NPCPtr other) {
    return false;
}
