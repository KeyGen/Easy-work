// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Item {

    function setItemLesson(count) {
        var name = "test";
        var j = 0;
        for(var i = count; name != ""; i++,j++){
            name = Qt_fun.getNameLesson(j);
            if(name !=""){
                lessonTypes.insert(i, { "name": name,
                                       "colorRect": "white",
                                       "ballColor": "DarkRed",
                                       "colorBorderRect" : "Turquoise",
                                       "setText" : "N"});
            }
        }

        var autor = Qt_fun.getAutorName();
        avtorPaneText.text = autor;
    }
}
