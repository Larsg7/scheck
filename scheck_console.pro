TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    src/main.cpp \
    src/dictionary.cpp

HEADERS += \
    inc/dictionary.h \
    inc/error.h \
    src/error.h
