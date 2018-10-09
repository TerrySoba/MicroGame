
if (WIN32)
    set(INTERNAL_SDL2_DIR C:/SDL2-2.0.8/x86_64-w64-mingw32/)
    set(SDL2_LIBRARIES
        ${INTERNAL_SDL2_DIR}/lib/libSDL2.dll.a
        ${INTERNAL_SDL2_DIR}/lib/libSDL2main.a
        )
    set(SDL2_INCLUDE_DIR ${INTERNAL_SDL2_DIR}/include)

    install(FILES ${INTERNAL_SDL2_DIR}/bin/SDL2.dll
        DESTINATION bin)

    file(TO_CMAKE_PATH $ENV{MINGW_DIR} MINGW_DIR)

    install(
        FILES 
            ${MINGW_DIR}/bin/libgcc_s_seh-1.dll
            ${MINGW_DIR}/bin/libstdc++-6.dll
        DESTINATION bin)

else (WIN32)
    find_package(SDL2 REQUIRED)
endif (WIN32)
