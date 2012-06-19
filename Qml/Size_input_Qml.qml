// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Item {
    id: my_item

    width: parent.width
    height: parent.height

    Image {
        id: input_size //Имя кнопки
        source: ":/picture/active_size"

        width: parent.width/52.4
        height: parent.height/22.7

        scale: input_sizeMouse.pressed ? 0.8 : 1.0
        smooth: true

        x: my_item.width - 75
        y: 5

        // Меняем размеры для появления на экране item_input_size_view
        MouseArea {
            id: input_sizeMouse
            anchors.fill: parent
            anchors.margins: -10
            acceptedButtons: Qt.LeftButton
            onClicked:
            {
                item_input_size_view.x = 0
                item_input_size_view.width = my_item.width
                item_input_size_view.height = my_item.height

                input_size_view_3.width = item_input_size_view.width/9
                input_size_view_3.height = item_input_size_view.height/4

                input_size_view_4.width = item_input_size_view.width/9
                input_size_view_4.height = item_input_size_view.height/4

                quit_input_size_view.width = 20
                quit_input_size_view.height = 20
            }
        }
    }

    Item{
        id: item_input_size_view //Имя кнопки
        width: 0
        height: 0

        Image {
            id: input_size_view //Имя кнопки
            //source: ":/picture/sizeinput"

             width: item_input_size_view.width+1
             height: item_input_size_view.height+1

             Rectangle{
                 id: input_size_view_2 //Имя кнопки

                 //Цвет - градиент
                 gradient: Gradient {
                     GradientStop { position: 0.0; color: "#8B2500" }
                     GradientStop { position: 0.5; color: "#FF4500" }
                     GradientStop { position: 0.5; color: "#FF4500" }
                     GradientStop { position: 1.0; color: "#8B2500" }
                 }

                 // Закругление углов
                 radius: 10
                 // Сглаживание
                 smooth: true

                 //Размещаем в центре
                 anchors.horizontalCenter: input_size_view.horizontalCenter
                 anchors.verticalCenter: input_size_view.verticalCenter

                 width: input_size_view.width/5; height: input_size_view.height/1.2

                 Image {
                     id: quit_input_size_view //Имя кнопки
                     source: ":/picture/quit"

                     width: 0
                     height: 0

                     x: input_size_view_2.width-26
                     y: 5

                     scale: quit_input_size_viewMouse.pressed ? 0.8 : 1.0
                     smooth: quit_input_size_viewMouse.pressed

                     // Меняем размеры для сокрытия item_input_size_view
                     MouseArea {
                         id: quit_input_size_viewMouse
                         anchors.fill: parent
                         acceptedButtons: Qt.LeftButton
                         onClicked:
                         {
                             item_input_size_view.x = -10

                             item_input_size_view.width = 1
                             item_input_size_view.height = 1

                             input_size_view_3.width = 1
                             input_size_view_3.height = 1

                             input_size_view_4.width = 1
                             input_size_view_4.height = 1

                             quit_input_size_view.width = 1
                             quit_input_size_view.height = 1

                         }
                     }
                 }

                 Image {
                     id: input_size_view_3
                     source: ":/picture/plus"

                     //Размещаем в центре по горизонтали
                     anchors.horizontalCenter: input_size_view_2.horizontalCenter
                     y: input_size_view_2.height/7

                     width: 0; height: 0

                     scale: input_size_view_3Mouse.pressed ? 0.8 : 1.0
                     smooth: true

                     MouseArea {
                         id: input_size_view_3Mouse
                         anchors.fill: parent

                         onPressAndHold: Qt_fun.timer_size_enhance()
                         onReleased: Qt_fun.timer_stop_size_enhance()
                         onClicked:
                         {
                             Qt_fun.size_enhance()

                             item_input_size_view.x = 0
                             item_input_size_view.width = main.width
                             item_input_size_view.height = main.height

                             input_size_view_3.width = item_input_size_view.width/9
                             input_size_view_3.height = item_input_size_view.height/4

                             input_size_view_4.width = item_input_size_view.width/9
                             input_size_view_4.height = item_input_size_view.height/4

                             quit_input_size_view.width = 20
                             quit_input_size_view.height = 20
                        }
                     }
                 }

                 Image {
                     id: input_size_view_4
                     source: ":/picture/minus"

                     //Размещаем в центре
                     anchors.horizontalCenter: input_size_view_2.horizontalCenter
                     y: input_size_view_2.height/1.8

                     width: 0; height: 0

                     scale: input_size_view_4Mouse.pressed ? 0.8 : 1.0
                     smooth: true

                     MouseArea {
                         id: input_size_view_4Mouse
                         anchors.fill: parent

                         onPressAndHold: Qt_fun.timer_size_decreasing()
                         onReleased: Qt_fun.timer_stop_size_decreasing()

                         onClicked:
                         {
                             Qt_fun.size_decreasing()

                             item_input_size_view.x = 0
                             item_input_size_view.width = my_item.width
                             item_input_size_view.height = my_item.height

                             input_size_view_3.width = item_input_size_view.width/9
                             input_size_view_3.height = item_input_size_view.height/4

                             input_size_view_4.width = item_input_size_view.width/9
                             input_size_view_4.height = item_input_size_view.height/4

                             quit_input_size_view.width = 20
                             quit_input_size_view.height = 20

                         }
                     }
                }
            }
        }
    }
}
