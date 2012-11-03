#-------------------------------------------------
#
# Project created by QtCreator 2012-10-27T19:03:03
#
#-------------------------------------------------

#QT       -= gui

TARGET = FindKeyboardLayout
TEMPLATE = lib

DEFINES += FINDKEYBOARDLAYOUT_LIBRARY

SOURCES += findkeyboardlayout.cpp

HEADERS += findkeyboardlayout.h\
        FindKeyboardLayout_global.h

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xE72EAB80
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = FindKeyboardLayout.dll
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

DESTDIR = $$PWD/../../../../Easy-work/Plugins/PluginsKeyboard

INCLUDEPATH += $$PWD/../../../qzip/

RESOURCES += \
    standartLanguage.qrc
