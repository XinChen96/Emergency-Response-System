TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
Qt += sql

SOURCES += main.cpp \
    user.cpp \
    civilian.cpp \
    dbitem.cpp \
    responder.cpp \
    planner.cpp

HEADERS += \
    user.h \
    civilian.h \
    dbitem.h \
    responder.h \
    planner.h \
    roles.h
