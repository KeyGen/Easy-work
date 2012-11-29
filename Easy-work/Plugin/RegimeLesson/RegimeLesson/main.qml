// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Rectangle {
    id: window
    width: 600; height: 460; color: "#d2d2d2"
    x: -200
    y: -100

    FunctionLanguageLesson{id: lenguageLesson}

    FunctionNameLesson{id: nameLesson
        Timer {
            id: timer
            objectName: "setItemNameLessonF";
            interval: 1000;
            onTriggered:
            { var i = lessonTypes.count;
                nameLesson.setItemLesson(i);
                avtorPane.opacity = 1.0
                flickable.contentHeight = layout.height+330;
            }
        }
    }

    ListModel {
        id: lessonTypes
    }

    Gradient {
        id: backgroundItemOne
        GradientStop { position: 0.0; color: "#1e1e1e"}
        GradientStop { position: 0.5; color: "#828282"}
        GradientStop { position: 1.0; color: "#1e1e1e"}
    }

    Gradient {
        id: backgroundItemPress
        GradientStop { position: 0.0; color: "#828282"}
        GradientStop { position: 0.5; color: "#1e1e1e"}
        GradientStop { position: 1.0; color: "#828282"}
    }

    Gradient {
        id: backgroundItemTwo
        GradientStop { position: 0.0; color: "#828282"}
        GradientStop { position: 0.5; color: "#c8c8c8"}
        GradientStop { position: 1.0; color: "#828282"}
    }

    Component {
        id: delegate

        Item {
            height: 56; width: window.width

            Rectangle {
                id: slot3; height: 50; width: window.width - 430
                x: 210
                border.width: 2
                border.color: colorBorderRect;
                radius: 12
                smooth: true
                anchors.verticalCenter: parent.verticalCenter

                state: "normalslot3"

                states: [
                    State {
                        name: "normalslot3"
                        PropertyChanges {target: slot3;
                            gradient: backgroundItemOne
                        }
                    },
                    State {
                        name: "shiftslot3"
                        PropertyChanges {target: slot3;
                            gradient: backgroundItemTwo
                        }
                    }
                ]

                MouseArea {
                    id: itemLessonPress

                    onEntered: {
                        if(avtorPane.opacity != 0&&slot3.state != "shiftslot3"){
                            slot3.scale = 0.95;
                            textAll.font.bold = true;
                            slot3.gradient = backgroundItemPress;
                        }
                    }

                    onExited: {
                        if(avtorPane.opacity != 0&&slot3.state != "shiftslot3"){
                            Qt_fun.startLesson(index);
                            textAll.font.bold = false;
                            slot3.scale = 1.0;
                            slot3.gradient = backgroundItemOne;
                        }
                    }

                    anchors.fill: parent
                    anchors.margins: -5 // Make MouseArea bigger than the rectangle, itself
                }
            }

            Text { id: textAll; text: name; font.pixelSize: 14; anchors.centerIn: parent; color: "White" }

            Rectangle {
                id: slot1; color: "#121212"; x: 230; height: 46; width: 46
                border.color: "#343434"; border.width: 1; radius: 12
                anchors.verticalCenter: parent.verticalCenter

                MouseArea {
                    anchors.fill: parent
                    anchors.margins: -5 // Make MouseArea bigger than the rectangle, itself
                }
            }

            Rectangle {
                id: slot2; color: "#121212"; x: window.width - 240 - slot2.width; height: 46; width: 46
                border.color: "#343434"; border.width: 1; radius: 12
                anchors.verticalCenter: parent.verticalCenter

                MouseArea {
                    anchors.fill: parent
                    anchors.margins: -5 // Make MouseArea bigger than the rectangle, itself
                }
            }

            Rectangle {
                id: rect; x: 230; color: "#454545"
                border.color: colorRect; border.width: 2
                height: 46; width: 46; radius: 12
                anchors.verticalCenter: parent.verticalCenter

                Image {
                    id: icon
                    source: iconSource
                    width: 30
                    height: 30
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                }

                Text {
                    id: textLesson
                    text: setText

                    font.pixelSize: 16

                    anchors.verticalCenter: parent.verticalCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                }

                MouseArea {
                    onClicked: {
                        if(avtorPane.opacity == 0||slot3.state == "shiftslot3"){
                            if (rect.state == '') rect.state = "right"; else rect.state = ''

                            if(rect.state == "right"){
                                Qt_fun.readDBNameLesson(lessonTypes.get(index).name);
                                slot3.state = "shiftslot3";
                                removeItem(index);
                                timer.running = true;

                                flickable.contentHeight = layout.height+277;

                                textAll.font.bold = true;
                                textAll.color = "black";
                            }
                            else{
                                lessonTypes.clear();
                                lenguageLesson.setItemLesson();

                                textAll.font.bold = false;
                                textAll.color = "white";

                                avtorPane.opacity = 0;
                                flickable.contentHeight = layout.height+277;
                            }
                        }
                    }

                    anchors.fill: parent
                    anchors.margins: -5 // Make MouseArea bigger than the rectangle, itself
                }

                states : State {
                    name: "right"
                    PropertyChanges { target: rect; x: window.width - 240 - slot2.width; color: ballColor}
                }

                transitions: Transition {
                    NumberAnimation { properties: "x"; easing.type: type; duration: 1000 }
                    ColorAnimation { properties: "color"; easing.type: type; duration: 1000 }
                }
            }
        }
    }

    Flickable {
        id: flickable
        anchors.fill: parent
        contentHeight: layout.height+277

        Rectangle {
            id: titlePane

            gradient: Gradient {
                GradientStop { position: 0.0; color: "black"}
                GradientStop { position: 0.5; color: "#7f7f7f"}
                GradientStop { position: 1.0; color: "black"}
            }

            height: 50
            y: 100
            anchors { left: parent.left; right: parent.right }

            Text { text: "Выберите урок из доступных:"; anchors.centerIn: parent; color: "White" }
        }

        Rectangle {
            id: avtorPane

            gradient: Gradient {
                GradientStop { position: 0.0; color: "black"}
                GradientStop { position: 0.5; color: "#7f7f7f"}
                GradientStop { position: 1.0; color: "black"}
            }

            opacity: 0

            height: 53
            y: parent.height - 107 -avtorPane.height
            anchors {left: parent.left; right: parent.right }

            Text { id: avtorPaneText;  text: "Автор уроков: KeyGen"; anchors.centerIn: parent; color: "White" }
        }

        Column {
            id: layout
            anchors { top: titlePane.bottom; topMargin: 10; left: parent.left; right: parent.right }
            Repeater { model: lessonTypes; delegate: delegate }
        }
    }

    function removeItem(index) {

        var name = lessonTypes.get(index).name;

        for(var i = 0; i < lessonTypes.count;){

            if(lessonTypes.count == 1)
                break;

            if(lessonTypes.get(i).name != name){
                lessonTypes.remove(i);
            }
            else{
                i++;
            }
        }
    }
}

//Behavior on height { PropertyAnimation {duration: 1500; easing.type: type} }
