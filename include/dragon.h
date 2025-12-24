#ifndef DRAGON_H
#define DRAGON_H

#include "npc.h"

class Dragon : public NPC {
public:
    Dragon(const std::string& name, int x, int y);
    void accept(NPCVisitor& visitor) override;
    std::string getType() const override;
};

#endif
