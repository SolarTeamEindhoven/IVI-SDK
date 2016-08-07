TARGET     = STE-SDK
QT         = core dbus

load(qt_module)

DEFINES += QT_BUILD_STE_SDK_LIB

QMAKE_DOCS = $$PWD/doc/STE-SDK.qdocconf

DBUS_INTERFACES += ../protocol/DBUSManager.xml ../protocol/DBUSVehicleData.xml

HEADERS += qtstesdkglobal.h\
    stesoftkey.h \
    steshellmanager.h \
    stesoftkeyprovider.h \
    stevehicledata.h \
    stedbusmanager_p.h \
    stedbusvehicledata_p.h
SOURCES += \
    stesoftkey.cpp \
    steshellmanager.cpp \
    stesoftkeyprovider.cpp \
    stevehicledata.cpp \
    stedbusmanager.cpp \
    stedbusvehicledata.cpp
