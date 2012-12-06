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

Item {

    Timer {
        objectName: "setItemLanguageLessonF";
        interval: 0;
        onTriggered: setItemLesson();
    }

    function setItemLesson() {
        var name = "test";
        for(var i = 0; name != ""; i++){
            name = Qt_fun.getLanguageLesson(i);
            if(name !=""){
                lessonTypes.insert(i, { "name": name, "type": Easing.OutBounce,
                                       "colorRect": "Turquoise",
                                       "ballColor": "#2a3d6a",
                                       "colorBorderRect" : "black",
                                       "iconSource" : ":/hand",
                                       "stateLesson" : "",
                                       "setText" : ""});
            }
        }
    }
}

