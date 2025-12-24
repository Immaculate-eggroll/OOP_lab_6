#ifndef BULL_H
#define BULL_H

#include "npc.h"

class Bull : public NPC {
public:
    Bull(const std::string& name, int x, int y);
    void accept(NPCVisitor& visitor) override;
    std::string getType() const override;
};

#endif
