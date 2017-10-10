#-------------------------------------------------
#
# Project created by QtCreator 2017-07-14T20:08:38
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = dblsqd-sdk-qt
TEMPLATE = lib

SOURCES += \
    $$PWD/release.cpp \
    $$PWD/semver.cpp \
    $$PWD/update_dialog.cpp \
    $$PWD/feed.cpp

HEADERS  += \
    $$PWD/release.h \
    $$PWD/semver.h \
    $$PWD/update_dialog.h \
    $$PWD/feed.h

FORMS    += \
    $$PWD/update_dialog.ui

VERSION = 0.1.0

DISTFILES += \
    $$PWD/README.md \
    $$PWD/LICENSE \
    $$PWD/Doxyfile
