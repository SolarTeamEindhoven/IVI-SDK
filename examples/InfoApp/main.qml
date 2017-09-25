import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtQuick.Window 2.2
import QtQuick.Controls.Material 2.0

import QtDeviceUtilities.SettingsUI 1.0

ApplicationWindow {
    visible: Window.FullScreen

    SettingsUI {
        id: settingsUI
        anchors.fill: parent
    }
}
