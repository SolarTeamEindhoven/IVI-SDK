TARGET = IVI-App
QT = core core-private dbus qml quick quick-private waylandcompositor xml

CONFIG += c++14

MODULE = IVI-App
MODULE_PLUGIN_TYPES = ivi-vehicleinteractionbackend
load(qt_module)

DEFINES += QT_BUILD_IVI_APP_LIB

HEADERS += \
    iviappglobal.h \
    ividbusmanager_p.h \
    ividbusvehicledata_p.h \
    ividbusvehiclesetting_p.h \
    ivivehicledata.h \
    ivivehiclesetting.h

SOURCES += \
    ividbusmanager.cpp \
    ividbusvehicledata.cpp \
    ividbusvehiclesetting.cpp \
    ivivehicledata.cpp \
    ivivehiclesetting.cpp

DBUS_INTERFACES += ../protocol/DBUSManager.xml ../protocol/DBUSVehicleData.xml ../protocol/DBUSVehicleSetting.xml
