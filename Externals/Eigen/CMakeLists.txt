add_library(Eigen)

target_include_directories(
    Eigen 
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/>
           $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

install(
    TARGETS Eigen
    EXPORT Eigen-config
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(
    DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/Eigen/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/Eigen
)

install(
    EXPORT Eigen-config
    NAMESPACE Eigen::
    DESTINATION ${CMAKE_INSTALL_PREFIX}/cmake
)