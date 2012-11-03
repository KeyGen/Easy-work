#-------------------------------------------------
#
# Project created by QtCreator 2012-10-25T16:20:35
#
#-------------------------------------------------

QT       += gui

TARGET = CoreWidget
TEMPLATE = lib

DEFINES += COREWIDGET_LIBRARY

SOURCES += corewidget.cpp

HEADERS += corewidget.h\
        CoreWidget_global.h

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xECEF991B
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = CoreWidget.dll
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

FORMS += \
    corewidget.ui
