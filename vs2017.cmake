if (MSVC_VERSION)

    set(VC_DLL_DIR C:/BuildTools/VC/Tools/MSVC/14.15.26726/bin/HostX86/x86)

    install(
        FILES 
            ${VC_DLL_DIR}/msvcp140.dll
            ${VC_DLL_DIR}/vcruntime140.dll
        DESTINATION bin)

endif (MSVC_VERSION)
