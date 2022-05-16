import QtQuick 2.0

Item {
    width: 800
    height: 480





    Rectangle {
        id: hovedmenu
        x: 203
        y: 256
        width: 87
        height: 48
        visible: true
        color: "#ffffff"

        Text {
            id: hovedmenutekst
            x: 10
            y: 16
            text: qsTr("Hovedmenu")
            font.pixelSize: 12
            font.bold: true
        }
    }

    Rectangle {
        id: logaf1
        x: 342
        y: 256
        width: 87
        height: 48
        visible: true
        color: "#ffffff"
        Text {
            id: logaf1tekst
            x: 26
            y: 16
            text: qsTr("Log af")
            font.pixelSize: 12
            font.bold: true
        }
    }

    Text {
        id: drikndone
        x: 229
        y: 139
        visible: true
        text: qsTr("Drinken er færdig")
        font.pixelSize: 28
        font.bold: true

    }

}
