import QtQuick 2.0

Item {
    id: item1
    width: 800
    height: 480





    Rectangle {
        id: tilfoejsaldo
        x: 203
        y: 256
        width: 87
        height: 48
        visible: true
        color: "#ffffff"

        Text {
            id: tilfoejsaldotekst
            x: 13
            y: 16
            text: qsTr("Tilføj saldo")
            font.pixelSize: 12
            font.bold: true
        }
    }

    Rectangle {
        id: logaf
        x: 342
        y: 256
        width: 87
        height: 48
        visible: true
        color: "#ffffff"
        Text {
            id: logaftekst
            x: 26
            y: 16
            text: qsTr("Log af")
            font.pixelSize: 12
            font.bold: true
        }
    }

    Text {
        id: saldoforlav
        x: 229
        y: 139
        visible: true
        text: qsTr("Saldo for lav")
        font.pixelSize: 28
        font.bold: true

    }

}
