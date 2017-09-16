import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtQuick.Window 2.2
import QtLocation 5.6
import QtPositioning 5.6

import ivi.app 1.0

ApplicationWindow {
    visible: Window.FullScreen

    Map {
        anchors.fill: parent
        plugin: Plugin {
            name: "osm"
        }
        center: QtPositioning.coordinate(51.447971, 5.496258)
        zoomLevel: 16
    }
}
