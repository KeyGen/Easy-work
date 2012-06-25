import QtQuick 1.0 // to target S60 5th Edition or Maemo 5

//////////////////////////////////////
////////////////////////////// Клавиша

Rectangle {
    id: button //Имя кнопки

    //Размеры кнопки
    width: parent.width/18
    height: parent.height/8

    radius: 10

    x: 6

    Gradient {
        id: gr_1
        GradientStop { position: 0.0; color: "#45161c" }
        GradientStop { position: 0.5; color: "#996666" }
        GradientStop { position: 1.0; color: "#45161c" }
    }

    Gradient {
        id: gr_2
        GradientStop { position: 0.0; color: "#996666" }
        GradientStop { position: 0.5; color: "#45161c" }
        GradientStop { position: 1.0; color: "#996666" }
    }

    // невидимка
    //opacity: 0.5

    state: "normal"

            states: [
                State {
                    name: "normal"
                    PropertyChanges {
                        target: button
                        color: "green"
                        border.width: 3
                        border.color: "#45161c"
                        gradient: gr_1
                    }
                },
                State {
                    name: "shift"
                    PropertyChanges {
                        target: button
                        color: "green"
                        border.width: 3
                        border.color: "#0000CD"
                        gradient: gr_2
                    }
                }
            ]

    smooth: true

    // Разрешаем доступ buttonLabel
    property alias buttonLabel: buttonLabel.text
    property alias buttonState: buttonLabel.state
    ///////////////////
     Text {
        id: buttonLabel
        font.bold : true

        color: "white"
        anchors.centerIn: parent;

        state: "normal_text"

                states: [
                    State {
                        name: "normal_text"
                        PropertyChanges {
                            target: buttonLabel
                            font.pixelSize : 13
                        }
                    },
                    State {
                        name: "input_text"
                        PropertyChanges {
                            target: buttonLabel
                            font.pixelSize : parent.height/3
                        }
                    }
                ]
    }

    MouseArea {
        id: input_size_2_Mouse
        anchors.fill: parent
        onClicked: Qt.LeftButton
        hoverEnabled: true
        onCanceled: button.state = 'shift'
        onPositionChanged: button.state = 'shift'
        onExited: button.state = 'normal'
    }

    MouseArea {
        id: buttonMouse
        anchors.fill: parent
        anchors.margins: 10

        onEntered:
        {
            button.scale = 0.8
            console.log(buttonLabel.text + " clicked")
        }

        onReleased:
        {
            button.scale = 1.0
        }


//        focus: true

//        Keys.onPressed: {
//            if (event.key == Qt.Key_Space) {
//                button.state = "shift";
//                button.scale = 0.8
//                console.log(button.buttonLabel.toLocaleString() + " clicked" )
//            }
//        }


    }
}
