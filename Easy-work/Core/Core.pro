#-------------------------------------------------
#
# Project created by QtCreator 2012-10-25T16:19:09
#
#-------------------------------------------------

QT       += core gui

TARGET = Core
TEMPLATE = app


SOURCES += main.cpp\
        core.cpp \
    installationsPlugins.cpp

HEADERS  += core.h

INCLUDEPATH += $$PWD/../Plugin/CoreWidget/CoreWidget/
INCLUDEPATH += $$PWD/../Plugin/RegimeFile/RegimeFile/
INCLUDEPATH += $$PWD/../Plugin/Keyboard/Keyboard/
