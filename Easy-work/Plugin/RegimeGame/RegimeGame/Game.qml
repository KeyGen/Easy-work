// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Rectangle {
    width: parent.width
    height: parent.height

    gradient: Gradient {
        GradientStop { position: 0.0; color: "#1e1e1e"}
        GradientStop { position: 0.5; color: "#828282"}
        GradientStop { position: 1.0; color: "#1e1e1e"}
    }

    Rectangle {
        id: info
        width: 200
        height: parent.height - 219

        y: 105
        x: parent.width - 415;
        color: "SeaGreen";
        smooth: true;
        radius: 10;

        border.color: black
        border.width: 2

        ShowWord{
            id: word
            height: info.height/4 - 9
            width: info.width-12

            border.color: "#1e1e1e"
            border.width: 1
        }

        ShowLavel{
            id: lavel

            height: word.height
            width: word.width
            y: word.y + word.height + 8
            x: word.x

            border.color: "#1e1e1e"
            border.width: 1
        }

        ShowTimeGame{
            id: time
            height: word.height
            width: word.width
            y: lavel.y + word.height + 8
            x: word.x

            border.color: "#1e1e1e"
            border.width: 1
        }

        ShowScore{
            id: score
            height: word.height
            width: word.width
            y: time.y + time.height + 8
            x: word.x

            border.color: "#1e1e1e"
            border.width: 1
        }
    }

    Rectangle {
        width: parent.width - 627;
        height: parent.height - 219;

        y: 105;
        x: 206;
        color: "SeaGreen";

        border.color: black
        border.width: 2

        smooth: true;
        radius: 10;

        Image {
            id: right
            source: ":/right"
            x: parent.width - right.width + 3
            y: -6

            smooth: true

            width: 20
            height: 20
        }

        Image {
            id: left
            source: ":/left"

            x: -2
            y: -6

            smooth: true

            width: 20
            height: 20
        }

        Image {
            id: circ
            source: ":/circ"

            x: 20
            y: -6

            smooth: true

            width: 50
            height: 50
        }
    }

    Timer {
        interval: 0; running: true;
        onTriggered: console.log(parent.height - 241)
    }
}
