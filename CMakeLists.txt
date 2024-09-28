cmake_minimum_required(VERSION 3.10)
project(DSA)

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

include_directories(${CMAKE_SOURCE_DIR}/common/Deque)
include_directories(${CMAKE_SOURCE_DIR}/common/Graph)
include_directories(${CMAKE_SOURCE_DIR}/common/List)
include_directories(${CMAKE_SOURCE_DIR}/common/Point)
include_directories(${CMAKE_SOURCE_DIR}/common/Queue)
include_directories(${CMAKE_SOURCE_DIR}/common/Stack)
include_directories(${CMAKE_SOURCE_DIR}/common/Trie)
include_directories(${CMAKE_SOURCE_DIR}/common/Utils)

file(GLOB CMAKE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/Advance ${CMAKE_CURRENT_SOURCE_DIR}/Advance/*)
foreach(CMAKE_FILE ${CMAKE_FILES})
    if(EXISTS ${CMAKE_FILE}/CMakeLists.txt)
        get_filename_component(PROJECT_NAME ${CMAKE_FILE} NAME)
        # message(${PROJECT_NAME})
        add_subdirectory(Advance/${PROJECT_NAME})
    endif()
endforeach()

file(GLOB CMAKE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/Pro ${CMAKE_CURRENT_SOURCE_DIR}/Pro/*)
foreach(CMAKE_FILE ${CMAKE_FILES})
    if(EXISTS ${CMAKE_FILE}/CMakeLists.txt)
        get_filename_component(PROJECT_NAME ${CMAKE_FILE} NAME)
        # message(${PROJECT_NAME})
        add_subdirectory(Pro/${PROJECT_NAME})
    endif()
endforeach()

file(GLOB CMAKE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/User_Problems ${CMAKE_CURRENT_SOURCE_DIR}/User_Problems/*)
foreach(CMAKE_FILE ${CMAKE_FILES})
    if(EXISTS ${CMAKE_FILE}/CMakeLists.txt)
        get_filename_component(PROJECT_NAME ${CMAKE_FILE} NAME)
        # message(${PROJECT_NAME})
        add_subdirectory(User_Problems/${PROJECT_NAME})
    endif()
endforeach()

add_subdirectory(common/Stack)
add_subdirectory(common/Trie)
add_subdirectory(common/Point)
