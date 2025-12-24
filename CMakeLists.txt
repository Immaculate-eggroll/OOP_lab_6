cmake_minimum_required(VERSION 3.16)
project(OOP_Lab6)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(main
    main.cpp
    src/npc.cpp
    src/dragon.cpp
    src/bull.cpp
    src/frog.cpp
    src/npc_factory.cpp
    src/console_observer.cpp
    src/file_observer.cpp
    src/battle_observer.cpp
    src/npc_visitor.cpp
    src/dungeon_editor.cpp
)

find_package(GTest REQUIRED)
add_executable(tests
    tests.cpp
    src/npc.cpp
    src/dragon.cpp
    src/bull.cpp
    src/frog.cpp
    src/npc_factory.cpp
    src/console_observer.cpp
    src/file_observer.cpp
    src/battle_observer.cpp
    src/npc_visitor.cpp
    src/dungeon_editor.cpp
)
target_link_libraries(tests GTest::gtest GTest::gtest_main)
