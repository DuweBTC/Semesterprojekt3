import QtQuick 2.0

Item {
    width: 800
    height: 480

    Baggrund_Interface {
        id: baggrund_Interface
        anchors.fill: parent
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0

        Text {
            id: maintekst
            x: 317
            y: 44
            text: qsTr("Drinks katalog")
            font.pixelSize: 24
            font.bold: true
            font.family: "Times New Roman"
        }

        Rectangle {
            id: kontoinfoboks
            x: 50
            y: 169
            width: 98
            height: 34
            color: "#ffffff"

            Text {
                id: kontoinfotekst
                x: 19
                y: 10
                text: qsTr("Konto info")
                font.pixelSize: 12
                font.bold: true
            }
        }

        Rectangle {
            id: drinkkatalogboks
            x: 50
            y: 233
            width: 98
            height: 34
            color: "#ffffff"
            Text {
                id: drinkkatalogtekst
                x: 8
                y: 10
                width: 71
                height: 16
                text: qsTr("Drink katalog")
                font.pixelSize: 12
                font.bold: true
            }
        }

        Rectangle {
            id: tilfoejsaldoboks
            x: 50
            y: 292
            width: 98
            height: 34
            color: "#ffffff"
            Text {
                id: tilfoejsaldotekst
                x: 8
                y: 10
                width: 71
                height: 16
                text: qsTr("Tilføj saldo")
                anchors.bottom: parent.bottom
                font.pixelSize: 12
                anchors.bottomMargin: 8
                font.bold: true
            }
        }

        Rectangle {
            id: tilfoejdrinkboks
            x: 50
            y: 349
            width: 98
            height: 34
            color: "#ffffff"
            Text {
                id: tilfoejdrinktekst
                x: 8
                y: 10
                width: 71
                height: 16
                text: qsTr("Tilføj drink")
                anchors.bottom: parent.bottom
                font.pixelSize: 12
                anchors.bottomMargin: 8
                font.bold: true
            }
        }

        Rectangle {
            id: favoritboks
            x: 50
            y: 404
            width: 98
            height: 34
            color: "#ffffff"
            Text {
                id: favoritdrink
                x: 8
                y: 10
                width: 71
                height: 16
                text: qsTr("Favorit drinks")
                anchors.bottom: parent.bottom
                font.pixelSize: 12
                anchors.bottomMargin: 8
                font.bold: true
            }
        }

        Rectangle {
            id: drinkboks1
            x: 213
            y: 127
            width: 175
            height: 147
            color: "#ffffff"

            Text {
                id: drink1tekst
                x: 59
                y: 15
                text: qsTr("Cocktail: 20 kr")
                font.pixelSize: 12
                font.bold: true
            }

            Image {
                id: drink1
                x: 39
                y: 37
                width: 100
                height: 100
                source: "/billeder/cocktail.jfif"
                fillMode: Image.PreserveAspectFit
            }
        }

        Rectangle {
            id: drinkboks2
            x: 409
            y: 127
            width: 175
            height: 147
            color: "#ffffff"
            Text {
                id: drink2tekst
                x: 38
                y: 17
                text: qsTr("Gin & Tonic: 59 kr")
                font.pixelSize: 12
                font.bold: true
            }

            Image {
                id: drink2
                x: 38
                y: 39
                width: 100
                height: 100
                source: "/billeder/gintonic.jfif"
                fillMode: Image.PreserveAspectFit
            }
        }

        Rectangle {
            id: drinkboks3
            x: 213
            y: 299
            width: 175
            height: 147
            color: "#ffffff"
            Text {
                id: drink3tekst
                x: 35
                y: 15
                text: qsTr("Rom og cola: 30 kr")
                font.pixelSize: 12
                font.bold: true
            }

            Image {
                id: drink3
                x: 39
                y: 37
                width: 100
                height: 100
                source: "/billeder/romcola.jpg"
                fillMode: Image.PreserveAspectFit
            }
        }

        Rectangle {
            id: drinkboks4
            x: 409
            y: 299
            width: 175
            height: 147
            color: "#ffffff"
            Text {
                id: drink1tekst3
                x: 59
                y: 15
                text: qsTr("Cocktail: 20 kr")
                font.pixelSize: 12
                font.bold: true
            }

            Image {
                id: drink4
                x: 39
                y: 37
                width: 100
                height: 100
                source: "/billeder/gintonic.jfif"
                fillMode: Image.PreserveAspectFit
            }
        }
    }

}



/*##^##
Designer {
    D{i:0;formeditorZoom:0.33}
}
##^##*/
