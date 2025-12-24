#include "dungeon_editor.h"
#include "npc_factory.h"
#include "npc_visitor.h"
#include <fstream>
#include <iostream>
#include <algorithm>

DungeonEditor::DungeonEditor() {
    battleObserver = std::make_shared<BattleObserver>();
}

void DungeonEditor::addNPC(NPCPtr npc) {
    if (npc->getX() >= 0 && npc->getX() <= 500 && npc->getY() >= 0 && npc->getY() <= 500) {
        npcs.push_back(npc);
    }
}

void DungeonEditor::removeNPC(const std::string& name) {
    npcs.erase(std::remove_if(npcs.begin(), npcs.end(),
        [&name](const NPCPtr& npc) { return npc->getName() == name; }), npcs.end());
}

void DungeonEditor::printAll() const {
    for (const auto& npc : npcs) {
        std::cout << npc->getType() << " " << npc->getName() 
                  << " (" << npc->getX() << ", " << npc->getY() << ")" << std::endl;
    }
}

void DungeonEditor::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    for (const auto& npc : npcs) {
        file << NPCFactory::saveToString(*npc) << std::endl;
    }
}

void DungeonEditor::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    npcs.clear();
    while (std::getline(file, line)) {
        auto npc = NPCFactory::loadFromString(line);
        if (npc) npcs.push_back(npc);
    }
}

void DungeonEditor::battle(int range) {
    std::vector<NPCPtr> dead;
    NPCVisitor visitor(battleObserver, range);

    for (size_t i = 0; i < npcs.size(); ++i) {
        for (size_t j = 0; j < npcs.size(); ++j) {
            if (i == j) continue;
            visitor.setCurrentNPC(npcs[i]);
            npcs[j]->accept(visitor);
        }
    }

    for (const auto& npc : dead) {
        removeNPC(npc->getName());
    }
}

void DungeonEditor::addBattleObserver(std::shared_ptr<Observer> observer) {
    battleObserver->addObserver(observer);
}

const std::vector<NPCPtr>& DungeonEditor::getNPCs() const {
    return npcs;
}
