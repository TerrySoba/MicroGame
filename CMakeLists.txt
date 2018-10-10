cmake_minimum_required(VERSION 3.10)

project(MicroGame)

set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/install/${PROJECT_NAME})

# include(mingw64.cmake)
include(sdl2.cmake)
include(package.cmake)

include_directories(${SDL2_INCLUDE_DIRS})

include_directories(3rd_party/chaiscript)
include_directories(3rd_party/tclap)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME}
    game_loop.h
    game_loop.cpp
    main.cpp)

install(TARGETS ${PROJECT_NAME}
        DESTINATION bin)

install(FILES ${CMAKE_SOURCE_DIR}/rgb.bmp
        DESTINATION bin)


include_directories(
    ${OPENGL_INCLUDE_DIR}
    ${SDL2_INCLUDE_DIR})

target_link_libraries(${PROJECT_NAME}
    ${SDL2_LIBRARIES} -pthread)
