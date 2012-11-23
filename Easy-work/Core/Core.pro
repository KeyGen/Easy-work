#-------------------------------------------------
#
# Project created by QtCreator 2012-10-25T16:19:09
#
#-------------------------------------------------

QT       += core gui

TARGET = Easy_work
TEMPLATE = app


SOURCES += main.cpp\
        core.cpp \
    installationsPlugins.cpp \
    savesettings.cpp

HEADERS  += core.h

INCLUDEPATH += $$PWD/../Plugin/RegimeLesson/RegimeLesson/
INCLUDEPATH += $$PWD/../Plugin/SaveSetting/SaveSetting/
INCLUDEPATH += $$PWD/../Plugin/CoreWidget/CoreWidget/
INCLUDEPATH += $$PWD/../Plugin/RegimeFile/RegimeFile/
INCLUDEPATH += $$PWD/../Plugin/Keyboard/Keyboard/
INCLUDEPATH += $$PWD/../Plugin/Update/Update/
INCLUDEPATH += $$PWD/../Plugin/Style/Style/
INCLUDEPATH += $$PWD/../Plugin/what_is/

DESTDIR = $$PWD/../Easy-work/bin

unix: {
    target.path = /usr/bin

    INSTALLS += target
}
