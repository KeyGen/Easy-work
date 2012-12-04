#-------------------------------------------------
#
# Project created by QtCreator 2012-11-08T09:47:36
#
#-------------------------------------------------

QT       += gui

TARGET = SaveSetting
TEMPLATE = lib

DEFINES += SAVESETTING_LIBRARY

SOURCES += savesetting.cpp

HEADERS += savesetting.h\
        SaveSetting_global.h

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xEED1658D
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = SaveSetting.dll
    addFiles.path = !:/sys/bin
    DEPLOYMENT += addFiles
}

unix: {
    target.path = /usr/lib/EasyWork

    INSTALLS += target
}

DESTDIR = $$PWD/../../../Easy-work/lib/EasyWork
