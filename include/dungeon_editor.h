#ifndef DUNGEON_EDITOR_H
#define DUNGEON_EDITOR_H

#include <vector>
#include <memory>
#include <string>
#include "npc.h"
#include "battle_observer.h"

class DungeonEditor {
private:
    std::vector<NPCPtr> npcs;
    std::shared_ptr<BattleObserver> battleObserver;
public:
    DungeonEditor();
    void addNPC(NPCPtr npc);
    void removeNPC(const std::string& name);
    void printAll() const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
    void battle(int range);
    void addBattleObserver(std::shared_ptr<Observer> observer);
    const std::vector<NPCPtr>& getNPCs() const;
};

#endif
