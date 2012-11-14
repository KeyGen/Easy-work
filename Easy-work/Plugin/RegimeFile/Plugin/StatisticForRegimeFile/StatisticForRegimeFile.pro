#-------------------------------------------------
#
# Project created by QtCreator 2012-11-12T09:05:55
#
#-------------------------------------------------

QT       += gui sql

TARGET = StatisticForRegimeFile
TEMPLATE = lib

DEFINES += STATISTICFORREGIMEFILE_LIBRARY

SOURCES += statisticforregimefile.cpp \
    slots.cpp

HEADERS += statisticforregimefile.h\
        StatisticForRegimeFile_global.h

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xEFF980A0
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = StatisticForRegimeFile.dll
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

DESTDIR = $$PWD/../../../../Easy-work/lib/EasyWork

FORMS += \
    statisticDialog.ui
