#-------------------------------------------------
#
# Project created by QtCreator 2012-10-26T09:48:28
#
#-------------------------------------------------

TARGET = RegimeFile
TEMPLATE = lib

DEFINES += REGIMEFILE_LIBRARY

SOURCES += regimefile.cpp \
    installationPlugins.cpp

HEADERS += regimefile.h\
        RegimeFile_global.h

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xE2DF4087
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = RegimeFile.dll
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

INCLUDEPATH += $$PWD/../OpenFile/

DESTDIR = $$PWD/../../../readyPlugins

FORMS += \
    regimefile.ui \
    infoPrint.ui
