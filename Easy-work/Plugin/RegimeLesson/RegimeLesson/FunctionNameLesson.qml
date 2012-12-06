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

    function setItemLesson(count) {
        var name = "test";
        var j = 0;
        for(var i = count; name != ""; i++,j++){
            name = Qt_fun.getNameLesson(j);
            if(name !=""){
                var lessonAssessment = Qt_fun.getLessonAssessment(name);

                var backgroubdColorLessonRect;
                if(lessonAssessment == 1){
                    backgroubdColorLessonRect ="DarkRed"
                }
                else if(lessonAssessment == 2){
                    backgroubdColorLessonRect ="Purple"
                }
                else if(lessonAssessment == 3){
                    backgroubdColorLessonRect ="Teal"
                }
                else if(lessonAssessment == 4){
                    backgroubdColorLessonRect ="MidnightBlue"
                }
                else if(lessonAssessment == 5){
                    backgroubdColorLessonRect ="DarkGreen"
                }

                if(!lessonAssessment>0){
                lessonTypes.insert(i, { "name": name,
                                       "colorRect": "white",
                                       "ballColor": "DarkRed",
                                       "colorBorderRect" : "Turquoise",
                                       "iconSource" : ":/point",
                                       "stateLesson" : "",
                                       "setText" : "N"});
                }
                else{
                    lessonTypes.insert(i, { "name": name,
                                           "colorRect": "white",
                                           "ballColor": backgroubdColorLessonRect,
                                           "colorBorderRect" : "Turquoise",
                                           "iconSource" : ":/point",
                                           "stateLesson" : "right",
                                           "setText" : lessonAssessment});
                }
            }
        }

        var autor = Qt_fun.getAutorName();
        avtorPaneText.text = autor;
    }
}
