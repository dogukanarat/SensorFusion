add_library(
    SFBaseWidget
)

target_link_libraries(
    SFBaseWidget
    PUBLIC
        Qt5::Core
        Qt5::Widgets
        SFCore
)

target_sources(
    SFBaseWidget
    PRIVATE
        SFBaseWidget.cpp
        SFBaseWidget/SFBaseWidget.h
)

target_include_directories(
    SFBaseWidget 
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/>
           $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

install(
    TARGETS SFBaseWidget
    EXPORT SFWidgets-config
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(
    DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/SFBaseWidget/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/SFBaseWidget
)