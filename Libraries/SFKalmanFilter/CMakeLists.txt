add_library(
    SFKalmanFilter
)

target_link_libraries(
    SFKalmanFilter
    PRIVATE
        SFCore
        Eigen 
)

target_sources(
    SFKalmanFilter
    PRIVATE
        SFKalmanFilter.cpp
)

target_include_directories(
    SFKalmanFilter 
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/>
           $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

install(
    TARGETS SFKalmanFilter
    EXPORT SFLibrary-config
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(
    DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/SFKalmanFilter/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/SFKalmanFilter
)
