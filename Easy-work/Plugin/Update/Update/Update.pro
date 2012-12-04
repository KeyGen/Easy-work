#-------------------------------------------------
#
# Project created by QtCreator 2012-11-17T10:03:05
#
#-------------------------------------------------

QT       += gui network

TARGET = Update
TEMPLATE = lib

DEFINES += UPDATE_LIBRARY

SOURCES += update.cpp \
    savesettings.cpp

HEADERS += update.h\
        Update_global.h

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xE5DC07A0
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = Update.dll
    addFiles.path = !:/sys/bin
    DEPLOYMENT += addFiles
}

unix: {
    target.path = /usr/lib/EasyWork

    INSTALLS += target
}

DESTDIR = $$PWD/../../../Easy-work/lib/EasyWork

FORMS += \
    update_dialog.ui
