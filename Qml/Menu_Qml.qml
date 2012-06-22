// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

//////////////////////////////////////
//////////////////// Кнопка выключения
Image {
    id: menu //Имя кнопки
    source: ":/picture/menu"

    width: 30
    height: 30

    x: parent.width - 33
    y: 45

    scale: quitMouse.pressed ? 0.8 : 1.0
    smooth: true

    MouseArea {
        id: quitMouse
        anchors.fill: parent
        anchors.margins: -10
        acceptedButtons: Qt.LeftButton | Qt.RightButton
        onClicked: Qt_fun.menu_up()
    }
}
