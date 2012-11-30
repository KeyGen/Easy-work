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
