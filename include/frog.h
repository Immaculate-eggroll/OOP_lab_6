#ifndef FROG_H
#define FROG_H

#include "npc.h"

class Frog : public NPC {
public:
    Frog(const std::string& name, int x, int y);
    void accept(NPCVisitor& visitor) override;
    std::string getType() const override;
};

#endif
