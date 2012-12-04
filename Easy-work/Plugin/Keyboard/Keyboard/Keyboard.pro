#-------------------------------------------------
#
# Project created by QtCreator 2012-10-26T20:31:09
#
#-------------------------------------------------

TARGET = Keyboard
TEMPLATE = lib

DEFINES += KEYBOARD_LIBRARY

QT       += core

SOURCES += keyboard.cpp \
    slots.cpp \
    installatiosPlugins.cpp \
    systemWindowsLinux.cpp \
    savesettings.cpp

HEADERS += keyboard.h\
        Keyboard_global.h

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xE3043CFC
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = Keyboard.dll
    addFiles.path = !:/sys/bin
    DEPLOYMENT += addFiles
}

unix: {
    target.path = /usr/lib/EasyWork

    INSTALLS += target
}

DESTDIR = $$PWD/../../../Easy-work/lib/EasyWork

INCLUDEPATH += $$PWD/../Plugin/FindKeyboardLayout/

FORMS += \
    keyboard.ui
