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
        width: parent.width/4*3-9
        height: parent.height-8

        gradient: Gradient {
            GradientStop { position: 0.0; color: "black"}
            GradientStop { position: 0.5; color: "#7f7f7f"}
            GradientStop { position: 1.0; color: "black"}
        }

        radius: 10
        smooth: true

        Text {
            id: textLavel
            text: qsTr("Lavel")

            font.pixelSize: textLavelInt.font.pixelSize
            font.bold: true;

            color: "white"

            anchors.horizontalCenter: parent.horizontalCenter;
            anchors.verticalCenter: parent.verticalCenter;
        }

        x: 6
        y: 4

    }

    Rectangle{
        id: two
        width: parent.width/4-6
        height: parent.height-8

        radius: 10
        smooth: true

        Text {
            id: textLavelInt
            text: qsTr("1")

            font.pixelSize: parent.width-8
            font.bold: true;

            color: "white"

            anchors.horizontalCenter: parent.horizontalCenter;
            anchors.verticalCenter: parent.verticalCenter;
        }

        gradient: Gradient {
            GradientStop { position: 0.0; color: "black"}
            GradientStop { position: 0.5; color: "#7f7f7f"}
            GradientStop { position: 1.0; color: "black"}
        }

        x: one.x + one.width +4
        y: 4
    }
}
