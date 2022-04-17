add_subdirectory(SFKalmanFilter)
install(
    EXPORT SFObjects-config
    NAMESPACE SFObjects::
    DESTINATION ${CMAKE_INSTALL_PREFIX}/cmake
)
