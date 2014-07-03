#-------------------------------------------------
#
# Project created by QtCreator 2014-06-22T02:15:50
#
#-------------------------------------------------

QT       += core gui

TARGET = litescreengui
TEMPLATE = app


SOURCES += main.cpp\
        litescreengui.cpp \
    ../gen-cpp/servernode.cpp \
    ../gen-cpp/node.cpp \
    ../gen-cpp/lz4.cpp \
    ../gen-cpp/litescreen_types.cpp \
    ../gen-cpp/litescreen_constants.cpp \
    ../gen-cpp/litescreen.cpp \
    ../gen-cpp/clientnode.cpp

HEADERS  += litescreengui.h \
    ../gen-cpp/servernode.h \
    ../gen-cpp/node.h \
    ../gen-cpp/lz4.h \
    ../gen-cpp/litescreen_types.h \
    ../gen-cpp/litescreen_constants.h \
    ../gen-cpp/litescreen.h \
    ../gen-cpp/clientnode.h

FORMS    += litescreengui.ui
