// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

//////////////////////////////////////
//////////////////// Main для Qml
Item {
    id: main
    width: 1050
    height: 455

//    // Фон
//    Image {
//        id: background //Имя кнопки
//        source: ":/picture/background"

//        width: parent.width
//        height: parent.height
//    }

    // Кнопка выключения
    Exit_Qml{
        width: parent.width/52.4
        height: parent.height/22.7
    }

    //////////////////////////////////////
    ////////////// Клавиши ///////////////
    Button_Qml{
        id: button_1
        x: parent.width/37
        y: parent.height/12.8
        width: 104
        height: 57
        //Текст кнопки
        Text {
            id: buttonLabel_1
            font.bold : true
            text: "Esc"
            scale: 0.100
            color: "black"
            anchors.centerIn: parent;
        }
    }

    Button_Qml{
        id: button_2
        opacity: 0.640
        transformOrigin: Item.TopLeft
        anchors.fill: parent
        //Текст кнопки
        Text {
            id: buttonLabel_2
            font.bold : true
            text: "F1"
            color: "black"
            anchors.centerIn: parent;
        }
    }
    Button_Qml{
        id: button_3
        x: button_2.x + button_3.width + parent.width/261.7
        //Текст кнопки
        Text {
            id: buttonLabel_3
            font.bold : true
            text: "F2"
            color: "black"
            anchors.centerIn: parent;
        }
    }

    Button_Qml{
        id: button_4
        x: button_3.x + button_4.width + parent.width/261.7
        //Текст кнопки
        Text {
            id: buttonLabel_4
            font.bold : true
            text: "F3"
            color: "black"
            anchors.centerIn: parent;
        }
    }

    Button_Qml{
        id: button_5
        x: button_4.x + button_5.width + parent.width/261.7
        opacity: 0.850
        visible: true
        //Текст кнопки
        Text {
            id: buttonLabel_5
            font.bold : true
            text: "F4"
            color: "black"
            anchors.centerIn: parent;
        }
    }

    Button_Qml{
        id: button_6
        x: button_5.x + button_2.width*2 + (parent.width/261.7)*2
        //Текст кнопки
        Text {
            id: buttonLabel_6
            font.bold : true
            text: "F5"
            color: "black"
            anchors.centerIn: parent;
        }
    }
    Button_Qml{
        id: button_7
        x: button_6.x + button_7.width + parent.width/261.7
        //Текст кнопки
        Text {
            id: buttonLabel_7
            font.bold : true
            text: "F6"
            color: "black"
            anchors.centerIn: parent;
        }
    }

    Button_Qml{
        id: button_8
        x: button_7.x + button_8.width + parent.width/261.7
        //Текст кнопки
        Text {
            id: buttonLabel_8
            font.bold : true
            text: "F7"
            color: "black"
            anchors.centerIn: parent;
        }
    }

    Button_Qml{
        id: button_9
        x: button_8.x + button_9.width + parent.width/261.7
        //Текст кнопки
        Text {
            id: buttonLabel_9
            font.bold : true
            text: "F8"
            color: "black"
            anchors.centerIn: parent;
        }
    }

    Button_Qml{
        id: button_10
        x: button_9.x + button_10.width*2 + (parent.width/261.7)*2
        //Текст кнопки
        Text {
            id: buttonLabel_10
            font.bold : true
            text: "F9"
            color: "black"
            anchors.centerIn: parent;
        }
    }
    Button_Qml{
        id: button_11
        x: button_10.x + button_11.width + parent.width/261.7
        //Текст кнопки
        Text {
            id: buttonLabel_11
            font.bold : true
            text: "F10"
            color: "black"
            anchors.centerIn: parent;
        }
    }

    Button_Qml{
        id: button_12
        x: button_11.x + button_12.width + parent.width/261.7
        //Текст кнопки
        Text {
            id: buttonLabel_12
            font.bold : true
            text: "F11"
            color: "black"
            anchors.centerIn: parent;
        }
    }

    Button_Qml{
        id: button_13
        x: button_12.x + button_13.width + parent.width/261.7
        //Текст кнопки
        Text {
            id: buttonLabel_13
            font.bold : true
            text: "F12"
            color: "black"
            anchors.centerIn: parent;
        }
    }
    //////////////////////////////////////
    ////////////// второй ////////////////

    Button_Qml{
        id: button_14
        x: parent.width/37
        y: button_1.y + button_14.height + button_14.height/2.3
        //Текст кнопки
        Text {
            id: buttonLabel_14
            font.bold : true
            text: "~\n`"
            color: "black"
            anchors.centerIn: parent;
        }
    }

    Button_Qml{
        id: button_15
        x: button_14.x + button_15.width + parent.width/261.7
        y: button_1.y + button_15.height + button_15.height/2.3
        //Текст кнопки
        Text {
            id: buttonLabel_15
            font.bold : true
            text: "1"
            color: "black"
            anchors.centerIn: parent;
        }
    }

    Button_Qml{
        id: button_16
        x: button_15.x + button_16.width + parent.width/261.7
        y: button_1.y + button_15.height + button_15.height/2.3
        //Текст кнопки
        Text {
            id: buttonLabel_16
            font.bold : true
            text: "2"
            color: "black"
            anchors.centerIn: parent;
        }
    }

    Button_Qml{
        id: button_17
        x: button_16.x + button_17.width + parent.width/261.7
        y: button_1.y + button_15.height + button_15.height/2.3
        //Текст кнопки
        Text {
            id: buttonLabel_17
            font.bold : true
            text: "3"
            color: "black"
            anchors.centerIn: parent;
        }
    }

    Button_Qml{
        id: button_18
        x: button_17.x + button_18.width + parent.width/261.7
        y: button_1.y + button_15.height + button_15.height/2.3
        //Текст кнопки
        Text {
            id: buttonLabel_18
            font.bold : true
            text: "4"
            color: "black"
            anchors.centerIn: parent;
        }
    }

    Button_Qml{
        id: button_19
        x: button_18.x + button_19.width + parent.width/261.7
        y: button_1.y + button_15.height + button_15.height/2.3
        //Текст кнопки
        Text {
            id: buttonLabel_19
            font.bold : true
            text: "5"
            color: "black"
            anchors.centerIn: parent;
        }
    }

    Button_Qml{
        id: button_20
        x: button_19.x + button_20.width + parent.width/261.7
        y: button_1.y + button_15.height + button_15.height/2.3
        //Текст кнопки
        Text {
            id: buttonLabel_20
            font.bold : true
            text: "6"
            color: "black"
            anchors.centerIn: parent;
        }
    }

    Button_Qml{
        id: button_21
        x: button_20.x + button_21.width + parent.width/261.7
        y: button_1.y + button_15.height + button_15.height/2.3
        //Текст кнопки
        Text {
            id: buttonLabel_21
            font.bold : true
            text: "7"
            color: "black"
            anchors.centerIn: parent;
        }
    }

    Button_Qml{
        id: button_22
        x: button_21.x + button_22.width + parent.width/261.7
        y: button_1.y + button_15.height + button_15.height/2.3
        //Текст кнопки
        Text {
            id: buttonLabel_22
            font.bold : true
            text: "8"
            color: "black"
            anchors.centerIn: parent;
        }
    }

    Button_Qml{
        id: button_23
        x: button_22.x + button_23.width + parent.width/261.7
        y: button_1.y + button_15.height + button_15.height/2.3
        //Текст кнопки
        Text {
            id: buttonLabel_23
            font.bold : true
            text: "9"
            color: "black"
            anchors.centerIn: parent;
        }
    }

    Button_Qml{
        id: button_24
        x: button_23.x + button_24.width + parent.width/261.7
        y: button_1.y + button_15.height + button_15.height/2.3
        //Текст кнопки
        Text {
            id: buttonLabel_24
            font.bold : true
            text: "0"
            color: "black"
            anchors.centerIn: parent;
        }
    }

    Button_Qml{
        id: button_25
        x: button_24.x + button_25.width + parent.width/261.7
        y: button_1.y + button_15.height + button_15.height/2.3
        //Текст кнопки
        Text {
            id: buttonLabel_25
            font.bold : true
            text: "-"
            color: "black"
            anchors.centerIn: parent;
        }
    }

    Button_Qml{
        id: button_26
        x: button_25.x + button_26.width + parent.width/261.7
        y: button_1.y + button_15.height + button_15.height/2.3
        //Текст кнопки
        Text {
            id: buttonLabel_26
            font.bold : true
            text: "="
            color: "black"
            anchors.centerIn: parent;
        }
    }

    Button_Qml{
        id: button_27
        x: button_26.x + button_26.width + parent.width/261.7
        y: button_1.y + button_15.height + button_15.height/2.3
        width: parent.width/5.72
        //Текст кнопки
        Text {
            id: buttonLabel_27
            font.bold : true
            text: "backspase"
            color: "black"
            anchors.centerIn: parent;
        }
    }

    //////////////////////////////////////
    ////////////// третий ////////////////

    Button_Qml{
        id: button_28
        x: parent.width/37
        y: button_27.y + button_28.height + parent.width/261.7
        width: button_27.width
        //Текст кнопки
        Text {
            id: buttonLabel_28
            font.bold : true
            text: "Tab"
            color: "black"
            anchors.centerIn: parent;
        }
    }

    Button_Qml{
        id: button_29
        x: button_28.x + button_28.width + parent.width/261.7
        y: button_27.y + button_28.height + parent.width/261.7
        //Текст кнопки
        Text {
            id: buttonLabel_29
            font.bold : true
            text: "Q"
            color: "black"
            anchors.centerIn: parent;
        }
    }

    Button_Qml{
        id: button_30
        x: button_29.x + button_29.width + parent.width/261.7
        y: button_27.y + button_28.height + parent.width/261.7
        //Текст кнопки
        Text {
            id: buttonLabel_30
            font.bold : true
            text: "W"
            color: "black"
            anchors.centerIn: parent;
        }
    }

    Button_Qml{
        id: button_31
        x: button_30.x + button_30.width + parent.width/261.7
        y: button_27.y + button_28.height + parent.width/261.7
        //Текст кнопки
        Text {
            id: buttonLabel_31
            font.bold : true
            text: "E"
            color: "black"
            anchors.centerIn: parent;
        }
    }

    Button_Qml{
        id: button_32
        x: button_31.x + button_31.width + parent.width/261.7
        y: button_27.y + button_28.height + parent.width/261.7
        //Текст кнопки
        Text {
            id: buttonLabel_32
            font.bold : true
            text: "R"
            color: "black"
            anchors.centerIn: parent;
        }
    }

    Button_Qml{
        id: button_33
        x: button_32.x + button_32.width + parent.width/261.7
        y: button_27.y + button_28.height + parent.width/261.7
        //Текст кнопки
        Text {
            id: buttonLabel_33
            font.bold : true
            text: "T"
            color: "black"
            anchors.centerIn: parent;
        }
    }

    Button_Qml{
        id: button_34
        x: button_33.x + button_33.width + parent.width/261.7
        y: button_27.y + button_28.height + parent.width/261.7
        //Текст кнопки
        Text {
            id: buttonLabel_34
            font.bold : true
            text: "Y"
            color: "black"
            anchors.centerIn: parent;
        }
    }

    Button_Qml{
        id: button_35
        x: button_34.x + button_34.width + parent.width/261.7
        y: button_27.y + button_28.height + parent.width/261.7
        //Текст кнопки
        Text {
            id: buttonLabel_35
            font.bold : true
            text: "U"
            color: "black"
            anchors.centerIn: parent;
        }
    }

    Button_Qml{
        id: button_36
        x: button_35.x + button_35.width + parent.width/261.7
        y: button_27.y + button_28.height + parent.width/261.7
        //Текст кнопки
        Text {
            id: buttonLabel_36
            font.bold : true
            text: "I"
            color: "black"
            anchors.centerIn: parent;
        }
    }

    Button_Qml{
        id: button_37
        x: button_36.x + button_36.width + parent.width/261.7
        y: button_27.y + button_28.height + parent.width/261.7
        //Текст кнопки
        Text {
            id: buttonLabel_37
            font.bold : true
            text: "O"
            color: "black"
            anchors.centerIn: parent;
        }
    }

    Button_Qml{
        id: button_38
        x: button_37.x + button_37.width + parent.width/261.7
        y: button_27.y + button_28.height + parent.width/261.7
        //Текст кнопки
        Text {
            id: buttonLabel_38
            font.bold : true
            text: "P"
            color: "black"
            anchors.centerIn: parent;
        }
    }

    Button_Qml{
        id: button_39
        x: button_38.x + button_38.width + parent.width/261.7
        y: button_27.y + button_28.height + parent.width/261.7
        //Текст кнопки
        Text {
            id: buttonLabel_39
            font.bold : true
            text: "{"
            color: "black"
            anchors.centerIn: parent;
        }
    }

    Button_Qml{
        id: button_40
        x: button_39.x + button_39.width + parent.width/261.7
        y: button_27.y + button_28.height + parent.width/261.7
        //Текст кнопки
        Text {
            id: buttonLabel_40
            font.bold : true
            text: "}"
            color: "black"
            anchors.centerIn: parent;
        }
    }

    Button_Qml{
        id: button_41
        x: button_40.x + button_40.width + parent.width/261.7
        y: button_27.y + button_28.height + parent.width/261.7
        //Текст кнопки
        Text {
            id: buttonLabel_41
            font.bold : true
            text: "|"
            color: "black"
            anchors.centerIn: parent;
        }
    }

    //////////////////////////////////////
    ///////////// четвертый //////////////

    Button_Qml{
        id: button_42
        x: parent.width/37
        y: button_41.y + button_15.height + parent.width/261.7
        width: button_40.width*2.072
        //Текст кнопки
        Text {
            id: buttonLabel_42
            font.bold : true
            text: "Caps Lock"
            color: "black"
            anchors.centerIn: parent;
        }
    }

    Button_Qml{
        id: button_43
        x: button_42.x + button_42.width + parent.width/261.7
        y: button_41.y + button_43.height + parent.width/261.7
        //Текст кнопки
        Text {
            id: buttonLabel_43
            font.bold : true
            text: "A"
            color: "black"
            anchors.centerIn: parent;
        }
    }

    Button_Qml{
        id: button_44
        x: button_43.x + button_43.width + parent.width/261.7
        y: button_41.y + button_43.height + parent.width/261.7
        //Текст кнопки
        Text {
            id: buttonLabel_44
            font.bold : true
            text: "S"
            color: "black"
            anchors.centerIn: parent;
        }
    }

    Button_Qml{
        id: button_45
        x: button_44.x + button_44.width + parent.width/261.7
        y: button_41.y + button_43.height + parent.width/261.7
        //Текст кнопки
        Text {
            id: buttonLabel_45
            font.bold : true
            text: "D"
            color: "black"
            anchors.centerIn: parent;
        }
    }

    Button_Qml{
        id: button_46
        x: button_45.x + button_45.width + parent.width/261.7
        y: button_41.y + button_43.height + parent.width/261.7
        //Текст кнопки
        Text {
            id: buttonLabel_46
            font.bold : true
            text: "F"
            color: "black"
            anchors.centerIn: parent;
        }
    }

    Button_Qml{
        id: button_47
        x: button_46.x + button_46.width + parent.width/261.7
        y: button_41.y + button_43.height + parent.width/261.7
        //Текст кнопки
        Text {
            id: buttonLabel_47
            font.bold : true
            text: "G"
            color: "black"
            anchors.centerIn: parent;
        }
    }

    Button_Qml{
        id: button_48
        x: button_47.x + button_47.width + parent.width/261.7
        y: button_41.y + button_43.height + parent.width/261.7
        //Текст кнопки
        Text {
            id: buttonLabel_48
            font.bold : true
            text: "H"
            color: "black"
            anchors.centerIn: parent;
        }
    }

    Button_Qml{
        id: button_49
        x: button_48.x + button_48.width + parent.width/261.7
        y: button_41.y + button_43.height + parent.width/261.7
        //Текст кнопки
        Text {
            id: buttonLabel_49
            font.bold : true
            text: "J"
            color: "black"
            anchors.centerIn: parent;
        }
    }

    Button_Qml{
        id: button_50
        x: button_49.x + button_49.width + parent.width/261.7
        y: button_41.y + button_43.height + parent.width/261.7
        //Текст кнопки
        Text {
            id: buttonLabel_50
            font.bold : true
            text: "K"
            color: "black"
            anchors.centerIn: parent;
        }
    }

    Button_Qml{
        id: button_51
        x: button_50.x + button_50.width + parent.width/261.7
        y: button_41.y + button_43.height + parent.width/261.7
        //Текст кнопки
        Text {
            id: buttonLabel_51
            font.bold : true
            text: "L"
            color: "black"
            anchors.centerIn: parent;
        }
    }

    Button_Qml{
        id: button_52
        x: button_51.x + button_51.width + parent.width/261.7
        y: button_41.y + button_43.height + parent.width/261.7
        //Текст кнопки
        Text {
            id: buttonLabel_52
            font.bold : true
            text: ":"
            color: "black"
            anchors.centerIn: parent;
        }
    }

    Button_Qml{
        id: button_53
        x: button_52.x + button_52.width + parent.width/261.7
        y: button_41.y + button_43.height + parent.width/261.7
        //Текст кнопки
        Text {
            id: buttonLabel_53
            font.bold : true
            text: "\""
            color: "black"
            anchors.centerIn: parent;
        }
    }

    Button_Qml{
        id: button_55
        x: button_53.x + button_53.width + parent.width/261.7
        y: button_41.y + button_43.height + parent.width/261.7
        width: parent.width/5.72
        //Текст кнопки
        Text {
            id: buttonLabel_55
            font.bold : true
            text: "<-- Enter"
            color: "black"
            anchors.centerIn: parent;
        }
    }

    //////////////////////////////////////
    /////////////// пятый ////////////////

    Button_Qml{
        id: button_56
        x: parent.width/37
        y: button_55.y + button_55.height + parent.width/261.7
        width: button_53.width*2.615
        //Текст кнопки
        Text {
            id: buttonLabel_56
            font.bold : true
            text: "Shift"
            color: "black"
            anchors.centerIn: parent;
        }
    }

    Button_Qml{
        id: button_57
        x: button_56.x + button_56.width + parent.width/261.7
        y: button_56.y
        //Текст кнопки
        Text {
            id: buttonLabel_57
            font.bold : true
            text: "\\"
            color: "black"
            anchors.centerIn: parent;
        }
    }

    Button_Qml{
        id: button_58
        x: button_57.x + button_57.width + parent.width/261.7
        y: button_57.y
        //Текст кнопки
        Text {
            id: buttonLabel_58
            font.bold : true
            text: "Z"
            color: "black"
            anchors.centerIn: parent;
        }
    }

    Button_Qml{
        id: button_59
        x: button_58.x + button_58.width + parent.width/261.7
        y: button_56.y
        //Текст кнопки
        Text {
            id: buttonLabel_59
            font.bold : true
            text: "X"
            color: "black"
            anchors.centerIn: parent;
        }
    }

    Button_Qml{
        id: button_60
        x: button_59.x + button_59.width + parent.width/261.7
        y: button_56.y
        //Текст кнопки
        Text {
            id: buttonLabel_60
            font.bold : true
            text: "C"
            color: "black"
            anchors.centerIn: parent;
        }
    }

    Button_Qml{
        id: button_61
        x: button_60.x + button_60.width + parent.width/261.7
        y: button_56.y
        //Текст кнопки
        Text {
            id: buttonLabel_61
            font.bold : true
            text: "V"
            color: "black"
            anchors.centerIn: parent;
        }
    }

    Button_Qml{
        id: button_62
        x: button_61.x + button_61.width + parent.width/261.7
        y: button_56.y
        //Текст кнопки
        Text {
            id: buttonLabel_62
            font.bold : true
            text: "B"
            color: "black"
            anchors.centerIn: parent;
        }
    }

    Button_Qml{
        id: button_63
        x: button_62.x + button_62.width + parent.width/261.7
        y: button_56.y
        //Текст кнопки
        Text {
            id: buttonLabel_63
            font.bold : true
            text: "N"
            color: "black"
            anchors.centerIn: parent;
        }
    }

    Button_Qml{
        id: button_64
        x: button_63.x + button_63.width + parent.width/261.7
        y: button_56.y
        //Текст кнопки
        Text {
            id: buttonLabel_64
            font.bold : true
            text: "M"
            color: "black"
            anchors.centerIn: parent;
        }
    }

    Button_Qml{
        id: button_65
        x: button_64.x + button_64.width + parent.width/261.7
        y: button_56.y
        //Текст кнопки
        Text {
            id: buttonLabel_65
            font.bold : true
            text: "<"
            color: "black"
            anchors.centerIn: parent;
        }
    }

    Button_Qml{
        id: button_66
        x: button_65.x + button_65.width + parent.width/261.7
        y: button_56.y
        //Текст кнопки
        Text {
            id: buttonLabel_66
            font.bold : true
            text: ">"
            color: "black"
            anchors.centerIn: parent;
        }
    }

    Button_Qml{
        id: button_67
        x: button_66.x + button_66.width + parent.width/261.7
        y: button_56.y
        //Текст кнопки
        Text {
            id: buttonLabel_67
            font.bold : true
            text: "?"
            color: "black"
            anchors.centerIn: parent;
        }
    }

    Button_Qml{
        id: button_68
        x: button_67.x + button_67.width + parent.width/261.7
        y: button_56.y
        width: button_53.width*2.615
        //Текст кнопки
        Text {
            id: buttonLabel_68
            font.bold : true
            text: "Shift"
            color: "black"
            anchors.centerIn: parent;
        }
    }

    //////////////////////////////////////
    /////////////// шестой ///////////////

    Button_Qml{
        id: button_69
        x: parent.width/37
        y: button_68.y + button_18.height + parent.width/261.7
        width: button_26.width*1.5
        //Текст кнопки
        Text {
            id: buttonLabel_69
            font.bold : true
            text: "Ctrl"
            color: "black"
            anchors.centerIn: parent;
        }
    }

    Button_Qml{
        id: button_70
        x: button_69.x + button_69.width + parent.width/261.7
        y: button_69.y
        width: button_26.width*1.5
        //Текст кнопки
        Text {
            id: buttonLabel_70
            font.bold : true
            text: "Super L"
            color: "black"
            anchors.centerIn: parent;
        }
    }

    Button_Qml{
        id: button_71
        x: button_70.x + button_70.width + parent.width/261.7
        y: button_70.y
        width: button_26.width*1.5
        //Текст кнопки
        Text {
            id: buttonLabel_71
            font.bold : true
            text: "Alt L"
            color: "black"
            anchors.centerIn: parent;
        }
    }

    Button_Qml{
        id: button_72
        x: button_71.x + button_71.width + parent.width/261.7
        y: button_71.y
        width: button_26.width*6.08
        //Текст кнопки
        Text {
            id: buttonLabel_72
            font.bold : true
            text: "Space"
            color: "black"
            anchors.centerIn: parent;
        }
    }

    Button_Qml{
        id: button_73
        x: button_72.x + button_72.width + parent.width/261.7
        y: button_72.y
        width: button_26.width*1.5
        //Текст кнопки
        Text {
            id: buttonLabel_73
            font.bold : true
            text: "Alt R"
            color: "black"
            anchors.centerIn: parent;
        }
    }

    Button_Qml{
        id: button_74
        x: button_73.x + button_73.width + parent.width/261.7
        y: button_73.y
        width: button_26.width*1.5
        //Текст кнопки
        Text {
            id: buttonLabel_74
            font.bold : true
            text: "Super R"
            color: "black"
            anchors.centerIn: parent;
        }
    }

    Button_Qml{
        id: button_75
        x: button_74.x + button_74.width + parent.width/261.7
        y: button_74.y
        width: button_26.width*1.5
        //Текст кнопки
        Text {
            id: buttonLabel_75
            font.bold : true
            text: "Menu"
            color: "black"
            anchors.centerIn: parent;
        }
    }

    Button_Qml{
        id: button_76
        x: button_75.x + button_75.width + parent.width/261.7
        y: button_75.y
        width: button_26.width*1.5
        //Текст кнопки
        Text {
            id: buttonLabel_76
            font.bold : true
            text: "Ctrl R"
            color: "black"
            anchors.centerIn: parent;
        }
    }

    //////////////////////////////////////
    ////////////// The end ///////////////

    // Перемещения окна
    Move_Qml{
        width: parent.width/52.4
        height: parent.height/22.7
    }
    // Для изменения размера
    Size_input_Qml{ x: 20;y: 117}
}
