QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

DEFINES += QT_DEPRECATED_WARNINGS

include(../../sources/Engine/Modules/Math/Math.pri)

SOURCES += \
        main.cpp \
        testsmatrix.cpp \
        testsvector.cpp

HEADERS += \
    testsmatrix.h \
    testsvector.h
