#-------------------------------------------------
#
# Project created by QtCreator 2016-09-19T22:25:56
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET          = comtool
TEMPLATE        = app
MOC_DIR         = temp/moc
RCC_DIR         = temp/rcc
UI_DIR          = temp/ui
OBJECTS_DIR     = temp/obj
DESTDIR         = bin
win32:RC_FILE   = other/main.rc

SOURCES         += main.cpp
HEADERS         += head.h
RESOURCES       += other/main.qrc
CONFIG          += warn_off

include         ($$PWD/api/api.pri)
include         ($$PWD/form/form.pri)
include         ($$PWD/qextserialport/qextserialport.pri)

INCLUDEPATH     += $$PWD
INCLUDEPATH     += $$PWD/api
INCLUDEPATH     += $$PWD/form
INCLUDEPATH     += $$PWD/qextserialport
