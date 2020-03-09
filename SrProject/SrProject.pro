#-------------------------------------------------
#
# Project created by QtCreator 2019-10-14T23:52:48
#
#-------------------------------------------------

QT       += core gui network widgets sql multimedia

TARGET = SrProject
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++17

SOURCES += \
        client.cpp \
        collabeditor.cpp \
        connection.cpp \
        highlighter.cpp \
        login.cpp \
        main.cpp \
        mainwindow.cpp \
        peermanager.cpp \
        server.cpp \
        udpreceiver.cpp \
        udpsender.cpp

HEADERS += \
        client.h \
        collabeditor.h \
        connection.h \
        highlighter.h \
        login.h \
        mainwindow.h \
        peermanager.h \
        server.h \
        udpreceiver.h \
        udpsender.h

FORMS += \
        collabeditor.ui \
        login.ui \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
