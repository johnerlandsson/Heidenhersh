#-------------------------------------------------
#
# Project created by QtCreator 2014-04-17T01:23:41
#
#-------------------------------------------------

QT       += core gui

CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QHeidenhersh
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

LIBS += -L../libHeidenhersh -lHeidenhersh

INCLUDEPATH += ../libHeidenhersh/src
