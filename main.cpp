#include <iostream>
#include <memory>
#include "dungeon_editor.h"
#include "npc_factory.h"
#include "console_observer.h"
#include "file_observer.h"

int main() {
    DungeonEditor editor;
    
    auto consoleObs = std::make_shared<ConsoleObserver>();
    auto fileObs = std::make_shared<FileObserver>("log.txt");
    
    editor.addBattleObserver(consoleObs);
    editor.addBattleObserver(fileObs);

    editor.addNPC(NPCFactory::createNPC("Dragon", "Smaug", 100, 100));
    editor.addNPC(NPCFactory::createNPC("Bull", "Ferdinand", 150, 150));
    editor.addNPC(NPCFactory::createNPC("Frog", "Kermit", 120, 120));
    editor.addNPC(NPCFactory::createNPC("Dragon", "Toothless", 130, 130));
    editor.addNPC(NPCFactory::createNPC("Bull", "Raging", 140, 140));

    std::cout << "Initial NPCs:" << std::endl;
    editor.printAll();

    editor.saveToFile("dungeon.txt");

    std::cout << "\nStarting battle with range 50:" << std::endl;
    editor.battle(50);

    std::cout << "\nSurviving NPCs:" << std::endl;
    editor.printAll();

    std::cout << "\nLoading from file..." << std::endl;
    editor.loadFromFile("dungeon.txt");
    editor.printAll();

    return 0;
}
