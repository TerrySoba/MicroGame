cmake_minimum_required(VERSION 3.10)

project(MicroGame)

include(sdl2.cmake)

include_directories(${SDL2_INCLUDE_DIRS})

include_directories(3rd_party/chaiscript)
include_directories(3rd_party/tclap)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME}
    main.cpp)

include_directories(
    ${OPENGL_INCLUDE_DIR}
    ${SDL2_INCLUDE_DIR})

target_link_libraries(${PROJECT_NAME}
    ${SDL2_LIBRARIES} -ldl -pthread)
