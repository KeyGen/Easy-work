#-------------------------------------------------
#
# Project created by QtCreator 2012-12-07T12:32:36
#
#-------------------------------------------------

#QT       += gui core

QT       += gui declarative

TARGET = RegimeGame
TEMPLATE = lib

DEFINES += REGIMEGAME_LIBRARY

SOURCES += regimegame.cpp \
    savesettings.cpp

HEADERS += regimegame.h\
        RegimeGame_global.h

unix: {
    target.path = /usr/lib/EasyWork

    INSTALLS += target
}

DESTDIR = $$PWD/../../../Easy-work/lib/EasyWork

RESOURCES += \
    fileRegimeGame.qrc

OTHER_FILES += \
    mainGame.qml \
    СircleMain.qml \
    StartGame.qml \
    Game.qml \
    ShowWord.qml \
    ShowLavel.qml \
    ShowTimeGame.qml \
    ShowScore.qml

FORMS += \
    formGame.ui
