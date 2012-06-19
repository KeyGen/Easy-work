// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Image {
    id: input_move //Имя кнопки
    source: ":/picture/active_move"

    scale: input_move_Mouse.pressed ? 0.8 : 1.0
    smooth: true

    x: parent.width - 50
    y: 5

    MouseArea {
        id: input_move_Mouse
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton
        onPositionChanged: Qt_fun.move_window()
    }
}
