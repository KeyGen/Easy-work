#-------------------------------------------------
#
# Project created by QtCreator 2012-11-23T11:21:30
#
#-------------------------------------------------
QT       += gui sql declarative

TARGET = RegimeLesson
TEMPLATE = lib

DEFINES += REGIMELESSON_LIBRARY

SOURCES += regimelesson.cpp \
    savesettings.cpp \
    database.cpp

HEADERS += regimelesson.h\
        RegimeLesson_global.h \
    database.h

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xEF32C76C
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = RegimeLesson.dll
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

DESTDIR = $$PWD/../../../Easy-work/lib/EasyWork

RESOURCES += \
    icon.qrc

FORMS += \
    regimeLesson.ui

OTHER_FILES += \
    main.qml \
    FunctionLanguageLesson.qml \
    FunctionNameLesson.qml
