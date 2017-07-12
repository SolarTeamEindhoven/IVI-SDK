TEMPLATE = subdirs
CONFIG += ordered
SUBDIRS += \
    IVI-SDK \
    plugins

qtHaveModule(quick) {
    src_imports.subdir = imports
    src_imports.depends = IVI-SDK
    SUBDIRS += src_imports
}
