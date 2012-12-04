#-------------------------------------------------
#
# Project created by QtCreator 2012-10-16T22:49:57
#
#-------------------------------------------------

QT       +=  gui

TARGET = what_is
TEMPLATE = lib

DEFINES += WHAT_IS_LIBRARY

SOURCES += what_is.cpp

HEADERS += what_is.h\
        what_is_global.h

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xE14E423D
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = what_is.dll
    addFiles.path = !:/sys/bin
    DEPLOYMENT += addFiles
}

unix: {
    target.path = /usr/lib/EasyWork

    INSTALLS += target
}

DESTDIR = $$PWD/../../Easy-work/lib/EasyWork

FORMS += \
    ui_whatIs.ui

RESOURCES += \
    file_what_is.qrc
