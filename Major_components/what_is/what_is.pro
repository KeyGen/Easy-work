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

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
        DESTDIR = /home/keygen/Документы/Easy-work/plugins
    }
    INSTALLS += target
}

FORMS += \
    ui_whatIs.ui

RESOURCES += \
    file_what_is.qrc
