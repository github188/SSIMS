#-------------------------------------------------
#
# Project created by QtCreator 2014-07-16T21:55:24
#
#-------------------------------------------------

QT       += network xml xmlpatterns

QT       -= gui

TARGET = $$qtLibraryTarget(PanelCommPluginV1)
TEMPLATE = lib
CONFIG += plugin
DEFINES += PANELCOMMPLUGINV1_LIBRARY
DESTDIR         = ../SIMS_SERVER/panel_comm_plugins
SOURCES += panelcommpluginv1.cpp \
    network/networkserver.cpp \
    network/networksocket.cpp

HEADERS += panelcommpluginv1.h\
        panelcommpluginv1_global.h \
    network/networkclientitem.h \
    network/networkserver.h \
    network/networksocket.h

#unix {
#    target.path =  #/usr/lib
#    INSTALLS += target
#}
