cmake_minimum_required(VERSION 3.10)
project(Pro)

# Disable warning C4996 for windows MSbuild
if(MSVC)
    add_definitions(/wd4996)
endif()

# Generate Clangd compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

# Avoid MSBuild putting Debug and Release in seperate folder
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${OUTPUT_DIRECTORY}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${OUTPUT_DIRECTORY}")

add_library(compiler_flags INTERFACE)
target_compile_features(compiler_flags INTERFACE cxx_std_11)

include_directories(${CMAKE_SOURCE_DIR}/common/Queue)
include_directories(${CMAKE_SOURCE_DIR}/common/Deque)
include_directories(${CMAKE_SOURCE_DIR}/common/Stack)
include_directories(${CMAKE_SOURCE_DIR}/common/Point)
include_directories(${CMAKE_SOURCE_DIR}/common/Graph)
include_directories(${CMAKE_SOURCE_DIR}/common/Utils)

file(GLOB CMAKE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/Advance ${CMAKE_CURRENT_SOURCE_DIR}/Advance/*)
foreach(CMAKE_FILE ${CMAKE_FILES})
    if(EXISTS ${CMAKE_FILE}/CMakeLists.txt)
        get_filename_component(PROJECT_NAME ${CMAKE_FILE} NAME)
        message(${PROJECT_NAME})
        add_subdirectory(Advance/${PROJECT_NAME})
    endif()
endforeach()

add_subdirectory(Pro/Bacteria)
add_subdirectory(Pro/Civilization)
add_subdirectory(Pro/Constellation_Search)
add_subdirectory(Pro/Dictionary)
add_subdirectory(Pro/Dungeon_escape)
add_subdirectory(Pro/Image_Searching)
add_subdirectory(Pro/Memory_System)
add_subdirectory(Pro/Microorganism)
add_subdirectory(Pro/Morning_Commute_Radio)
add_subdirectory(Pro/Notepad_Program)
add_subdirectory(Pro/Online_Streamer)
add_subdirectory(Pro/Push)
add_subdirectory(Pro/Reserved_bus)
add_subdirectory(Pro/Scattered_Constellation_Tiles)
add_subdirectory(Pro/Secondhand_Market_App)
add_subdirectory(Pro/Soldier_Management)
add_subdirectory(Pro/Stock_Price)
add_subdirectory(Pro/Survival_Train)
add_subdirectory(Pro/Table_of_Ranking)
add_subdirectory(Pro/Toll_Discount)
add_subdirectory(Pro/Value_of_Restaurant)
add_subdirectory(Pro/Vocab_Sheet)
add_subdirectory(Pro/Water_Tank_Installing)
add_subdirectory(Pro/Web_Service)
add_subdirectory(Pro/Word_Search)

add_subdirectory(User_Problems/BFS_Searching)
add_subdirectory(User_Problems/BasicTrie)
add_subdirectory(User_Problems/Howard_and_Convenience_Store)
add_subdirectory(User_Problems/Tree_Set_2)

add_subdirectory(common/Stack)
add_subdirectory(common/Trie)
add_subdirectory(common/Point)


