
if (WIN32)
    set(INTERNAL_SDL2_DIR C:/SDL2-devel-2.0.8-VC/SDL2-2.0.8/)
    set(SDL2_LIBRARIES
        ${INTERNAL_SDL2_DIR}/lib/x64/SDL2.lib
        ${INTERNAL_SDL2_DIR}/lib/x64/SDL2main.lib
        )
    set(SDL2_INCLUDE_DIR ${INTERNAL_SDL2_DIR}/include)

    install(FILES ${INTERNAL_SDL2_DIR}/lib/x64/SDL2.dll
        DESTINATION bin)
else (WIN32)
    find_package(SDL2 REQUIRED)
endif (WIN32)
