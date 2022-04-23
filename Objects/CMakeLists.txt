add_subdirectory(SFKalmanFilterObject)

install(
    EXPORT SFObjects-config
    NAMESPACE SFObjects::
    DESTINATION ${CMAKE_INSTALL_PREFIX}/cmake
)