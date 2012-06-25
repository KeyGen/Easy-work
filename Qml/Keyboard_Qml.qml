// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Item {
    id: key
    width: parent.width
    height: parent.height

    // Пробую
//    function loadButton() {
//        var component = Qt.createComponent("Button_Qml.qml");

//        if (component.status == Component.Ready) {

//            for(var i = 0; i<9; i++)
//            {
//                var button = component.createObject(parent);

//                button.objectName = "button_" + i.toLocaleString();


//                button.x = 60*i+14*(i+1);
//                button.y = 30;
//                button.buttonLabel = i.toLocaleString();
//            }
//        }
//    }

//    Component.onCompleted: loadButton()

    //////////////////////////////////////
    ////////////// Клавиши ///////////////
    Button_Qml{
        id: button_1
        objectName: "button_1"
        x: parent.width/37
        y: parent.height/14

        buttonLabel: "Esc"
    }

    Button_Qml{
        id: button_2
        objectName: "button_2"
        x: button_1.x + button_1.width + parent.width/261.7 + parent.width/34.5
        y: button_1.y

        //Текст кнопки
        buttonLabel: "F1"
    }

    Button_Qml{
        id: button_3
        objectName: "button_2"
        x: button_2.x + button_3.width + parent.width/261.7
        y: button_1.y

        //Текст кнопки
        buttonLabel: "F2"
    }

    Button_Qml{
        id: button_4
        objectName: "button_2"
        x: button_3.x + button_4.width + parent.width/261.7
        y: button_1.y

        //Текст кнопки
        buttonLabel: "F3"
    }

    Button_Qml{
        id: button_5
        objectName: "button_2"
        x: button_4.x + button_5.width + parent.width/261.7
        y: button_1.y

        //Текст кнопки
        buttonLabel: "F4"
    }

    Button_Qml{
        id: button_6
        objectName: "button_2"
        x: button_5.x + button_2.width*2 + (parent.width/261.7)*2
        y: button_1.y

        //Текст кнопки
        buttonLabel: "F5"
    }

    Button_Qml{
        id: button_7
        objectName: "button_2"
        x: button_6.x + button_7.width + parent.width/261.7
        y: button_1.y

        //Текст кнопки
        buttonLabel: "F6"
    }

    Button_Qml{
        id: button_8
        objectName: "button_2"
        x: button_7.x + button_8.width + parent.width/261.7
        y: button_1.y

        //Текст кнопки
        buttonLabel: "F7"
    }

    Button_Qml{
        id: button_9
        objectName: "button_2"
        x: button_8.x + button_9.width + parent.width/261.7
        y: button_1.y

        //Текст кнопки
        buttonLabel: "F8"
    }

    Button_Qml{
        id: button_10
        objectName: "button_2"
        x: button_9.x + button_10.width*2 + (parent.width/261.7)*2
        y: button_1.y

        //Текст кнопки
        buttonLabel: "F9"
    }

    Button_Qml{
        id: button_11
        objectName: "button_2"
        x: button_10.x + button_11.width + parent.width/261.7
        y: button_1.y

        //Текст кнопки
        buttonLabel: "F10"
    }

    Button_Qml{
        id: button_12
        objectName: "button_2"
        x: button_11.x + button_12.width + parent.width/261.7
        y: button_1.y

        //Текст кнопки
        buttonLabel: "F11"
    }

    Button_Qml{
        id: button_13
        objectName: "button_2"
        x: button_12.x + button_13.width + parent.width/261.7
        y: button_1.y

        //Текст кнопки
        buttonLabel: "F12"
    }
    //////////////////////////////////////
    ////////////// второй ////////////////

    Button_Qml{
        id: button_14
        objectName: "button_2"
        x: parent.width/37
        y: button_1.y + button_14.height + button_14.height/2.3

        //Текст кнопки
        buttonLabel: "~\n`"
    }

    Button_Qml{
        id: button_15
        objectName: "button_2"
        x: button_14.x + button_15.width + parent.width/261.7
        y: button_1.y + button_15.height + button_15.height/2.3

        //Текст кнопки
        buttonLabel: "1"

    }

    Button_Qml{
        id: button_16
        objectName: "button_2"
        x: button_15.x + button_16.width + parent.width/261.7
        y: button_1.y + button_15.height + button_15.height/2.3

        //Текст кнопки
        buttonLabel: "2"
    }

    Button_Qml{
        id: button_17
        objectName: "button_2"
        x: button_16.x + button_17.width + parent.width/261.7
        y: button_1.y + button_15.height + button_15.height/2.3

        //Текст кнопки
        buttonLabel: "3"
    }

    Button_Qml{
        id: button_18
        objectName: "button_2"
        x: button_17.x + button_18.width + parent.width/261.7
        y: button_1.y + button_15.height + button_15.height/2.3

        //Текст кнопки
        buttonLabel: "4"
    }

    Button_Qml{
        id: button_19
        objectName: "button_2"
        x: button_18.x + button_19.width + parent.width/261.7
        y: button_1.y + button_15.height + button_15.height/2.3

        //Текст кнопки
        buttonLabel: "5"
    }

    Button_Qml{
        id: button_20
        objectName: "button_2"
        x: button_19.x + button_20.width + parent.width/261.7
        y: button_1.y + button_15.height + button_15.height/2.3

        //Текст кнопки
        buttonLabel: "6"
    }

    Button_Qml{
        id: button_21
        objectName: "button_2"
        x: button_20.x + button_21.width + parent.width/261.7
        y: button_1.y + button_15.height + button_15.height/2.3

        //Текст кнопки
        buttonLabel: "7"
    }

    Button_Qml{
        id: button_22
        objectName: "button_2"
        x: button_21.x + button_22.width + parent.width/261.7
        y: button_1.y + button_15.height + button_15.height/2.3

        //Текст кнопки
        buttonLabel: "8"
    }

    Button_Qml{
        id: button_23
        objectName: "button_2"
        x: button_22.x + button_23.width + parent.width/261.7
        y: button_1.y + button_15.height + button_15.height/2.3

        //Текст кнопки
        buttonLabel: "9"
    }

    Button_Qml{
        id: button_24
        objectName: "button_2"
        x: button_23.x + button_24.width + parent.width/261.7
        y: button_1.y + button_15.height + button_15.height/2.3

        //Текст кнопки
        buttonLabel: "0"
    }

    Button_Qml{
        id: button_25
        objectName: "button_2"
        x: button_24.x + button_25.width + parent.width/261.7
        y: button_1.y + button_15.height + button_15.height/2.3

        //Текст кнопки
        buttonLabel: "-"
    }

    Button_Qml{
        id: button_26
        objectName: "button_2"
        x: button_25.x + button_26.width + parent.width/261.7
        y: button_1.y + button_15.height + button_15.height/2.3

        //Текст кнопки
        buttonLabel: "="
    }

    Button_Qml{
        id: button_27
        objectName: "button_2"
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
        objectName: "button_2"
        x: parent.width/37
        y: button_27.y + button_28.height + parent.height/85
        width: button_27.width

        //Текст кнопки
        buttonLabel: "Tab"
    }

    Button_Qml{
        id: button_29
        objectName: "button_2"
        x: button_28.x + button_28.width + parent.width/261.7
        y: button_28.y

        //Текст кнопки
        buttonLabel: "Q"
    }

    Button_Qml{
        id: button_30
        objectName: "button_2"
        x: button_29.x + button_29.width + parent.width/261.7
        y: button_28.y

        //Текст кнопки
        buttonLabel: "W"
    }

    Button_Qml{
        id: button_31
        objectName: "button_2"
        x: button_30.x + button_30.width + parent.width/261.7
        y: button_28.y

        //Текст кнопки
        buttonLabel: "E"
    }

    Button_Qml{
        id: button_32
        objectName: "button_2"
        x: button_31.x + button_31.width + parent.width/261.7
        y: button_28.y

        //Текст кнопки
        buttonLabel: "R"
    }

    Button_Qml{
        id: button_33
        objectName: "button_2"
        x: button_32.x + button_32.width + parent.width/261.7
        y: button_28.y

        //Текст кнопки
        buttonLabel: "T"
    }

    Button_Qml{
        id: button_34
        objectName: "button_2"
        x: button_33.x + button_33.width + parent.width/261.7
        y: button_28.y

        //Текст кнопки
        buttonLabel: "Y"
    }

    Button_Qml{
        id: button_35
        objectName: "button_2"
        x: button_34.x + button_34.width + parent.width/261.7
        y: button_28.y

        //Текст кнопки
        buttonLabel: "U"
    }

    Button_Qml{
        id: button_36
        objectName: "button_2"
        x: button_35.x + button_35.width + parent.width/261.7
        y: button_28.y

        //Текст кнопки
        buttonLabel: "I"
    }

    Button_Qml{
        id: button_37
        objectName: "button_2"
        x: button_36.x + button_36.width + parent.width/261.7
        y: button_28.y

        //Текст кнопки
        buttonLabel: "O"
    }

    Button_Qml{
        id: button_38
        objectName: "button_2"
        x: button_37.x + button_37.width + parent.width/261.7
        y: button_28.y

        //Текст кнопки
        buttonLabel: "P"
    }

    Button_Qml{
        id: button_39
        objectName: "button_2"
        x: button_38.x + button_38.width + parent.width/261.7
        y: button_28.y

        //Текст кнопки
        buttonLabel: "{"
    }

    Button_Qml{
        id: button_40
        objectName: "button_2"
        x: button_39.x + button_39.width + parent.width/261.7
        y: button_28.y

        //Текст кнопки
        buttonLabel: "}"
    }

    Button_Qml{
        id: button_41
        objectName: "button_2"
        x: button_40.x + button_40.width + parent.width/261.7
        y: button_28.y

        //Текст кнопки
        buttonLabel: "|"
    }

    //////////////////////////////////////
    ///////////// четвертый //////////////

    Button_Qml{
        id: button_42
        objectName: "button_2"
        x: parent.width/37
        y: button_41.y + button_15.height + parent.height/85
        width: button_40.width*2.072

        //Текст кнопки
        buttonLabel: "Caps Lock"
    }

    Button_Qml{
        id: button_43
        objectName: "button_2"
        x: button_42.x + button_42.width + parent.width/261.7
        y: button_42.y

        //Текст кнопки
        buttonLabel: "A"
    }

    Button_Qml{
        id: button_44
        objectName: "button_2"
        x: button_43.x + button_43.width + parent.width/261.7
        y: button_42.y

        //Текст кнопки
        buttonLabel: "S"
    }

    Button_Qml{
        id: button_45
        objectName: "button_2"
        x: button_44.x + button_44.width + parent.width/261.7
        y: button_42.y

        //Текст кнопки
        buttonLabel: "D"
    }

    Button_Qml{
        id: button_46
        objectName: "button_2"
        x: button_45.x + button_45.width + parent.width/261.7
        y: button_42.y

        //Текст кнопки
        buttonLabel: "F"
    }

    Button_Qml{
        id: button_47
        objectName: "button_2"
        x: button_46.x + button_46.width + parent.width/261.7
        y: button_42.y

        //Текст кнопки
        buttonLabel: "G"
    }

    Button_Qml{
        id: button_48
        objectName: "button_2"
        x: button_47.x + button_47.width + parent.width/261.7
        y: button_42.y

        //Текст кнопки
        buttonLabel: "H"
    }

    Button_Qml{
        id: button_49
        objectName: "button_2"
        x: button_48.x + button_48.width + parent.width/261.7
        y: button_42.y

        //Текст кнопки
        buttonLabel: "J"
    }

    Button_Qml{
        id: button_50
        objectName: "button_2"
        x: button_49.x + button_49.width + parent.width/261.7
        y: button_42.y

        //Текст кнопки
        buttonLabel: "K"
    }

    Button_Qml{
        id: button_51
        objectName: "button_2"
        x: button_50.x + button_50.width + parent.width/261.7
        y: button_42.y

        //Текст кнопки
        buttonLabel: "L"
    }

    Button_Qml{
        id: button_52
        objectName: "button_2"
        x: button_51.x + button_51.width + parent.width/261.7
        y: button_42.y

        //Текст кнопки
        buttonLabel: ":"
    }

    Button_Qml{
        id: button_53
        objectName: "button_2"
        x: button_52.x + button_52.width + parent.width/261.7
        y: button_42.y

        //Текст кнопки
        buttonLabel: "\""
    }

    Button_Qml{
        id: button_54
        objectName: "button_2"
        x: button_53.x + button_53.width + parent.width/261.7
        y: button_42.y
        width: button_27.width

        //Текст кнопки
        buttonLabel: "ENTER"
    }

    //////////////////////////////////////
    /////////////// пятый ////////////////

    Button_Qml{
        id: button_55
        objectName: "button_2"
        x: parent.width/37
        y: button_54.y + button_54.height + parent.height/85
        width: button_27.width/0.9

        //Текст кнопки
        buttonLabel: "Shift"
    }

    Button_Qml{
        id: button_56
        objectName: "button_2"
        x: button_55.x + button_55.width + parent.width/261.7
        y: button_55.y

        //Текст кнопки
        buttonLabel: "Z"
    }

    Button_Qml{
        id: button_57
        objectName: "button_2"
        x: button_56.x + button_56.width + parent.width/261.7
        y: button_55.y

        //Текст кнопки
        buttonLabel: "X"
    }

    Button_Qml{
        id: button_58
        objectName: "button_2"
        x: button_57.x + button_57.width + parent.width/261.7
        y: button_55.y

        //Текст кнопки
        buttonLabel: "C"
    }

    Button_Qml{
        id: button_59
        objectName: "button_2"
        x: button_58.x + button_58.width + parent.width/261.7
        y: button_55.y

        //Текст кнопки
        buttonLabel: "V"
    }

    Button_Qml{
        id: button_60
        objectName: "button_2"
        x: button_59.x + button_59.width + parent.width/261.7
        y: button_55.y

        //Текст кнопки
        buttonLabel: "B"
    }

    Button_Qml{
        id: button_61
        objectName: "button_2"
        x: button_60.x + button_60.width + parent.width/261.7
        y: button_55.y

        //Текст кнопки
        buttonLabel: "N"
    }

    Button_Qml{
        id: button_62
        objectName: "button_2"
        x: button_61.x + button_61.width + parent.width/261.7
        y: button_55.y

        //Текст кнопки
        buttonLabel: "M"
    }

    Button_Qml{
        id: button_63
        objectName: "button_2"
        x: button_62.x + button_62.width + parent.width/261.7
        y: button_55.y

        //Текст кнопки
        buttonLabel: "<"
    }

    Button_Qml{
        id: button_64
        objectName: "button_2"
        x: button_63.x + button_63.width + parent.width/261.7
        y: button_55.y

        //Текст кнопки
        buttonLabel: ">"
    }

    Button_Qml{
        id: button_65
        objectName: "button_2"
        x: button_64.x + button_64.width + parent.width/261.7
        y: button_55.y

        //Текст кнопки
        buttonLabel: "?"
    }

    Button_Qml{
        id: button_66
        objectName: "button_2"
        x: button_65.x + button_65.width + parent.width/261.7
        y: button_55.y
        width: button_55.width

        //Текст кнопки
        buttonLabel: "Shift"
    }

    //////////////////////////////////////
    /////////////// шестой ///////////////

    Button_Qml{
        id: button_67
        objectName: "button_2"
        x: parent.width/37
        y: button_66.y + button_18.height + parent.height/85
        width: button_26.width*1.5

        //Текст кнопки
        buttonLabel: "Ctrl"
    }

    Button_Qml{
        id: button_68
        objectName: "button_2"
        x: button_67.x + button_67.width + parent.width/261.7
        y: button_67.y
        width: button_26.width*1.5

        //Текст кнопки
        buttonLabel: "Win"
    }

    Button_Qml{
        id: button_69
        objectName: "button_2"
        x: button_68.x + button_68.width + parent.width/261.7
        y: button_67.y
        width: button_26.width*1.5

        //Текст кнопки
        buttonLabel: "Alt"
    }

    Button_Qml{
        id: button_70
        objectName: "button_2"
        x: button_69.x + button_69.width + parent.width/261.7
        y: button_67.y
        width: button_27.width*2.74

        //Текст кнопки
        buttonLabel: "versia 2.0 :)"
    }

    Button_Qml{
        id: button_71
        objectName: "button_2"
        x: button_70.x + button_70.width + parent.width/261.7
        y: button_67.y
        width: button_26.width*1.5

        //Текст кнопки
        buttonLabel: "Alt Gr"
    }

    Button_Qml{
        id: button_72
        objectName: "button_2"
        x: button_71.x + button_71.width + parent.width/261.7
        y: button_67.y
        width: button_26.width*1.5

        //Текст кнопки
        buttonLabel: "Menu"
    }

    Button_Qml{
        id: button_73
        objectName: "button_2"
        x: button_72.x + button_72.width + parent.width/261.7
        y: button_67.y
        width: button_26.width*1.5

        //Текст кнопки
        buttonLabel: "Ctrl R"

    }

    //////////////////////////////////////
    ////////////// The end ///////////////

    focus: true


    Keys.onPressed: {
        if (event.key == Qt.Key_Escape) {
            button_1.state = "shift";
            button_1.scale = 0.8
            console.log(button_1.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_F1) {
            button_2.state = "shift";
            button_2.scale = 0.8
            console.log(button_2.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_F2) {
            button_3.state = "shift";
            button_3.scale = 0.8
            console.log(button_3.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_F3) {
            button_4.state = "shift";
            button_4.scale = 0.8
            console.log(button_4.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_F4) {
            button_5.state = "shift";
            button_5.scale = 0.8
            console.log(button_5.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_F5) {
            button_6.state = "shift";
            button_6.scale = 0.8
            console.log(button_6.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_F6) {
            button_7.state = "shift";
            button_7.scale = 0.8
            console.log(button_7.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_F7) {
            button_8.state = "shift";
            button_8.scale = 0.8
            console.log(button_8.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_F8) {
            button_9.state = "shift";
            button_9.scale = 0.8
            console.log(button_9.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_F9) {
            button_10.state = "shift";
            button_10.scale = 0.8
            console.log(button_10.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_F10) {
            button_11.state = "shift";
            button_11.scale = 0.8
            console.log(button_11.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_F11) {
            button_12.state = "shift";
            button_12.scale = 0.8
            console.log(button_12.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_F12) {
            button_13.state = "shift";
            button_13.scale = 0.8
            console.log(button_13.buttonLabel.toLocaleString() + " clicked" )
        }
        /////////////////////////////////////////////////////////////////////
        else if (event.key == 96 | event.key == 126) {
            button_14.state = "shift";
            button_14.scale = 0.8
            console.log(button_14.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_1 | event.key == Qt.Key_Exclam) {
            button_15.state = "shift";
            button_15.scale = 0.8
            console.log(button_15.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_2 | event.key == 64) {
            button_16.state = "shift";
            button_16.scale = 0.8
            console.log(button_16.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_3 | event.key == Qt.Key_NumberSign) {
            button_17.state = "shift";
            button_17.scale = 0.8
            console.log(button_17.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_4 | event.key == Qt.Key_Dollar) {
            button_18.state = "shift";
            button_18.scale = 0.8
            console.log(button_18.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_5 | event.key == Qt.Key_Percent) {
            button_19.state = "shift";
            button_19.scale = 0.8
            console.log(button_19.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_6 | event.key == 94) {
            button_20.state = "shift";
            button_20.scale = 0.8
            console.log(button_20.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_7 | event.key == Qt.Key_Ampersand) {
            button_21.state = "shift";
            button_21.scale = 0.8
            console.log(button_21.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_8 | event.key == 42) {
            button_22.state = "shift";
            button_22.scale = 0.8
            console.log(button_22.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_9 | event.key == Qt.Key_ParenLeft) {
            button_23.state = "shift";
            button_23.scale = 0.8
            console.log(button_23.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_0 | event.key == Qt.Key_ParenRight) {
            button_24.state = "shift";
            button_24.scale = 0.8
            console.log(button_24.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_Minus | event.key == 95) {
            button_25.state = "shift";
            button_25.scale = 0.8
            console.log(button_25.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_Equal | event.key == Qt.Key_Plus) {
            button_26.state = "shift";
            button_26.scale = 0.8
            console.log(button_26.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_Backspace) {
            button_27.state = "shift";
            button_27.scale = 0.8
            console.log(button_27.buttonLabel.toLocaleString() + " clicked" )
        }
        /////////////////////////////////////////////////////////////////////
        else if (event.key == Qt.Key_Tab) {
            button_28.state = "shift";
            button_28.scale = 0.8
            console.log(button_28.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_Q) {
            button_29.state = "shift";
            button_29.scale = 0.8
            console.log(button_29.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_W) {
            button_30.state = "shift";
            button_30.scale = 0.8
            console.log(button_30.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_E) {
            button_31.state = "shift";
            button_31.scale = 0.8
            console.log(button_31.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_R) {
            button_32.state = "shift";
            button_32.scale = 0.8
            console.log(button_32.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_T) {
            button_33.state = "shift";
            button_33.scale = 0.8
            console.log(button_33.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_Y) {
            button_34.state = "shift";
            button_34.scale = 0.8
            console.log(button_34.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_U) {
            button_35.state = "shift";
            button_35.scale = 0.8
            console.log(button_35.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_I) {
            button_36.state = "shift";
            button_36.scale = 0.8
            console.log(button_36.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_O) {
            button_37.state = "shift";
            button_37.scale = 0.8
            console.log(button_37.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_P) {
            button_38.state = "shift";
            button_38.scale = 0.8
            console.log(button_38.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == 91) {
            button_39.state = "shift";
            button_39.scale = 0.8
            console.log(button_39.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == 93) {
            button_40.state = "shift";
            button_40.scale = 0.8
            console.log(button_40.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == 92 | event.key == Qt.Key_Bar) {
            button_41.state = "shift";
            button_41.scale = 0.8
            console.log(button_41.buttonLabel.toLocaleString() + " clicked" )
        }
        /////////////////////////////////////////////////////////////////////
        else if (event.key == Qt.Key_CapsLock) {
            button_42.state = "shift";
            button_42.scale = 0.8
            console.log(button_42.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_A) {
            button_43.state = "shift";
            button_43.scale = 0.8
            console.log(button_43.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_S) {
            button_44.state = "shift";
            button_44.scale = 0.8
            console.log(button_44.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_D) {
            button_45.state = "shift";
            button_45.scale = 0.8
            console.log(button_45.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_F) {
            button_46.state = "shift";
            button_46.scale = 0.8
            console.log(button_46.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_G) {
            button_47.state = "shift";
            button_47.scale = 0.8
            console.log(button_47.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_H) {
            button_48.state = "shift";
            button_48.scale = 0.8
            console.log(button_48.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_J) {
            button_49.state = "shift";
            button_49.scale = 0.8
            console.log(button_49.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_K) {
            button_50.state = "shift";
            button_50.scale = 0.8
            console.log(button_50.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_L) {
            button_51.state = "shift";
            button_51.scale = 0.8
            console.log(button_51.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == 59) {
            button_52.state = "shift";
            button_52.scale = 0.8
            console.log(button_52.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == 39) {
            button_53.state = "shift";
            button_53.scale = 0.8
            console.log(button_53.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == 16777220) {
            button_54.state = "shift";
            button_54.scale = 0.8
            console.log(button_54.buttonLabel.toLocaleString() + " clicked" )
        }
        /////////////////////////////////////////////////////////////////////
        else if (event.key == Qt.Key_Shift) {
            button_55.state = "shift";
            button_55.scale = 0.8
            console.log(button_56.buttonLabel.toLocaleString() + " clicked" )
            button_66.state = "shift";
            button_66.scale = 0.8
            console.log(button_66.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_Z) {
            button_56.state = "shift";
            button_56.scale = 0.8
            console.log(button_56.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_X) {
            button_57.state = "shift";
            button_57.scale = 0.8
            console.log(button_57.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_C) {
            button_58.state = "shift";
            button_58.scale = 0.8
            console.log(button_58.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_V) {
            button_59.state = "shift";
            button_59.scale = 0.8
            console.log(button_59.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_B) {
            button_60.state = "shift";
            button_60.scale = 0.8
            console.log(button_60.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_N) {
            button_61.state = "shift";
            button_61.scale = 0.8
            console.log(button_61.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_M) {
            button_62.state = "shift";
            button_62.scale = 0.8
            console.log(button_62.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_Comma) {
            button_63.state = "shift";
            button_63.scale = 0.8
            console.log(button_63.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == 46) {
            button_64.state = "shift";
            button_64.scale = 0.8
            console.log(button_64.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_Question | event.key == 47) {
            button_65.state = "shift";
            button_65.scale = 0.8
            console.log(button_65.buttonLabel.toLocaleString() + " clicked" )
        }
        /////////////////////////////////////////////////////////////////////
        else if (event.key == Qt.Key_Control) {
            button_67.state = "shift";
            button_67.scale = 0.8
            console.log(button_67.buttonLabel.toLocaleString() + " clicked" )
            button_73.state = "shift";
            button_73.scale = 0.8
            console.log(button_73.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == 16777250) { // ?????????????????????????
            button_68.state = "shift";
            button_68.scale = 0.8
            console.log(button_68.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_Alt) {
            button_69.state = "shift";
            button_69.scale = 0.8
            console.log(button_69.buttonLabel.toLocaleString() + " clicked" )
            button_71.state = "shift";
            button_71.scale = 0.8
            console.log(button_71.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_Space) {
            button_70.state = "shift";
            button_70.scale = 0.8
            console.log(button_70.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_Menu) {
            button_72.state = "shift";
            button_72.scale = 0.8
            console.log(button_72.buttonLabel.toLocaleString() + " clicked" )
        }
        else
            console.log(event.key)
    }

    //////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////

    Keys.onReleased: {

        if (event.key == Qt.Key_Escape) {
            button_1.state = "normal";
            button_1.scale = 1.0
            console.log(button_1.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_F1) {
            button_2.state = "normal";
            button_2.scale = 1.0
            console.log(button_2.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_F2) {
            button_3.state = "normal";
            button_3.scale = 1.0
            console.log(button_3.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_F3) {
            button_4.state = "normal";
            button_4.scale = 1.0
            console.log(button_4.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_F4) {
            button_5.state = "normal";
            button_5.scale = 1.0
            console.log(button_5.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_F5) {
            button_6.state = "normal";
            button_6.scale = 1.0
            console.log(button_6.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_F6) {
            button_7.state = "normal";
            button_7.scale = 1.0
            console.log(button_7.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_F7) {
            button_8.state = "normal";
            button_8.scale = 1.0
            console.log(button_8.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_F8) {
            button_9.state = "normal";
            button_9.scale = 1.0
            console.log(button_9.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_F9) {
            button_10.state = "normal";
            button_10.scale = 1.0
            console.log(button_10.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_F10) {
            button_11.state = "normal";
            button_11.scale = 1.0
            console.log(button_11.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_F11) {
            button_12.state = "normal";
            button_12.scale = 1.0
            console.log(button_12.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_F12) {
            button_13.state = "normal";
            button_13.scale = 1.0
            console.log(button_13.buttonLabel.toLocaleString() + " clicked" )
        }
        /////////////////////////////////////////////////////////////////////
        else if (event.key == 96 | event.key == 126) {
            button_14.state = "normal";
            button_14.scale = 1.0
            console.log(button_14.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_1 | event.key == Qt.Key_Exclam) {
            button_15.state = "normal";
            button_15.scale = 1.0
            console.log(button_15.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_2 | event.key == 64) {
            button_16.state = "normal";
            button_16.scale = 1.0
            console.log(button_16.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_3 | event.key == Qt.Key_NumberSign) {
            button_17.state = "normal";
            button_17.scale = 1.0
            console.log(button_17.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_4 | event.key == Qt.Key_Dollar) {
            button_18.state = "normal";
            button_18.scale = 1.0
            console.log(button_18.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_5 | event.key == Qt.Key_Percent) {
            button_19.state = "normal";
            button_19.scale = 1.0
            console.log(button_19.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_6 | event.key == 94) {
            button_20.state = "normal";
            button_20.scale = 1.0
            console.log(button_20.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_7 | event.key == Qt.Key_Ampersand) {
            button_21.state = "normal";
            button_21.scale = 1.0
            console.log(button_21.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_8 | event.key == 42) {
            button_22.state = "normal";
            button_22.scale = 1.0
            console.log(button_22.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_9 | event.key == Qt.Key_ParenLeft) {
            button_23.state = "normal";
            button_23.scale = 1.0
            console.log(button_23.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_0 | event.key == Qt.Key_ParenRight) {
            button_24.state = "normal";
            button_24.scale = 1.0
            console.log(button_24.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_Minus | event.key == 95) {
            button_25.state = "normal";
            button_25.scale = 1.0
            console.log(button_25.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_Equal | event.key == Qt.Key_Plus) {
            button_26.state = "normal";
            button_26.scale = 1.0
            console.log(button_26.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_Backspace) {
            button_27.state = "normal";
            button_27.scale = 1.0
            console.log(button_27.buttonLabel.toLocaleString() + " clicked" )
        }
        /////////////////////////////////////////////////////////////////////
        else if (event.key == Qt.Key_Tab) {
            button_28.state = "normal";
            button_28.scale = 1.0
            console.log(button_28.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_Q) {
            button_29.state = "normal";
            button_29.scale = 1.0
            console.log(button_29.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_W) {
            button_30.state = "normal";
            button_30.scale = 1.0
            console.log(button_30.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_E) {
            button_31.state = "normal";
            button_31.scale = 1.0
            console.log(button_31.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_R) {
            button_32.state = "normal";
            button_32.scale = 1.0
            console.log(button_32.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_T) {
            button_33.state = "normal";
            button_33.scale = 1.0
            console.log(button_33.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_Y) {
            button_34.state = "normal";
            button_34.scale = 1.0
            console.log(button_34.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_U) {
            button_35.state = "normal";
            button_35.scale = 1.0
            console.log(button_35.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_I) {
            button_36.state = "normal";
            button_36.scale = 1.0
            console.log(button_36.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_O) {
            button_37.state = "normal";
            button_37.scale = 1.0
            console.log(button_37.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_P) {
            button_38.state = "normal";
            button_38.scale = 1.0
            console.log(button_38.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == 91) {
            button_39.state = "normal";
            button_39.scale = 1.0
            console.log(button_39.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == 93) {
            button_40.state = "normal";
            button_40.scale = 1.0
            console.log(button_40.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == 92 | event.key == Qt.Key_Bar) {
            button_41.state = "normal";
            button_41.scale = 1.0
            console.log(button_41.buttonLabel.toLocaleString() + " clicked" )
        }
        /////////////////////////////////////////////////////////////////////
        else if (event.key == Qt.Key_CapsLock) {
            button_42.state = "normal";
            button_42.scale = 1.0
            console.log(button_42.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_A) {
            button_43.state = "normal";
            button_43.scale = 1.0
            console.log(button_43.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_S) {
            button_44.state = "normal";
            button_44.scale = 1.0
            console.log(button_44.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_D) {
            button_45.state = "normal";
            button_45.scale = 1.0
            console.log(button_45.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_F) {
            button_46.state = "normal";
            button_46.scale = 1.0
            console.log(button_46.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_G) {
            button_47.state = "normal";
            button_47.scale = 1.0
            console.log(button_47.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_H) {
            button_48.state = "normal";
            button_48.scale = 1.0
            console.log(button_48.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_J) {
            button_49.state = "normal";
            button_49.scale = 1.0
            console.log(button_49.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_K) {
            button_50.state = "normal";
            button_50.scale = 1.0
            console.log(button_50.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_L) {
            button_51.state = "normal";
            button_51.scale = 1.0
            console.log(button_51.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == 59) {
            button_52.state = "normal";
            button_52.scale = 1.0
            console.log(button_52.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == 39) {
            button_53.state = "normal";
            button_53.scale = 1.0
            console.log(button_53.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == 16777220) {
            button_54.state = "normal";
            button_54.scale = 1.0
            console.log(button_54.buttonLabel.toLocaleString() + " clicked" )
        }
        /////////////////////////////////////////////////////////////////////
        else if (event.key == Qt.Key_Shift) {
            button_55.state = "normal";
            button_55.scale = 1.0
            console.log(button_56.buttonLabel.toLocaleString() + " clicked" )
            button_66.state = "normal";
            button_66.scale = 1.0
            console.log(button_66.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_Z) {
            button_56.state = "normal";
            button_56.scale = 1.0
            console.log(button_56.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_X) {
            button_57.state = "normal";
            button_57.scale = 1.0
            console.log(button_57.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_C) {
            button_58.state = "normal";
            button_58.scale = 1.0
            console.log(button_58.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_V) {
            button_59.state = "normal";
            button_59.scale = 1.0
            console.log(button_59.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_B) {
            button_60.state = "normal";
            button_60.scale = 1.0
            console.log(button_60.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_N) {
            button_61.state = "normal";
            button_61.scale = 1.0
            console.log(button_61.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_M) {
            button_62.state = "normal";
            button_62.scale = 1.0
            console.log(button_62.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_Comma) {
            button_63.state = "normal";
            button_63.scale = 1.0
            console.log(button_63.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == 46) {
            button_64.state = "normal";
            button_64.scale = 1.0
            console.log(button_64.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_Question | event.key == 47) {
            button_65.state = "normal";
            button_65.scale = 1.0
            console.log(button_65.buttonLabel.toLocaleString() + " clicked" )
        }
        /////////////////////////////////////////////////////////////////////
        else if (event.key == Qt.Key_Control) {
            button_67.state = "normal";
            button_67.scale = 1.0
            console.log(button_67.buttonLabel.toLocaleString() + " clicked" )
            button_73.state = "normal";
            button_73.scale = 1.0
            console.log(button_73.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == 16777250) { // ?????????????????????????
            button_68.state = "normal";
            button_68.scale = 1.0
            console.log(button_68.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_Alt) {
            button_69.state = "normal";
            button_69.scale = 1.0
            console.log(button_69.buttonLabel.toLocaleString() + " clicked" )
            button_71.state = "normal";
            button_71.scale = 1.0
            console.log(button_71.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_Space) {
            button_70.state = "normal";
            button_70.scale = 1.0
            console.log(button_70.buttonLabel.toLocaleString() + " clicked" )
        }
        else if (event.key == Qt.Key_Menu) {
            button_72.state = "normal";
            button_72.scale = 1.0
            console.log(button_72.buttonLabel.toLocaleString() + " clicked" )
        }
        else
            console.log(event.key)
    }

}
