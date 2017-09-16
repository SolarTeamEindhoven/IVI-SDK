TEMPLATE = aux

build_online_docs: {
    QMAKE_DOCS_TARGETDIR = IVI-App
    QMAKE_DOCS = $$PWD/config/IVI-App-online.qdocconf
} else {
    QMAKE_DOCS = $$PWD/config/IVI-App.qdocconf
}

QMAKE_DOCS_OUTPUTDIR = $$OUT_PWD/IVI-App
