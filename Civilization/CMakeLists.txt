add_executable(Civilization main.cpp solution.cpp)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/sample_input.txt ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)