// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Rectangle {
    width: 50
    height: 50

    gradient: Gradient {
        GradientStop { position: 0.0; color: "black"}
        GradientStop { position: 0.5; color: "#7f7f7f"}
        GradientStop { position: 1.0; color: "black"}
    }

    radius: 50
    smooth: true;

    Rectangle {
        width: parent.width-5
        height: parent.height-5

        x: 2.5
        y: 2.5

        color: "blue"

        radius: 50
        smooth: true;
    }
}
