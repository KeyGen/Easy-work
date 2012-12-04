#-------------------------------------------------
#
# Project created by QtCreator 2012-11-01T20:24:31
#
#-------------------------------------------------

QT       += gui

TARGET = Style
TEMPLATE = lib

DEFINES += STYLE_LIBRARY

SOURCES += style.cpp \
    savesettings.cpp

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

unix: {
    target.path = /usr/lib/EasyWork

    INSTALLS += target
}

INCLUDEPATH += $$PWD/../../qzip/

DESTDIR = $$PWD/../../../Easy-work/lib/EasyWork

RESOURCES += \
    standartStyle.qrc
