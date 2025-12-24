#ifndef NPC_FACTORY_H
#define NPC_FACTORY_H

#include <memory>
#include <string>
#include "npc.h"

class NPCFactory {
public:
    static NPCPtr createNPC(const std::string& type, const std::string& name, int x, int y);
    static NPCPtr loadFromString(const std::string& data);
    static std::string saveToString(const NPC& npc);
};

#endif
