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
                lessonTypes.insert(i, { "name": name, "type": Easing.OutBounce, "ballColor": "DarkRed"});
            }
        }
    }
}

