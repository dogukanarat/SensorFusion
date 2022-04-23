add_subdirectory(SensorFusion)
add_subdirectory(KalmanFilter)

install(
    EXPORT SF-config
    NAMESPACE SF::
    DESTINATION ${CMAKE_INSTALL_PREFIX}/cmake
)