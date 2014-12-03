#-------------------------------------------------
#
# Project created by QtCreator 2014-07-15T19:40:52
#
#-------------------------------------------------
VERSION = 0.0.3.0
DEFINES += APP_VERSION=\\\"$$VERSION\\\"
DEFINES += BUILDTIME=\\\"$$system(date '+%H:%M:%S')\\\"
DEFINES += BUILDDATE=\\\"$$system(date '+%d.%m.%y')\\\"

QT       += core sql network #websockets

QT       -= gui

QMAKE_CXXFLAGS += -std=c++0x #turn on c++ 11 support

TARGET = SIMS_SERVER
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    panelcommpluginmanager.cpp \
    database/databasemanager.cpp \
    clientsnetwork/clnetserver.cpp \
    clientsnetwork/clnetsocket.cpp \
    logger/Logger.cpp \
    messagedispatcher.cpp \
    video/videomanager.cpp \
    video/remotedvr.cpp \
    video/videodata.cpp #\
#    clients_communication/websocketserver.cpp \
#    clients_communication/communicationprotocol.cpp \
#    clients_communication/clientscommandprocessor.cpp

HEADERS += \
    panelcomminterface.h \
    panelcommpluginmanager.h \
    database/databasemanager.h \
    clientsnetwork/cldataitem.h \
    clientsnetwork/clnetserver.h \
    clientsnetwork/clnetsocket.h \
    logger/Logger.h \
    messagedispatcher.h \
    video/videomanager.h \
    video/remotedvr.h \
    video/videodata.h #\
#    clients_communication/websocketserver.h \
#    clients_communication/communicationprotocol.h \
#    clients_communication/clientscommandprocessor.h

SUBDIRS += \
    MAIN.pro

unix:!macx: LIBS += -L$$PWD/camera_sdk/lib/ -lHHNet

INCLUDEPATH += $$PWD/camera_sdk/include
DEPENDPATH += $$PWD/camera_sdk/include

unix:!macx: PRE_TARGETDEPS += $$PWD/camera_sdk/lib/libHHNet.a
