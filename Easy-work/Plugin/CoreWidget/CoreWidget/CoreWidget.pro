#-------------------------------------------------
#
# Project created by QtCreator 2012-10-25T16:20:35
#
#-------------------------------------------------

QT       += gui declarative sql

TARGET = CoreWidget
TEMPLATE = lib

DEFINES += COREWIDGET_LIBRARY

SOURCES += corewidget.cpp

HEADERS += corewidget.h\
        CoreWidget_global.h

DESTDIR = $$PWD/../../../Easy-work/lib/EasyWork

FORMS += \
    corewidget.ui

OTHER_FILES += \
    main.qml \
    PointerLeft.qml \
    PointerRight.qml

RESOURCES += \
    resource.qrc
