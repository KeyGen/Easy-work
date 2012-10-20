#-------------------------------------------------
#
# Project created by QtCreator 2012-10-20T10:05:29
#
#-------------------------------------------------

TARGET = keyboard
TEMPLATE = lib

DEFINES += KEYBOARD_LIBRARY

SOURCES += keyboard.cpp \
    installatiosPlugins.cpp

HEADERS += keyboard.h\
        keyboard_global.h

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xEBC3DE78
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = keyboard.dll
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

DESTDIR = $$PWD/../../../readyPlugins

INCLUDEPATH += $$PWD/../downloadLanguageKeyboard/

FORMS += \
    dialog.ui
