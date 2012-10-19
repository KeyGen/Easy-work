#-------------------------------------------------
#
# Project created by QtCreator 2012-10-19T16:32:00
#
#-------------------------------------------------

TARGET = regime_outward_file
TEMPLATE = lib

DEFINES += REGIME_OUTWARD_FILE_LIBRARY

SOURCES += regime_outward_file.cpp

HEADERS += regime_outward_file.h\
        regime_outward_file_global.h

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xE6D606E7
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = regime_outward_file.dll
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

DESTDIR = $$PWD/../../readyPlugins

FORMS += \
    outward_file.ui
