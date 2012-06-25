// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Item{
    id: main
    objectName: "main"

    // Фон
    Rectangle {
        id: background //Имя кнопки

        width: parent.width
        height: parent.height

        color: "#9C9C9C"
    }

    Rectangle {
        id: background_top //Имя кнопки

        width: parent.width
        height: 35

        gradient: Gradient {
            GradientStop { position: 0.0; color: "#363636" }
            GradientStop { position: 1.0; color: "#9C9C9C" }
        }
    }


    Rectangle {
        id: background_down //Имя кнопки

        y: parent.height-30
        width: parent.width
        height: 30

        gradient: Gradient {
            GradientStop { position: 1.0; color: "#363636" }
            GradientStop { position: 0.0; color: "#9C9C9C" }
        }
    }

    MouseArea {
        id: input_move_Mouse
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton
        onPositionChanged: Qt_fun.move_window()
        onReleased: Qt_fun.bl_true()
        onDoubleClicked: Qt_fun.MaxSize()
    }

    Rectangle{
        id: size_input
        height: 60
        width: 60
        rotation: 320

        gradient: Gradient {
            GradientStop { position: 0.0; color: "red" }
            GradientStop { position: 0.5; color: "black" }
        }

        radius: 80

        x: parent.width- 30
        y: parent.height-30

        smooth: true

        MouseArea {
            id: input_size_2_Mouse
            anchors.fill: parent
            onClicked: Qt.LeftButton
            hoverEnabled: true
            onEntered: Qt_fun.cursor_up()
            onExited: Qt_fun.cursor_down()
        }

        MouseArea {
            id: input_size_Mouse
            anchors.fill: parent
            onClicked: Qt.LeftButton
            onPositionChanged: Qt_fun.size_input()
            onReleased: Qt_fun.bl_true_size()
        }
    }

    // Кнопка выключения
    Exit_Qml{}

    // Клавиатура
    Keyboard_Qml{
    }

    // Меню
    Menu_Qml{}

}
