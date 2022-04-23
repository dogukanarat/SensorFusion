add_subdirectory(SFCore)
add_subdirectory(SFKalmanFilter)

install(
    EXPORT SFLibrary-config
    NAMESPACE SFLibrary::
    DESTINATION ${CMAKE_INSTALL_PREFIX}/cmake
)
