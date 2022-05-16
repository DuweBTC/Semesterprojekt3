import QtQuick 2.0

Item {

    width: 800
    height: 480

    Text {
        id: mixerdrinktekst
        y: 213
        width: 330
        height: 42
        text: qsTr("Mixer drink vent venligst...")
        font.pixelSize: 26
        font.bold: true
        anchors.horizontalCenter: parent.horizontalCenter
    }

}
