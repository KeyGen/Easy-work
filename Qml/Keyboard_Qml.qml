// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Item {

    width: parent.width
    height: parent.height

    //////////////////////////////////////
    ////////////// Клавиши ///////////////
    Button_Qml{
        id: button_1
        x: parent.width/37
        y: parent.height/14

        buttonLabel: "Esc"
    }

    Button_Qml{
        id: button_2

        x: button_1.x + button_1.width + parent.width/261.7 + parent.width/34.5
        y: button_1.y

        //Текст кнопки
        buttonLabel: "F1"
    }

    Button_Qml{
        id: button_3
        x: button_2.x + button_3.width + parent.width/261.7
        y: button_1.y

        //Текст кнопки
        buttonLabel: "F2"
    }

    Button_Qml{
        id: button_4
        x: button_3.x + button_4.width + parent.width/261.7
        y: button_1.y

        //Текст кнопки
        buttonLabel: "F3"
    }

    Button_Qml{
        id: button_5
        x: button_4.x + button_5.width + parent.width/261.7
        y: button_1.y

        //Текст кнопки
        buttonLabel: "F4"
    }

    Button_Qml{
        id: button_6
        x: button_5.x + button_2.width*2 + (parent.width/261.7)*2
        y: button_1.y

        //Текст кнопки
        buttonLabel: "F5"
    }

    Button_Qml{
        id: button_7
        x: button_6.x + button_7.width + parent.width/261.7
        y: button_1.y

        //Текст кнопки
        buttonLabel: "F6"
    }

    Button_Qml{
        id: button_8
        x: button_7.x + button_8.width + parent.width/261.7
        y: button_1.y

        //Текст кнопки
        buttonLabel: "F7"
    }

    Button_Qml{
        id: button_9
        x: button_8.x + button_9.width + parent.width/261.7
        y: button_1.y

        //Текст кнопки
        buttonLabel: "F8"
    }

    Button_Qml{
        id: button_10
        x: button_9.x + button_10.width*2 + (parent.width/261.7)*2
        y: button_1.y

        //Текст кнопки
        buttonLabel: "F9"
    }

    Button_Qml{
        id: button_11
        x: button_10.x + button_11.width + parent.width/261.7
        y: button_1.y

        //Текст кнопки
        buttonLabel: "F10"
    }

    Button_Qml{
        id: button_12
        x: button_11.x + button_12.width + parent.width/261.7
        y: button_1.y

        //Текст кнопки
        buttonLabel: "F11"
    }

    Button_Qml{
        id: button_13
        x: button_12.x + button_13.width + parent.width/261.7
        y: button_1.y

        //Текст кнопки
        buttonLabel: "F12"
    }
    //////////////////////////////////////
    ////////////// второй ////////////////

    Button_Qml{
        id: button_14
        x: parent.width/37
        y: button_1.y + button_14.height + button_14.height/2.3

        //Текст кнопки
        buttonLabel: "~\n`"
    }

    Button_Qml{
        id: button_15
        x: button_14.x + button_15.width + parent.width/261.7
        y: button_1.y + button_15.height + button_15.height/2.3

        //Текст кнопки
        buttonLabel: "1"

    }

    Button_Qml{
        id: button_16
        x: button_15.x + button_16.width + parent.width/261.7
        y: button_1.y + button_15.height + button_15.height/2.3

        //Текст кнопки
        buttonLabel: "2"
    }

    Button_Qml{
        id: button_17
        x: button_16.x + button_17.width + parent.width/261.7
        y: button_1.y + button_15.height + button_15.height/2.3

        //Текст кнопки
        buttonLabel: "3"
    }

    Button_Qml{
        id: button_18
        x: button_17.x + button_18.width + parent.width/261.7
        y: button_1.y + button_15.height + button_15.height/2.3

        //Текст кнопки
        buttonLabel: "4"
    }

    Button_Qml{
        id: button_19
        x: button_18.x + button_19.width + parent.width/261.7
        y: button_1.y + button_15.height + button_15.height/2.3

        //Текст кнопки
        buttonLabel: "5"
    }

    Button_Qml{
        id: button_20
        x: button_19.x + button_20.width + parent.width/261.7
        y: button_1.y + button_15.height + button_15.height/2.3

        //Текст кнопки
        buttonLabel: "6"
    }

    Button_Qml{
        id: button_21
        x: button_20.x + button_21.width + parent.width/261.7
        y: button_1.y + button_15.height + button_15.height/2.3

        //Текст кнопки
        buttonLabel: "7"
    }

    Button_Qml{
        id: button_22
        x: button_21.x + button_22.width + parent.width/261.7
        y: button_1.y + button_15.height + button_15.height/2.3

        //Текст кнопки
        buttonLabel: "8"
    }

    Button_Qml{
        id: button_23
        x: button_22.x + button_23.width + parent.width/261.7
        y: button_1.y + button_15.height + button_15.height/2.3

        //Текст кнопки
        buttonLabel: "9"
    }

    Button_Qml{
        id: button_24
        x: button_23.x + button_24.width + parent.width/261.7
        y: button_1.y + button_15.height + button_15.height/2.3

        //Текст кнопки
        buttonLabel: "0"
    }

    Button_Qml{
        id: button_25
        x: button_24.x + button_25.width + parent.width/261.7
        y: button_1.y + button_15.height + button_15.height/2.3

        //Текст кнопки
        buttonLabel: "-"
    }

    Button_Qml{
        id: button_26
        x: button_25.x + button_26.width + parent.width/261.7
        y: button_1.y + button_15.height + button_15.height/2.3

        //Текст кнопки
        buttonLabel: "="
    }

    Button_Qml{
        id: button_27
        x: button_26.x + button_26.width + parent.width/261.7
        y: button_1.y + button_15.height + button_15.height/2.3
        //width: parent.width/5.72
        width: parent.width/7

        //Текст кнопки
        buttonLabel: "backspase"
    }

    //////////////////////////////////////
    ////////////// третий ////////////////

    Button_Qml{
        id: button_28
        x: parent.width/37
        y: button_27.y + button_28.height + parent.height/85
        width: button_27.width

        //Текст кнопки
        buttonLabel: "Tab"
    }

    Button_Qml{
        id: button_29
        x: button_28.x + button_28.width + parent.width/261.7
        y: button_28.y

        //Текст кнопки
        buttonLabel: "Q"
    }

    Button_Qml{
        id: button_30
        x: button_29.x + button_29.width + parent.width/261.7
        y: button_28.y

        //Текст кнопки
        buttonLabel: "W"
    }

    Button_Qml{
        id: button_31
        x: button_30.x + button_30.width + parent.width/261.7
        y: button_28.y

        //Текст кнопки
        buttonLabel: "E"
    }

    Button_Qml{
        id: button_32
        x: button_31.x + button_31.width + parent.width/261.7
        y: button_28.y

        //Текст кнопки
        buttonLabel: "R"
    }

    Button_Qml{
        id: button_33
        x: button_32.x + button_32.width + parent.width/261.7
        y: button_28.y

        //Текст кнопки
        buttonLabel: "T"
    }

    Button_Qml{
        id: button_34
        x: button_33.x + button_33.width + parent.width/261.7
        y: button_28.y

        //Текст кнопки
        buttonLabel: "Y"
    }

    Button_Qml{
        id: button_35
        x: button_34.x + button_34.width + parent.width/261.7
        y: button_28.y

        //Текст кнопки
        buttonLabel: "U"
    }

    Button_Qml{
        id: button_36
        x: button_35.x + button_35.width + parent.width/261.7
        y: button_28.y

        //Текст кнопки
        buttonLabel: "I"
    }

    Button_Qml{
        id: button_37
        x: button_36.x + button_36.width + parent.width/261.7
        y: button_28.y

        //Текст кнопки
        buttonLabel: "O"
    }

    Button_Qml{
        id: button_38
        x: button_37.x + button_37.width + parent.width/261.7
        y: button_28.y

        //Текст кнопки
        buttonLabel: "P"
    }

    Button_Qml{
        id: button_39
        x: button_38.x + button_38.width + parent.width/261.7
        y: button_28.y

        //Текст кнопки
        buttonLabel: "{"
    }

    Button_Qml{
        id: button_40
        x: button_39.x + button_39.width + parent.width/261.7
        y: button_28.y

        //Текст кнопки
        buttonLabel: "}"
    }

    Button_Qml{
        id: button_41
        x: button_40.x + button_40.width + parent.width/261.7
        y: button_28.y

        //Текст кнопки
        buttonLabel: "|"
    }

    //////////////////////////////////////
    ///////////// четвертый //////////////

    Button_Qml{
        id: button_42
        x: parent.width/37
        y: button_41.y + button_15.height + parent.height/85
        width: button_40.width*2.072

        //Текст кнопки
        buttonLabel: "Caps Lock"
    }

    Button_Qml{
        id: button_43
        x: button_42.x + button_42.width + parent.width/261.7
        y: button_42.y

        //Текст кнопки
        buttonLabel: "A"
    }

    Button_Qml{
        id: button_44
        x: button_43.x + button_43.width + parent.width/261.7
        y: button_42.y

        //Текст кнопки
        buttonLabel: "S"
    }

    Button_Qml{
        id: button_45
        x: button_44.x + button_44.width + parent.width/261.7
        y: button_42.y

        //Текст кнопки
        buttonLabel: "D"
    }

    Button_Qml{
        id: button_46
        x: button_45.x + button_45.width + parent.width/261.7
        y: button_42.y

        //Текст кнопки
        buttonLabel: "F"
    }

    Button_Qml{
        id: button_47
        x: button_46.x + button_46.width + parent.width/261.7
        y: button_42.y

        //Текст кнопки
        buttonLabel: "G"
    }

    Button_Qml{
        id: button_48
        x: button_47.x + button_47.width + parent.width/261.7
        y: button_42.y

        //Текст кнопки
        buttonLabel: "H"
    }

    Button_Qml{
        id: button_49
        x: button_48.x + button_48.width + parent.width/261.7
        y: button_42.y

        //Текст кнопки
        buttonLabel: "J"
    }

    Button_Qml{
        id: button_50
        x: button_49.x + button_49.width + parent.width/261.7
        y: button_42.y

        //Текст кнопки
        buttonLabel: "K"
    }

    Button_Qml{
        id: button_51
        x: button_50.x + button_50.width + parent.width/261.7
        y: button_42.y

        //Текст кнопки
        buttonLabel: "L"
    }

    Button_Qml{
        id: button_52
        x: button_51.x + button_51.width + parent.width/261.7
        y: button_42.y

        //Текст кнопки
        buttonLabel: ":"
    }

    Button_Qml{
        id: button_53
        x: button_52.x + button_52.width + parent.width/261.7
        y: button_42.y

        //Текст кнопки
        buttonLabel: "\""
    }

    Button_Qml{
        id: button_55
        x: button_53.x + button_53.width + parent.width/261.7
        y: button_42.y
        width: button_27.width

        //Текст кнопки
        buttonLabel: "ENTER"
    }

    //////////////////////////////////////
    /////////////// пятый ////////////////

    Button_Qml{
        id: button_56
        x: parent.width/37
        y: button_55.y + button_55.height + parent.height/85
        width: button_27.width/1.11

        //Текст кнопки
        buttonLabel: "Shift"
    }

    Button_Qml{
        id: button_57
        x: button_56.x + button_56.width + parent.width/261.7
        y: button_56.y

        //Текст кнопки
        buttonLabel: "\\"
    }

    Button_Qml{
        id: button_58
        x: button_57.x + button_57.width + parent.width/261.7
        y: button_57.y

        //Текст кнопки
        buttonLabel: "Z"
    }

    Button_Qml{
        id: button_59
        x: button_58.x + button_58.width + parent.width/261.7
        y: button_56.y

        //Текст кнопки
        buttonLabel: "X"
    }

    Button_Qml{
        id: button_60
        x: button_59.x + button_59.width + parent.width/261.7
        y: button_56.y

        //Текст кнопки
        buttonLabel: "C"
    }

    Button_Qml{
        id: button_61
        x: button_60.x + button_60.width + parent.width/261.7
        y: button_56.y

        //Текст кнопки
        buttonLabel: "V"
    }

    Button_Qml{
        id: button_62
        x: button_61.x + button_61.width + parent.width/261.7
        y: button_56.y

        //Текст кнопки
        buttonLabel: "B"
    }

    Button_Qml{
        id: button_63
        x: button_62.x + button_62.width + parent.width/261.7
        y: button_56.y

        //Текст кнопки
        buttonLabel: "N"
    }

    Button_Qml{
        id: button_64
        x: button_63.x + button_63.width + parent.width/261.7
        y: button_56.y

        //Текст кнопки
        buttonLabel: "M"
    }

    Button_Qml{
        id: button_65
        x: button_64.x + button_64.width + parent.width/261.7
        y: button_56.y

        //Текст кнопки
        buttonLabel: "<"
    }

    Button_Qml{
        id: button_66
        x: button_65.x + button_65.width + parent.width/261.7
        y: button_56.y

        //Текст кнопки
        buttonLabel: ">"
    }

    Button_Qml{
        id: button_67
        x: button_66.x + button_66.width + parent.width/261.7
        y: button_56.y

        //Текст кнопки
        buttonLabel: "?"
    }

    Button_Qml{
        id: button_68
        x: button_67.x + button_67.width + parent.width/261.7
        y: button_56.y
        width: button_56.width

        //Текст кнопки
        buttonLabel: "Shift"
    }

    //////////////////////////////////////
    /////////////// шестой ///////////////

    Button_Qml{
        id: button_69
        x: parent.width/37
        y: button_68.y + button_18.height + parent.height/85
        width: button_26.width*1.5

        //Текст кнопки
        buttonLabel: "Ctrl"
    }

    Button_Qml{
        id: button_70
        x: button_69.x + button_69.width + parent.width/261.7
        y: button_69.y
        width: button_26.width*1.5

        //Текст кнопки
        buttonLabel: "Super L"
    }

    Button_Qml{
        id: button_71
        x: button_70.x + button_70.width + parent.width/261.7
        y: button_70.y
        width: button_26.width*1.5

        //Текст кнопки
        buttonLabel: "Alt L"
    }

    Button_Qml{
        id: button_72
        x: button_71.x + button_71.width + parent.width/261.7
        y: button_71.y
        width: button_27.width*2.13

        //Текст кнопки
        buttonLabel: "versia 2.0 :)"
    }

    Button_Qml{
        id: button_73
        x: button_72.x + button_72.width + parent.width/261.7
        y: button_72.y
        width: button_26.width*1.5

        //Текст кнопки
        buttonLabel: "Alt R"
    }

    Button_Qml{
        id: button_74
        x: button_73.x + button_73.width + parent.width/261.7
        y: button_73.y
        width: button_26.width*1.5

        //Текст кнопки
        buttonLabel: "Super R"
    }

    Button_Qml{
        id: button_75
        x: button_74.x + button_74.width + parent.width/261.7
        y: button_74.y
        width: button_26.width*1.5

        //Текст кнопки
        buttonLabel: "Menu"
    }

    Button_Qml{
        id: button_76
        x: button_75.x + button_75.width + parent.width/261.7
        y: button_75.y
        width: button_26.width*1.5

        //Текст кнопки
        buttonLabel: "Ctrl R"

    }

    //////////////////////////////////////
    ////////////// The end ///////////////
}
