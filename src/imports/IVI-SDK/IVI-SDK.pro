CXX_MODULE = IVI-SDK
TARGET  = declarative_IVI-SDK
TARGETPATH = solarteameindhoven/sdk
IMPORT_VERSION = 1.0

QT += qml quick quicktemplates2-private IVI-SDK

OTHER_FILES += qmldir

SOURCES += \
    IVISDK.cpp \
    steapp.cpp \
    stesoftkeyqml.cpp \
    stesoftkeyvisualqml.cpp

HEADERS += \
    steapp.h \
    stesoftkeyqml.h \
    stesoftkeyvisualqml.h

load(qml_plugin)

for(FILE, qmldir.files) {
    DDIR = $$DESTDIR

    # Replace slashes in paths with backslashes for Windows
    win32:FILE ~= s,/,\\,g
    win32:DDIR ~= s,/,\\,g

    QMAKE_POST_LINK += $$QMAKE_COPY $$quote($$FILE) $$quote($$DDIR) $$escape_expand(\\n\\t)
}
export(QMAKE_POST_LINK)
