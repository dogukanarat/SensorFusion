set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_executable(
    SensorFusion
)

set(CUSTOM_HEADER "${CMAKE_CURRENT_SOURCE_DIR}/GeneratedHeader.h")

execute_process(
    COMMAND python ${CRESSIE_SCRIPT_DIR}/HelloWorld.py ${CUSTOM_HEADER}
    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})

target_sources(
    SensorFusion 
    PRIVATE
        MainWindow.cpp
        Main.cpp
        MainWindow.ui
        ${CUSTOM_HEADER}
)

add_dependencies(SensorFusion SFSensorControlWidget)

target_link_libraries(
    SensorFusion
    PUBLIC
        Qt5::Core
        Qt5::Widgets
        Qt5::Gui
        SFCore
        SFSensorControlWidget
        SFBaseWidget
        SFKalmanFilterObject
)

install(
    TARGETS SensorFusion
    EXPORT SF-config
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})


