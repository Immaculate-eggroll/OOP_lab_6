#pragma once

#include <memory>
#include "battle_observer.h"

class Dragon;
class Bull;
class Frog;

class NPC;
using NPCPtr = std::shared_ptr<NPC>;

class NPCVisitor {
private:
    std::shared_ptr<BattleObserver> observer;
    NPCPtr currentNPC;
    int range;
    
public:
    NPCVisitor(std::shared_ptr<BattleObserver> observer, int range);
    void setCurrentNPC(NPCPtr npc);
    void visit(Dragon& dragon);
    void visit(Bull& bull);
    void visit(Frog& frog);
    bool shouldAttack(NPCPtr other);
};
