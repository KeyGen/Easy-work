// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Rectangle {
    width: 100
    height: 32

    y: 7
    x: 6

    gradient: Gradient {
        GradientStop { position: 0.0; color: "#0e6600"}
        GradientStop { position: 0.5; color: "#24ff00"}
        GradientStop { position: 1.0; color: "#0e6600"}
    }

    radius: 10
    smooth: true

    Ball{
        id: ballOne
        width: parent.width/4-4
        height: parent.height-4

        x: 2
        y: 2

        Text {
            id: textBallOne
            text: qsTr("a")

            font.pixelSize: ballTwo.width-9
            font.bold: true;

            color: "white"

            anchors.horizontalCenter: parent.horizontalCenter;
            anchors.verticalCenter: parent.verticalCenter;
        }

    }
    Ball{
        id: ballTwo
        width: parent.width/4-4
        height: parent.height-4

        x: ballOne.x + ballOne.width +4
        y: 2

        Text {
            id: textBallTwo
            text: qsTr("b")

            font.pixelSize: ballTwo.width-9
            font.bold: true;

            color: "white"

            anchors.horizontalCenter: parent.horizontalCenter;
            anchors.verticalCenter: parent.verticalCenter;
        }
    }

    Ball{
        id: ballThree
        width: parent.width/4-4
        height: parent.height-4

        x: ballTwo.x + ballTwo.width +4
        y: 2

        Text {
            id: textBallThree
            text: qsTr("c")

            font.pixelSize: ballTwo.width-9
            font.bold: true;

            color: "white"

            anchors.horizontalCenter: parent.horizontalCenter;
            anchors.verticalCenter: parent.verticalCenter;
        }
    }

    Ball{
        id: ballFour
        width: parent.width/4-4
        height: parent.height-4

        x: ballThree.x + ballThree.width +4
        y: 2

        Text {
            id: textBallFour
            text: qsTr("d")

            font.pixelSize: ballTwo.width-9
            font.bold: true;

            color: "white"

            anchors.horizontalCenter: parent.horizontalCenter;
            anchors.verticalCenter: parent.verticalCenter;
        }
    }
}
