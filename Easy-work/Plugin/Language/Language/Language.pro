#-------------------------------------------------
#
# Project created by QtCreator 2013-01-22T15:06:37
#
#-------------------------------------------------

QT       += gui

TARGET = Language
TEMPLATE = lib

DEFINES += LANGUAGE_LIBRARY

SOURCES += language.cpp

HEADERS += language.h\
        Language_global.h

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
