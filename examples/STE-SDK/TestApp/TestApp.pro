QT += qml quick STE-SDK

CONFIG += c++11

SOURCES += main.cpp

RESOURCES += qml.qrc

DISTFILES += MANIFEST

target.path = $$[QT_INSTALL_EXAMPLES]/STE-SDK/TestApp
INSTALLS += target
