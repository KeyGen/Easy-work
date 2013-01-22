#-------------------------------------------------
#
# Project created by QtCreator 2013-01-22T15:05:57
#
#-------------------------------------------------

QT       += gui

TARGET = Sound
TEMPLATE = lib

DEFINES += SOUND_LIBRARY

SOURCES += sound.cpp

HEADERS += sound.h\
        Sound_global.h

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xE5DC07A0
    TARGET.CAPABILITY =
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = Update.dll
    addFiles.path = !:/sys/bin
    DEPLOYMENT += addFiles
}

unix: {
    target.path = /usr/lib/EasyWork

    INSTALLS += target
}

DESTDIR = $$PWD/../../../Easy-work/lib/EasyWork
