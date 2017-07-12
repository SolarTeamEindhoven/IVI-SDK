QT += qml quick IVI-SDK

CONFIG += c++11

SOURCES += main.cpp

RESOURCES += qml.qrc

DISTFILES += MANIFEST

target.path = $$[QT_INSTALL_EXAMPLES]/IVI-SDK/TestApp
INSTALLS += target
