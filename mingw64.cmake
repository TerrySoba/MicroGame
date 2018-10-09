if (WIN32)
    file(TO_CMAKE_PATH $ENV{MINGW_DIR} MINGW_DIR)
    install(
        FILES 
            ${MINGW_DIR}/bin/libgcc_s_seh-1.dll
            ${MINGW_DIR}/bin/libstdc++-6.dll
        DESTINATION bin)
endif (WIN32)
