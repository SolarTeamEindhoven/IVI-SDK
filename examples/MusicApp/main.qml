import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtQuick.Window 2.2
import QtWebEngine 1.4

import ivi.app 1.0

ApplicationWindow {
    visible: Window.FullScreen

    WebEngineView {
        anchors.fill: parent
        settings.pluginsEnabled: true
        url: "https://play.spotify.com/"
    }
}
