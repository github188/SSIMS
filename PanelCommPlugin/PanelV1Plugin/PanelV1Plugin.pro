#-------------------------------------------------
#
# Project created by QtCreator 2014-07-16T21:22:55
#
#-------------------------------------------------

QT       += network xml xmlpatterns

QT       -= gui

TARGET = PanelV1Plugin
TEMPLATE = lib

DEFINES += PANELV1PLUGIN_LIBRARY

SOURCES += panelv1plugin.cpp

HEADERS += panelv1plugin.h\
        panelv1plugin_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
