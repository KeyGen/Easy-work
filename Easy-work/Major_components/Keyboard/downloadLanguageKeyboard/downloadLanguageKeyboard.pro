#-------------------------------------------------
#
# Project created by QtCreator 2012-10-20T19:37:30
#
#-------------------------------------------------

QT       += gui

TARGET = downloadLanguageKeyboard
TEMPLATE = lib

DEFINES += DOWNLOADLANGUAGEKEYBOARD_LIBRARY

SOURCES += downloadlanguagekeyboard.cpp

HEADERS += downloadlanguagekeyboard.h\
        downloadLanguageKeyboard_global.h

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xED26F443
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = downloadLanguageKeyboard.dll
    addFiles.path = !:/sys/bin
    DEPLOYMENT += addFiles
}

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

DESTDIR = $$PWD/../../../readyPluginsForKeyboard
