// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Rectangle {
    id: startGame

    state: "normal"

    states: [
        State {
            name: "normal"
            PropertyChanges {target: startGame;
                opacity: 1.0
                width: parent.width; height: parent.height;
            }
        },
        State {
            name: "shift"
            PropertyChanges {target: startGame;
                opacity: 0.0
                width: 0
                height: 0;
            }
        }
    ]

    transitions: Transition {
        PropertyAnimation { properties: "width"; duration: 1500; easing.type: Easing.InOutSine }
        PropertyAnimation { properties: "height"; duration: 1500; easing.type: Easing.InBack }
        PropertyAnimation { properties: "opacity"; duration: 1500; easing.type: Easing.InOutSine }
    }

    СircleMain{ width: 230; height: 230; x: 100; y: 0;}
    СircleMain{ width: 70; height: 70; x: 350; anchors.verticalCenter: parent.verticalCenter; color: "yellow"}
    СircleMain{ width: 50; height: 50; anchors.horizontalCenter: parent.horizontalCenter; y: 110; color: "red"}
    СircleMain{ width: 200; height: 200; x: parent.width-330; y: 0; color: "black"}
    СircleMain{ width: 300; height: 300; x: parent.width-350; y: parent.height-250; color: "blue"}

    Rectangle{
        id: button
        width: 190
        height: 30

        y: parent.height - 145;
        anchors.horizontalCenter: parent.horizontalCenter;

        gradient: Gradient {
            GradientStop { position: 0.0; color: "#4c0000"}
            GradientStop { position: 0.5; color: "#df8c73"}
            GradientStop { position: 1.0; color: "#4c0000"}
        }

        smooth: true
        radius: 10
        border.width: 2
        border.color: "black"

        Text {
            id: textButton
            text: "Новая игра"
            font.pixelSize: 16
            color: "black"

            anchors.verticalCenter: button.verticalCenter
            anchors.horizontalCenter: button.horizontalCenter
        }

        scale: buttonMouse.pressed? 0.8 : 1.0

        MouseArea {
            id: buttonMouse
            anchors.fill: parent
            onClicked:
            {
                console.log("New Game")
                startGame.state = "shift";
            }
        }
    }

    Text {

        id: textMain
        text:
            "<center>
            <span style=\" font-size:16pt;\"><p align=\"right\">Easy work</p></span>
            <span style=\" font-size:6pt;\">&#32;<br></span>
            <span style=\" font-size:50pt;\"><b>Game</b></span>
            </center>"

        y: parent.height/2-55
        x: parent.width/2-textMain.width + 90
    }
}
