#-------------------------------------------------
#
# Project created by QtCreator 2012-06-15T10:27:18
#
#-------------------------------------------------

QT       += core gui declarative

TARGET = keyboard
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

OTHER_FILES += \
    Qml/Main_Qml.qml \
    Qml/Exit_Qml.qml \
    Qml/Button_Qml.qml \
    Qml/Size_input_Qml.qml \
    Qml/Move_Qml.qml

RESOURCES += \
    Resource_Qml.qrc
