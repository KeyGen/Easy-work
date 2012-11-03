#-------------------------------------------------
#
# Project created by QtCreator 2012-11-01T20:24:31
#
#-------------------------------------------------

QT       += gui

TARGET = Style
TEMPLATE = lib

DEFINES += STYLE_LIBRARY

SOURCES += style.cpp

HEADERS += style.h\
        Style_global.h

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xE79E0364
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = Style.dll
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

INCLUDEPATH += $$PWD/../../qzip/

DESTDIR = $$PWD/../../../Easy-work/Plugins

RESOURCES += \
    standartStyle.qrc
