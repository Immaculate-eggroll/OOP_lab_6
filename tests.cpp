#include <gtest/gtest.h>
#include "dungeon_editor.h"
#include "npc_factory.h"
#include "console_observer.h"

TEST(NPCFactoryTest, CreateNPC) {
    auto dragon = NPCFactory::createNPC("Dragon", "TestDragon", 10, 20);
    ASSERT_NE(dragon, nullptr);
    EXPECT_EQ(dragon->getType(), "Dragon");
    EXPECT_EQ(dragon->getName(), "TestDragon");
    EXPECT_EQ(dragon->getX(), 10);
    EXPECT_EQ(dragon->getY(), 20);

    auto bull = NPCFactory::createNPC("Bull", "TestBull", 30, 40);
    ASSERT_NE(bull, nullptr);
    EXPECT_EQ(bull->getType(), "Bull");

    auto frog = NPCFactory::createNPC("Frog", "TestFrog", 50, 60);
    ASSERT_NE(frog, nullptr);
    EXPECT_EQ(frog->getType(), "Frog");
}

TEST(NPCFactoryTest, SaveLoad) {
    auto npc = NPCFactory::createNPC("Dragon", "SaveTest", 100, 200);
    std::string saved = NPCFactory::saveToString(*npc);
    auto loaded = NPCFactory::loadFromString(saved);
    
    ASSERT_NE(loaded, nullptr);
    EXPECT_EQ(loaded->getType(), "Dragon");
    EXPECT_EQ(loaded->getName(), "SaveTest");
    EXPECT_EQ(loaded->getX(), 100);
    EXPECT_EQ(loaded->getY(), 200);
}

TEST(DungeonEditorTest, AddRemoveNPC) {
    DungeonEditor editor;
    auto npc = NPCFactory::createNPC("Dragon", "Test", 250, 250);
    
    editor.addNPC(npc);
    EXPECT_EQ(editor.getNPCs().size(), 1);
    
    editor.removeNPC("Test");
    EXPECT_EQ(editor.getNPCs().size(), 0);
}

TEST(DungeonEditorTest, BoundaryCheck) {
    DungeonEditor editor;
    auto npc1 = NPCFactory::createNPC("Dragon", "Valid", 250, 250);
    auto npc2 = NPCFactory::createNPC("Bull", "Invalid", 600, 600);
    
    editor.addNPC(npc1);
    editor.addNPC(npc2);
    
    EXPECT_EQ(editor.getNPCs().size(), 1);
    EXPECT_EQ(editor.getNPCs()[0]->getName(), "Valid");
}

TEST(DungeonEditorTest, SaveLoadFile) {
    DungeonEditor editor1;
    editor1.addNPC(NPCFactory::createNPC("Dragon", "D1", 10, 20));
    editor1.addNPC(NPCFactory::createNPC("Bull", "B1", 30, 40));
    
    editor1.saveToFile("test_save.txt");
    
    DungeonEditor editor2;
    editor2.loadFromFile("test_save.txt");
    
    EXPECT_EQ(editor2.getNPCs().size(), 2);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
