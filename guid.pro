HEADERS = Guid.h qrcodegen/qrcodegen.hpp
SOURCES = Guid.cpp qrcodegen/qrcodegen.cpp
RESOURCES = guid.qrc
QT += dbus gui widgets
unix:!macx:QT += x11extras
TARGET = guid

APP_VERSION = $$system(git describe --tags --always --dirty 2>/dev/null)
DEFINES += APP_VERSION=\\\"$$APP_VERSION\\\"

unix:!macx:LIBS += -lX11
unix:!macx:DEFINES += WS_X11

win32:CONFIG += console
win64:CONFIG += console

target.path += /usr/bin
INSTALLS += target