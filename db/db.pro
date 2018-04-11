TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
QT += core                # this should be added
QT += sql                 # this should be added

SOURCES += main.cpp \
    db_manager.cpp \
    user_db.cpp \
    group_db.cpp

HEADERS += \
    db_manager.h \
    user_db.h \
    group_db.h
