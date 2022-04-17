add_subdirectory(SensorFusion)

install(
    EXPORT SF-config
    NAMESPACE SF::
    DESTINATION ${CMAKE_INSTALL_PREFIX}/cmake
)