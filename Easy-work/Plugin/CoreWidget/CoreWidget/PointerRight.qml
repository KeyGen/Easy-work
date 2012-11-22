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
    id: pointerRight

    width: 20
    height: 20

    y: parent.height/2 - pointerRight.height+8
    x: parent.width - pointerRight.width - 4

    radius: 40
    smooth: true

    scale: mousePointerRight.pressed? 0.8 : 1.0

    Text {
        text: ">"
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
    }

    MouseArea {
        id: mousePointerRight
        anchors.fill: parent

        onClicked: {
            if(main.state == "shift")
                main.state="normal";
            else
                main.state ="shift";

            Qt_fun.followingText();
            Qt_fun.setStopChangeText();
        }
    }
}
