add_custom_target(
    zip
    COMMAND ${CMAKE_COMMAND} -E tar cvf MicroGame.zip --format=zip ${CMAKE_INSTALL_PREFIX}
    WORKING_DIRECTORY ${CMAKE_INSTALL_PREFIX}/../
)
