// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Rectangle {
    id: window
    width: 600; height: 460;

    x: -200
    y: -100

    gradient: Gradient {
        GradientStop { position: 0.0; color: "black"}
        GradientStop { position: 0.5; color: "#7f7f7f"}
        GradientStop { position: 1.0; color: "black"}
    }

    // Останавливаем прокрутку
    Flickable {
        anchors.fill: parent
        contentHeight: parent.height-1
    }

    Game{}
    StartGame{}
}
