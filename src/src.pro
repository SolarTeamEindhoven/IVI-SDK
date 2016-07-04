TEMPLATE = subdirs
CONFIG += ordered
SUBDIRS += \
    STE-SDK \
    plugins

qtHaveModule(quick) {
    src_imports.subdir = imports
    src_imports.depends = STE-SDK
    SUBDIRS += src_imports
}
