// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Rectangle {
    id: timeRec
    width: 100
    height: 32

    gradient: Gradient {
        GradientStop { position: 0.0; color: "#0e6600"}
        GradientStop { position: 0.5; color: "#24ff00"}
        GradientStop { position: 1.0; color: "#0e6600"}
    }

    radius: 10
    smooth: true

    Rectangle{
        id: one
        width: parent.width/4-6
        height: parent.height-8

        x: 5
        y: 4

        gradient: Gradient {
            GradientStop { position: 0.0; color: "black"}
            GradientStop { position: 0.5; color: "#7f7f7f"}
            GradientStop { position: 1.0; color: "black"}
        }

        radius: 10
        smooth: true

        Text {
            id: oneTime
            text: qsTr("0")

            font.pixelSize: parent.width-8
            font.bold: true;

            color: "white"

            anchors.horizontalCenter: parent.horizontalCenter;
            anchors.verticalCenter: parent.verticalCenter;
        }

    }
    Rectangle{
        id: two
        width: parent.width/4-6
        height: parent.height-8

        x: one.x + one.width +3
        y: 4

        gradient: Gradient {
            GradientStop { position: 0.0; color: "black"}
            GradientStop { position: 0.5; color: "#7f7f7f"}
            GradientStop { position: 1.0; color: "black"}
        }

        radius: 10
        smooth: true

        Text {
            id: twoTime
            text: qsTr("5")

            font.pixelSize: parent.width-8
            font.bold: true;

            color: "white"

            anchors.horizontalCenter: parent.horizontalCenter;
            anchors.verticalCenter: parent.verticalCenter;
        }
    }

    Rectangle{
        id: three
        width: parent.width/4-6
        height: parent.height-8

        x: two.x + two.width +8
        y: 4

        gradient: Gradient {
            GradientStop { position: 0.0; color: "black"}
            GradientStop { position: 0.5; color: "#7f7f7f"}
            GradientStop { position: 1.0; color: "black"}
        }

        radius: 10
        smooth: true

        Text {
            id: threeTime
            text: qsTr("1")

            font.pixelSize: parent.width-8
            font.bold: true;

            color: "white"

            anchors.horizontalCenter: parent.horizontalCenter;
            anchors.verticalCenter: parent.verticalCenter;
        }
    }

    Rectangle{
        id: four
        width: parent.width/4-6
        height: parent.height-8

        x: three.x + three.width +3
        y: 4

        gradient: Gradient {
            GradientStop { position: 0.0; color: "black"}
            GradientStop { position: 0.5; color: "#7f7f7f"}
            GradientStop { position: 1.0; color: "black"}
        }

        radius: 10
        smooth: true

        Text {
            id: fourTime
            text: qsTr("2")

            font.pixelSize: parent.width-8
            font.bold: true;

            color: "white"

            anchors.horizontalCenter: parent.horizontalCenter;
            anchors.verticalCenter: parent.verticalCenter;
        }
    }

    Text {
        id: textLavelInt
        text: qsTr(":")

        font.pixelSize: fourTime.font.pixelSize;
        font.bold: true;

        color: "black"

        x: timeRec.width/2-4
        y: timeRec.height/2-20
    }
}
