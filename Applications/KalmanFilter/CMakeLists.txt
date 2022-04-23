add_executable(
    KalmanFilter
)

target_sources(
    KalmanFilter
    PRIVATE
        Main.cpp
)

target_link_libraries(
    KalmanFilter
    PUBLIC
        SFCore
        SFKalmanFilter
        Eigen
)