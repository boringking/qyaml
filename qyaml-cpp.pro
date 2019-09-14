#-------------------------------------------------
#
# Project created by QtCreator 2016-09-02T10:51:50
#
#-------------------------------------------------

QT       += core gui

TEMPLATE = lib

DEFINES += QYAML_LIBRARY

CONFIG += c++11
CONFIG += staticlib
CONFIG += create_prl

QMAKE_STRIP = echo

include(qyaml-cpp.pri)

INCLUDE_PATH += /usr/local/include

unix: {
    CONFIG(release, debug|release): TARGET = qyaml-cpp
    CONFIG(debug, debug|release): TARGET = qyaml-cppd

    LIBS += -lyaml-cpp

    inc1.path = /home/simon/workspace/include/unix/qyaml-cpp
    inc1.files = $$HEADERS
    inc1.files += $$DISTFILES
    target.path = /home/simon/workspace/lib/unix
    INSTALLS += target inc1
}

win32:win64: {
    CONFIG(release, debug|release): TARGET = qyaml-cpp
    CONFIG(debug, debug|release): TARGET = qyaml-cppd

    LIBS += -L$$PWD/../../../../../opt/mxe/usr/x86_64-w64-mingw32.static/lib/ -lyaml-cpp

    inc1.path = /home/simon/workspace/include/mingw64/qyaml-cpp
    inc1.files = $$HEADERS
    inc1.files += $$DISTFILES
    target.path = /home/simon/workspace/lib/mingw64
    INSTALLS += target inc1
}
