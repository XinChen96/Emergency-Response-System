TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
QT += core
QT += sql

SOURCES += main.cpp \
    maincontroller.cpp \
    ../db/user_db.cpp \
    ../db/db_manager.cpp\
    ../users/civilian.cpp\
    ../users/simulation.cpp\
    ../db/simulation_db.cpp


HEADERS += \
    maincontroller.h\
    ../db/db_manager.h\
    ../db/user_db.h\
    ../db/db_manager.h\
    ../users/user.h\
    ../users/civilian.h\
    ../users/simulation.h\
    ../db/simulation_db.h

