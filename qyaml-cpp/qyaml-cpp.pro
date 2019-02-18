#-------------------------------------------------
#
# Project created by QtCreator 2016-09-02T10:51:50
#
#-------------------------------------------------

QT       += gui

TARGET = qyaml-cpp
TEMPLATE = lib

DEFINES += QYAML_LIBRARY

#CONFIG += debug_and_release_target
#CONFIG += static # static library
CONFIG += c++11 # C++11 is the newest standard

#DESTDIR = ../../build/qyaml

CONFIG(debug, debug|release) {
    TARGET = qyaml-cppd
    OBJECTS_DIR = $$OUT_PWD/.objd
    MOC_DIR = $$OUT_PWD/.mocd
    RCC_DIR = $$OUT_PWD/.qrcd
    UI_DIR = $$OUT_PWD/.uid
}

CONFIG(release, debug|release) {
    TARGET = qyaml-cpp
    OBJECTS_DIR = $$OUT_PWD/.obj
    MOC_DIR = $$OUT_PWD/.moc
    RCC_DIR = $$OUT_PWD/.qrc
    UI_DIR = $$OUT_PWD/.ui
}

include(qyaml-cpp.pri)

#unix {
#    target.path = /usr/lib
#    INSTALLS += target
#}


unix|win32: LIBS += -lyaml-cpp
