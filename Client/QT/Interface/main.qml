import QtQuick 2.15
import QtQuick.Window 2.15


Window {
    width: 800
    height: 480
    visible: true
    title: qsTr("Interface ADM")

    Baggrund_Interface {
        id: baggrund_Interface
        anchors.fill: parent
        visible: true

        }


       MainScreen {
            id: mainScreen
            anchors.fill: parent
            visible: false



        }


       Studiekort {
           id: studiekort
           x: 300
           y: 110
           width: 209
           height: 194
           visible: false




       }

       Add_Funds{
           visible: true
       }

       DispensererDrink{
           visible: false
       }

       INSUFFICIENT_FUNDS{
           visible: false
       }

       DrinkDone{
           visible: false
       }
}




