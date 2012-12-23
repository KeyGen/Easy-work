// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Rectangle {
    width: parent.width
    height: parent.height
    color: "green";

    Rectangle {
        id: info
        width: 200
        height: parent.height - 219

        y: 105
        x: parent.width - 415;
        color: "blue";
        smooth: true;
        radius: 10;

        ShowLavel{
            id: lavel
            height: info.height/4 - 9
            width: info.width-12
        }

        ShowWord{
            id: word
            height: lavel.height
            width: lavel.width
            y: lavel.y + lavel.height + 8
            x: lavel.x
        }

        ShowTimeGame{
            id: time
            height: lavel.height
            width: lavel.width
            y: word.y + word.height + 8
            x: lavel.x
        }

        ShowScore{
            id: score
            height: lavel.height
            width: lavel.width
            y: time.y + time.height + 8
            x: lavel.x
        }
    }

    Rectangle {
        width: parent.width - 627;
        height: parent.height - 219;

        y: 105;
        x: 206;
        color: "blue";
        smooth: true;
        radius: 10;
    }

    Timer {
        interval: 0; running: true;
        onTriggered: console.log(parent.height - 241)
    }
}
