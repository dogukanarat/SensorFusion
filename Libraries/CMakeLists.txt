add_subdirectory(SFCore)

install(
    EXPORT SFLibrary-config
    NAMESPACE SFLibrary::
    DESTINATION ${CMAKE_INSTALL_PREFIX}/cmake
)
