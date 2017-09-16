import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtQuick.Window 2.2
import QtQuick.Controls.Material 2.0

import QtDeviceUtilities.NetworkSettings 1.0

ApplicationWindow {
    visible: Window.FullScreen

    RowLayout {
        spacing: 2
        anchors.fill: parent

        ListView {
            id: interfaceOverview
            Layout.fillHeight: true
            Layout.preferredWidth: Math.max(Math.min(100, parent.width / 3), 256)
            model: NetworkSettingsManager.interfaces

            onCurrentIndexChanged: detailedView.currentIndex = currentIndex

            delegate: SwitchDelegate {
                width: parent.width
                text: name
                checked: modelData.powered;
                highlighted: ListView.isCurrentItem
                onCheckedChanged: modelData.powered = checked
                onClicked: interfaceOverview.currentIndex = index
            }
        }

        ColumnLayout {
            SwipeView {
                id: detailedView
                Layout.fillHeight: true
                Layout.fillWidth: true
                clip: true

                onCurrentIndexChanged: interfaceOverview.currentIndex = currentIndex

                Repeater {
                    model: NetworkSettingsManager.interfaces
                    Loader {
                        Page {
                            ListView.onCurrentItemChanged: {
                                if(ListView.isCurrentItem)
                                    modelData.scanServices()
                            }

                            ListView {
                                anchors.fill: parent
                                model: NetworkSettingsManager.services
                                spacing: 2
                                delegate: Column {
                                    padding: 4
                                    Label { text: "Name: " + modelData.name }
                                    Label { text: "IPv4: " + modelData.ipv4.address }
                                }
                            }
                        }
                    }
                }
            }

            PageIndicator {
                currentIndex: detailedView.currentIndex
                count: detailedView.count
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }
    }
}
