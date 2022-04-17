add_subdirectory(SFBaseWidget)
add_subdirectory(SFSensorControlWidget)

install(
    EXPORT SFWidgets-config
    NAMESPACE SFWidgets::
    DESTINATION ${CMAKE_INSTALL_PREFIX}/cmake
)
