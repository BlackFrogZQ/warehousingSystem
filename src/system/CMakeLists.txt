add_subdirectory(tool)
add_subdirectory(logSystem)
add_subdirectory(json)
# add_subdirectory(cardReader)
# add_subdirectory(ERP)
# add_subdirectory(LED)
# add_subdirectory(ET199)
# add_subdirectory(plcServer)

add_library(sysLib systemService.cpp)

target_link_libraries(sysLib
    jsonLib
    sysToolFunLib
    systemLogLib)

target_link_libraries(sysLib Qt5::Widgets Qt5::Network Qt5::SerialBus Qt5::Gui Qt5::Core Qt5::SerialPort Qt5::Concurrent Qt5::Qml) # Qt5 Shared Library