#-------------------------------------------------
#
# Project created by QtCreator 2012-10-16T22:44:09
#
#-------------------------------------------------

QT       -= gui

TARGET = style
TEMPLATE = lib

DEFINES += STYLE_LIBRARY

SOURCES += style.cpp

HEADERS += style.h\
        style_global.h

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xE407FCBF
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = style.dll
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
