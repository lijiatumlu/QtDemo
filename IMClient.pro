#-------------------------------------------------
#
# Project created by QtCreator 2016-02-17T10:25:47
#
#-------------------------------------------------

QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = IMServer
TEMPLATE = app

INCLUDEPATH += $$PWD/include
include(wlogin/wlogin.pri)
include(wchat/wchat.pri)
include(wmood/wmood.pri)

include(common/common.pri)
include(network/network.pri)
include(protocol/protocol.pri)


SOURCES += main.cpp \
    logiclayer.cpp

HEADERS += \
    logiclayer.h
