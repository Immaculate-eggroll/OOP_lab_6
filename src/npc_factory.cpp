#include "npc_factory.h"
#include "dragon.h"
#include "bull.h"
#include "frog.h"
#include <sstream>

NPCPtr NPCFactory::createNPC(const std::string& type, const std::string& name, int x, int y) {
    if (type == "Dragon") return std::make_shared<Dragon>(name, x, y);
    if (type == "Bull") return std::make_shared<Bull>(name, x, y);
    if (type == "Frog") return std::make_shared<Frog>(name, x, y);
    return nullptr;
}

NPCPtr NPCFactory::loadFromString(const std::string& data) {
    std::istringstream iss(data);
    std::string type, name;
    int x, y;
    iss >> type >> name >> x >> y;
    return createNPC(type, name, x, y);
}

std::string NPCFactory::saveToString(const NPC& npc) {
    std::ostringstream oss;
    oss << npc.getType() << " " << npc.getName() << " " << npc.getX() << " " << npc.getY();
    return oss.str();
}
