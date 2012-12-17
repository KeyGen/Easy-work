// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Rectangle {
    width: parent.width
    height: parent.height
    color: "green";

    Rectangle {
        width: 200
        height: parent.height - 219

        y: 105
        x: parent.width - 415;
        color: "blue";
    }
}
