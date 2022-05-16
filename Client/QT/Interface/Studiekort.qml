import QtQuick 2.0
Item {
    width: 300
    height: 250
    property alias buttonColor: button.color
    property alias displayText: display.text
    Rectangle {
        id: button
        color: "#181616"
        radius: width* 0.5
        anchors.fill: parent
        anchors.bottomMargin: 56
        anchors.leftMargin: 8
        anchors.topMargin: 69
        anchors.rightMargin: 8

        Text {
            id: display
            color: "#f8f4f4"
            text: qsTr("Scan din studiekort")
            anchors.verticalCenter: parent.verticalCenter
            font.pixelSize: 20
            anchors.horizontalCenter: parent.horizontalCenter
            font.family: "Times New Roman"
            font.bold: true
        }
    }
    MouseArea{
        anchors.fill: parent
        anchors.leftMargin: 0
        anchors.topMargin: 0
        anchors.rightMargin: -47
        anchors.bottomMargin: -43

        //onClicked: {



        //}

        onPressed: parent.buttonColor = "black"


        onReleased: parent.buttonColor ="blue"
    }

}





