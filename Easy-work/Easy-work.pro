TEMPLATE = subdirs

SUBDIRS += \
    Core \
    Plugin

QMAKE_CLEAN += Makefile.Debug Makefile.Release
