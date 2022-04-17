add_library(
    SFSensorControlWidget
)

target_link_libraries(
    SFSensorControlWidget
    PUBLIC
        Qt5::Core
        Qt5::Widgets
        SFBaseWidget
)

target_sources(
    SFSensorControlWidget
    PRIVATE
        SFSensorControlWidget.ui
        SFSensorControlWidget.cpp
        SFSensorControlWidget/SFSensorControlWidget.h
)

target_include_directories(
    SFSensorControlWidget 
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/>
           $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

install(
    TARGETS SFSensorControlWidget
    EXPORT ChessieWidgets-config
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(
    DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/SFSensorControlWidget/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/SFSensorControlWidget
)