#PLUGIN_TYPE = platforms

TEMPLATE = lib
TARGET  = STE-wayland
#DATAPATH = $$[QT_INSTALL_DATA]/stewayland

CONFIG += plugin

!no-pkg-config: CONFIG += link_pkgconfig

#PLUGIN_TYPE = platforms
PLUGIN_TYPE = wayland-shell-integration
PLUGIN_EXTENDS = -
PLUGIN_CLASS_NAME = CustomIntegrationPlugin
load(qt_plugin)

CONFIG += wayland-scanner
CONFIG += link_pkgconfig

QT += IVI-SDK waylandclient-private
!contains(QT_CONFIG, no-pkg-config) {
    PKGCONFIG += wayland-client
} else {
    LIBS += -lwayland-client
}

WAYLANDCLIENTSOURCES += ../../protocol/STE.xml

OTHER_FILES += STEWaylandShellIntegration.json

SOURCES += main.cpp \
    customextension.cpp \
    steshell.cpp \
    stesurface.cpp \
    stesoftkey.cpp \
    stesoftkeyproviderimplementation.cpp

HEADERS += customextension.h \
    steshell.h \
    stesurface.h \
    stesoftkey.h \
    stesoftkeyproviderimplementation.h

