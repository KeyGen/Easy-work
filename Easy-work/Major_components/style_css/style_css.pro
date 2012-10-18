#-------------------------------------------------
#
# Project created by QtCreator 2012-10-18T21:02:43
#
#-------------------------------------------------

QT       += gui

TARGET = style_css
TEMPLATE = lib

DEFINES += STYLE_CSS_LIBRARY

SOURCES += style_css.cpp

HEADERS += style_css.h\
        style_css_global.h

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xEFF19466
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = style_css.dll
    addFiles.path = !:/sys/bin
    DEPLOYMENT += addFiles
}

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
        DESTDIR = $$PWD/../../readyPlugins
    }
    INSTALLS += target
}