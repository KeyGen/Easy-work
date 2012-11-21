/**
 * Easy work - краткое описание на английском
 * Copyright (C) 2012 KeyGen <KeyGenQt@gmail.com>
 * https://github.com/KeyGen/Easy-work/wiki
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 */


// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Rectangle {
    id: main

    x: -200
    y: -100

    gradient: Gradient {
        GradientStop { position: 0.0; color: "#696969"}
        GradientStop { position: 0.5; color: "#dcdcdc"}
        GradientStop { position: 1.0; color: "#696969"}
    }

    state: "normal"

    states: [
        State {
            name: "normal"
            PropertyChanges {target: one;
                opacity: 1.0
                width: (parent.width-200)-60;
                height: (parent.height-200)-20;
            }
            PropertyChanges {target: two;
                opacity: 0
                width: 0
                height: 0
            }
        },
        State {
            name: "shift"
            PropertyChanges {target: two;
                opacity: 1.0
                width: (parent.width-200)-60;
                height: (parent.height-200)-20;
            }
            PropertyChanges {target: one;
                opacity: 0
                width: 0
                height: 0
            }
        }
    ]

    transitions: Transition {
        PropertyAnimation { properties: "width"; duration: 500; easing.type: Easing.InOutSine }
        PropertyAnimation { properties: "height"; duration: 500; easing.type: Easing.InBack }
        PropertyAnimation { properties: "opacity"; duration: 500; easing.type: Easing.InOutSine }
    }

    Rectangle {
        id: one
        objectName: "qmlOne"

        x: (parent.width+200)/2 - one.width/2
        y: parent.height/2 - one.height/2

        color: "green"

        smooth: true
        radius: 10
        border.color: "black"

        Text {
            id: objectTextOneContents
            objectName: "objectTextOneContents"
            text: "<b>Добро пожаловать в программу Easy work</b>"
            font.pixelSize: parent.width/26
            font.bold: true
        }

        Text {
            id: objectTextOneText
            objectName: "objectTextOneText"
            text: "<b>Добро пожаловать в программу Easy work</b>"
            font.pixelSize: parent.width/26
        }

        Image {
            id: imageOne
            objectName: "imageOne"
            smooth: true
        }
    }

    Rectangle {
        id: two
        objectName: "qmlTwo"

        x: (parent.width+200)/2 - two.width/2
        y: parent.height/2 - two.height/2

        color: "white"

        smooth: true
        radius: 10
        border.color: "black"

        Text {
            id: objectTextTwo
            objectName: "objectTextOne"
            text: "Добро пожаловать в программу Easy work!"
            font.pixelSize: parent.width/25
            font.bold: true

            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }

    PointerLeft{}
    PointerRight{}
}
