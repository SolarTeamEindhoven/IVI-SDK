TARGET     = STE-SDK
QT         = core

load(qt_module)

DEFINES += QT_BUILD_STE_SDK_LIB

QMAKE_DOCS = $$PWD/doc/STE-SDK.qdocconf

HEADERS += qtstesdkglobal.h\
    stesoftkey.h \
    steshellmanager.h \
    stesoftkeyprovider.h
SOURCES += \
    stesoftkey.cpp \
    steshellmanager.cpp \
    stesoftkeyprovider.cpp
