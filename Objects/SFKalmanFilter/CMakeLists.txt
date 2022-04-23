set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_library(
    SFKalmanFilter
)

target_link_libraries(
    SFKalmanFilter
    PUBLIC
        Qt5::Core
        Qt5::Widgets
        SFCore
        Eigen
)

target_sources(
    SFKalmanFilter
    PRIVATE
        SFKalmanFilter.cpp
        SFKalmanFilter/SFKalmanFilter.h
)

target_include_directories(
    SFKalmanFilter 
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/>
           $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

install(
    TARGETS SFKalmanFilter
    EXPORT SFObjects-config
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(
    DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/SFKalmanFilter/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/SFKalmanFilter
)
