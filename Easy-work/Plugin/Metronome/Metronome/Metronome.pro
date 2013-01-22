#-------------------------------------------------
#
# Project created by QtCreator 2013-01-22T13:58:14
#
#-------------------------------------------------

QT       -= gui

TARGET = Metronome
TEMPLATE = lib

DEFINES += METRONOME_LIBRARY

SOURCES += metronome.cpp

HEADERS += metronome.h\
        Metronome_global.h

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
