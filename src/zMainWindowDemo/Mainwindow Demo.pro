#-------------------------------------------------
#
# Project created by QtCreator 2014-08-15T14:34:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QUI
TEMPLATE = app


SOURCES += main.cpp\
        frmmain.cpp \
    frmmessagebox.cpp \
    frameless_helper.cpp

HEADERS  += frmmain.h \
    frmmessagebox.h \
    commonhelper.h \
    frameless_helper.h

FORMS    += frmmain.ui \
    frmmessagebox.ui


MOC_DIR=temp/moc
RCC_DIR=temp/rcc
UI_DIR=temp/ui
OBJECTS_DIR=temp/obj
DESTDIR=bin


RESOURCES += \
    resource.qrc
