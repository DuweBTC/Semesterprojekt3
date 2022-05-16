import QtQuick 2.0

Item {
    width: 800
    height: 480
    property alias displaytekstText: displaytekst.text

    Text {
        id: addfunds
        x: 244
        y: 157
        text: qsTr("Hvor meget vil du tilføje")
        font.pixelSize: 22
        font.bold: true
    }

    Rectangle {
        id: minus10
        x: 203
        y: 256
        width: 46
        height: 48
        color: "#aa0000"

        Text {
            id: minus10tekst
            x: 13
            y: 16
            text: qsTr("-10")
            font.pixelSize: 12
            font.bold: true
        }

    }

    Rectangle {
        id: minus1
        x: 273
        y: 256
        width: 46
        height: 48
        color: "#aa0000"

        Text {
            id: minus1tekst
            x: 13
            y: 16
            text: qsTr("-1")
            font.pixelSize: 12
            font.bold: true
        }
    }

    Rectangle {
        id: displaytilfoej
        function receive(value)
        {
            displaytekstText = value
            clicknotify.running = true
        }



        x: 339
        y: 256
        width: 92
        height: 48
        color: "#ffffff"

        Text {
            id: displaytekst
            x: 36
            y: 16
            text: qsTr("00 Kr.")
            font.pixelSize: 12
            font.bold: true
        }
    }

    Rectangle {
        id: plus1
        property int counter: 0
        property Add_Funds target: null

        signal send(string value)
        onTargetChanged: send.connect(target.receive)

        MouseArea{
            anchors.fill: parent

            onClicked: {
                counter++
                parent.send(counter)
            }
         }

        x: 451
        y: 256
        width: 46
        height: 48
        //target: displaytilfoej
        color: "#00aa00"

        Text {
            id: plus10tekst
            x: 13
            y: 16
            text: qsTr("+10")
            font.pixelSize: 12
            font.bold: true
        }
    }

    Rectangle {
        id: plus10
        x: 517
        y: 256
        width: 46
        height: 48
        color: "#00aa00"

        Text {
            id: plus1tekst
            x: 13
            y: 16
            text: qsTr("+1")
            font.pixelSize: 12
            font.bold: true
        }
    }

    Rectangle {
        id: godkend
        x: 192
        y: 348
        width: 92
        height: 48
        color: "#aaff00"
        Text {
            id: godkendtekst
            x: 21
            y: 16
            text: qsTr("Godkend")
            font.pixelSize: 12
            font.bold: true
        }
    }

    Rectangle {
        id: afbryd
        x: 460
        y: 348
        width: 92
        height: 48
        color: "#ff0000"
        Text {
            id: afbrydtekst
            x: 21
            y: 16
            text: qsTr("Afbryd")
            font.pixelSize: 12
            font.bold: true
        }
    }

}
