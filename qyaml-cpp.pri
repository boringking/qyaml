# ***************************************************************************
# Copyright (c) 2013-2019, Simon Meaden
# ***************************************************************************
#
# Simonsoft - QYaml-Cpp
# Config PRI File
#
# qyaml-cpp is a set of extensions to yaml-cpp to handle some common
# Qt 5 types such a QString, QPint and others.
#
# This code is licensed under the GPL Version 3.0
# ***************************************************************************

QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

INCLUDEPATH += $$PWD

SOURCES += \
    node.cpp \
    parse.cpp

HEADERS +=  \
    parse.h \
    collection.h \
    comment.h \
    emitter.h \
    node.h

DISTFILES += \
    qyaml-cpp.h \
    QYamlCpp
