#-------------------------------------------------
#
# Project created by QtCreator 2012-10-26T16:26:06
#
#-------------------------------------------------

TARGET = OpenFile
TEMPLATE = lib

DEFINES += OPENFILE_LIBRARY

SOURCES += openfile.cpp

HEADERS += openfile.h\
        OpenFile_global.h

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xE5809F5F
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = OpenFile.dll
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

DESTDIR = $$PWD/../../../Easy-work/Plugins

FORMS += openfile.ui
