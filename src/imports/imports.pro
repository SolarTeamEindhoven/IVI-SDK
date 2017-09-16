CXX_MODULE = qml
TARGET = IVIAppPlugin
TARGETPATH = ivi/app/
IMPORT_VERSION = 1.0

QT += qml IVI-App IVI-App-private

SOURCES += pluginmain.cpp

OTHER_FILES += qmldir

load(qml_plugin)

HEADERS +=
