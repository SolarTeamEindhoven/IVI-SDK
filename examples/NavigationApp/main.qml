import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtQuick.Window 2.2
import QtLocation 5.9
import QtPositioning 5.6

import ivi.app 1.0

ApplicationWindow {
    visible: Window.FullScreen

    Map {
        id: map
        anchors.fill: parent
        plugin: Plugin {
            name: "mapboxgl"
            PluginParameter {
                name: "mapboxgl.access_token"
                value: "pk.eyJ1Ijoic3RldmVudmRzY2hvb3QiLCJhIjoiY2o3dnk3Z3JpNHlqODMzcXAzYW1tNXZrcCJ9.laBxzf74WciYkjgADpOBKA"
            }
        }
        center: QtPositioning.coordinate(51.447859, 5.499963)
        bearing: -30
        zoomLevel: 19
        tilt: maximumTilt

        MapQuickItem {
            coordinate: QtPositioning.coordinate(51.447862, 5.4999)
            sourceItem: Image {
                width: 30
                height: width
                source: "Car.png"
                rotation: -30
            }
            anchorPoint.x: sourceItem.width/2
            anchorPoint.y: sourceItem.height/2
            zoomLevel: 19
        }
    }
}
