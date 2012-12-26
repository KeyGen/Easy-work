// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Rectangle {
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

        x: 6
        y: 4

        gradient: Gradient {
            GradientStop { position: 0.0; color: "black"}
            GradientStop { position: 0.5; color: "#7f7f7f"}
            GradientStop { position: 1.0; color: "black"}
        }

        radius: 10
        smooth: true

        Text {
            id: oneScore
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

        x: one.x + one.width +4
        y: 4

        gradient: Gradient {
            GradientStop { position: 0.0; color: "black"}
            GradientStop { position: 0.5; color: "#7f7f7f"}
            GradientStop { position: 1.0; color: "black"}
        }

        radius: 10
        smooth: true

        Text {
            id: twoScore
            text: qsTr("1")

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

        x: two.x + two.width +4
        y: 4

        gradient: Gradient {
            GradientStop { position: 0.0; color: "black"}
            GradientStop { position: 0.5; color: "#7f7f7f"}
            GradientStop { position: 1.0; color: "black"}
        }

        radius: 10
        smooth: true

        Text {
            id: threeScore
            text: qsTr("2")

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

        x: three.x + three.width +4
        y: 4

        gradient: Gradient {
            GradientStop { position: 0.0; color: "black"}
            GradientStop { position: 0.5; color: "#7f7f7f"}
            GradientStop { position: 1.0; color: "black"}
        }

        radius: 10
        smooth: true

        Text {
            id: fourScore
            text: qsTr("3")

            font.pixelSize: parent.width-8
            font.bold: true;

            color: "white"

            anchors.horizontalCenter: parent.horizontalCenter;
            anchors.verticalCenter: parent.verticalCenter;
        }
    }
}
