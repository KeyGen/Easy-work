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
INCLUDEPATH += $$PWD/../Plugin/RegimeGame/RegimeGame/
INCLUDEPATH += $$PWD/../Plugin/Keyboard/Keyboard/
INCLUDEPATH += $$PWD/../Plugin/Update/Update/
INCLUDEPATH += $$PWD/../Plugin/Style/Style/
INCLUDEPATH += $$PWD/../Plugin/what_is/

DESTDIR = $$PWD/../Easy-work/bin

unix: {
    target.path = /usr/bin
    target.files = $$PWD/../Easy-work/bin/*

    documentation.path = /usr/share/
    documentation.files = ../Easy-work/share/*

    INSTALLS += target documentation
}

#unix{
# isEmpty(PREFIX) {
#   PREFIX = /usr
# }

#BINDIR = $$PREFIX/bin
#DATADIR = $$PREFIX/share
#LOCALEDIR = $$DATADIR/locale
#SHAREDIR = $$DATADIR/$${TARGET}

# contains(QMAKE_HOST.arch, x86_64) {
#    DEFINES += XNEUR_PLUGIN_DIR=\\\"/usr/lib/xneur\\\"
# }
# else {
#    DEFINES += XNEUR_PLUGIN_DIR=\\\"/usr/lib/xneur\\\"
# }

#DEFINES += COUNTRY_FLAGS=\\\"$${SHAREDIR}/pixmaps\\\" SHAREDIR=\\\"$${SHAREDIR}\\\"

#INSTALLS =  target \
#            flags \
#            iconsvg \
#            desktop \
#            translate \
#            icon_x16 \
#            icon_x22 \
#            icon_x24 \
#            icon_x32 \
#            icon_x48

#target.path    = $${BINDIR}

#flags.files  += pixmaps/png/*
#flags.path  = $${SHAREDIR}/pixmaps

#iconsvg.path = $$DATADIR/icons/hicolor/scalable/apps
#iconsvg.files += pixmaps/scalable/*

#desktop.path = $$DATADIR/applications
#desktop.files += ../kdeneur.desktop

#translate.path = $$DATADIR/i18n
#translate.files += i18n/*.qm

#icon_x16.path = $$DATADIR/icons/hicolor/16x16/apps
#icon_x16.files += pixmaps/x16/*

#icon_x22.path = $$DATADIR/icons/hicolor/22x22/apps
#icon_x22.files += pixmaps/x22/*

#icon_x24.path = $$DATADIR/icons/hicolor/24x24/apps
#icon_x24.files += pixmaps/x24/*

#icon_x32.path = $$DATADIR/icons/hicolor/32x32/apps
#icon_x32.files += pixmaps/x32/*

#icon_x48.path = $$DATADIR/icons/hicolor/48x48/apps
#icon_x48.files += pixmaps/x48/*

#}
