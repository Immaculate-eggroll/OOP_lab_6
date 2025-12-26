cmake_minimum_required(VERSION 3.16)
project(OOP_Lab6)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Основная программа
add_executable(lab6_main
    src/main.cpp
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
target_include_directories(lab6_main PRIVATE include)

# GoogleTest через FetchContent
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.12.1
)
set(gtest_force_shared_crt OFF CACHE BOOL "" FORCE)
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Тесты
add_executable(lab6_tests
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
target_include_directories(lab6_tests PRIVATE include)
target_link_libraries(lab6_tests PRIVATE gtest_main)

include(GoogleTest)
gtest_discover_tests(lab6_tests)
