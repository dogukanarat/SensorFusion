set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_library(
    SFKalmanFilterObject
)

target_link_libraries(
    SFKalmanFilterObject
    PUBLIC
        Qt5::Core
        Qt5::Widgets
        SFCore
        Eigen
)

target_sources(
    SFKalmanFilterObject
    PRIVATE
        SFKalmanFilterObject.cpp
        SFKalmanFilterObject/SFKalmanFilterObject.h
)

target_include_directories(
    SFKalmanFilterObject 
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/>
           $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

install(
    TARGETS SFKalmanFilterObject
    EXPORT SFObjects-config
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(
    DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/SFKalmanFilterObject/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/SFKalmanFilterObject
)
