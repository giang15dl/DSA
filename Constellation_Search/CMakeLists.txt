get_filename_component(PROJECT_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
add_executable(${PROJECT_NAME} main.cpp solution.cpp)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/sample_input.txt ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
