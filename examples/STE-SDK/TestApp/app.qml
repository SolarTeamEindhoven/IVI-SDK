import QtQuick 2.6
import QtQuick.Controls 2.0
import solarteameindhoven.sdk 1.0

App
{
    id: app

    onSoftKeyListChanged: {
        console.log("Amount of softkeys: ", app.softKeyList.length);
        for(var i in app.softKeyList) {
            console.log("Softkey " + i + ": ", app.softKeyList[i].hint);

            switch(app.softKeyList[i].hint) {
            case "LAYR_left":
                leftButton.softkey = app.softKeyList[i];
                break;
            }
        }
    }

    SoftKeyVisual {
        id: leftButton

        width: hintSize.width
        height: hintSize.height
        visible: true

        hintList: ["LAYR_left", "left"]

        onClicked: {
            console.log("Left button clicked!");
        }

        Rectangle {
            id: rect

            anchors.fill: parent
            radius: width/2

            color: "green"

            SequentialAnimation {
                running: true
                loops: Animation.Infinite
                ColorAnimation { target: rect; property: "color"; to: "blue"; duration: 1000 }
                ColorAnimation { target: rect; property: "color"; to: "red"; duration: 1000 }
                ColorAnimation { target: rect; property: "color"; to: "green"; duration: 1000 }
            }
        }
    }

    /*
    VehicleData
    {
        id: batVoltage
        name: "bat_voltage"
    }

    VehicleSettings
    {
        id: settings
        name: "volume"
        value: 100
    }

    Label
    {
        anchors.verticalCenter: parent.verticalCenter
        anchors.top: parent.top
        text: "Battery volgate: " + batVoltage.value + "V"
    }
    //*/

    Image {
        source: "qrc:/images/qt-logo.png"

        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.leftMargin: 10
        fillMode: Image.PreserveAspectFit
    }

    Label
    {
        id: text
        anchors.centerIn: parent
        text: "Current time: " + Date().toString()
    }

    Timer {
        interval: 100
        running: true
        repeat: true
        onTriggered: {
            text.text = "Current time: " + Date().toString()
        }
    }

    Column {
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: parent.right

        RadioButton { text: qsTr("Option A") }
        RadioButton { text: qsTr("Option B");  checked: true }
        RadioButton { text: qsTr("Option C") }
    }

    Button {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: app.height / 20

        text: "Button"
    }
}
