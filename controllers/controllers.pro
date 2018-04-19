TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
QT += sql

SOURCES += main.cpp \
    maincontroller.cpp\
    ../db/db_manager.cpp\
    ../db/user_db.cpp\


HEADERS += \
    maincontroller.h\
    ../db/db_manager.h\
    ../db/user_db.h

