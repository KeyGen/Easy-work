// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

//////////////////////////////////////
////////////////////////////// Клавиша
Rectangle {
    id: button //Имя кнопки

    //Размеры кнопки
    width: parent.width/18
    height: parent.height/8

    x: 6
    y: parent.height/12.8


    //Цвет кнопки
    gradient: Gradient {
        GradientStop { position: 0.0; color: "#451200" }
        GradientStop { position: 0.33; color: "#996666" }
        GradientStop { position: 1.0; color: "#451200" }
    }

    scale: buttonMouse.pressed ? 0.8 : 1.0
    smooth: true
    radius: 5

    MouseArea {
        id: buttonMouse
        anchors.fill: parent
        anchors.margins: -10
        onReleased: console.log("Нажал")
    }
}
