add_library(
    SFCore
)

target_link_libraries(
    SFCore
    PRIVATE
        Qt5::Core   
)

target_sources(
    SFCore
    PRIVATE
        SFUtilities.cpp
)

target_include_directories(
    SFCore 
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/>
           $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

install(
    TARGETS SFCore
    EXPORT SFLibrary-config
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(
    DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/SFCore/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/SFCore
)
