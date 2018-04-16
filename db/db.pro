TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
QT += core
QT += sql

SOURCES += main.cpp \
    db_manager.cpp \
    user_db.cpp \
    group_db.cpp

HEADERS += \
    db_manager.h \
    user_db.h \
    group_db.h

SOURCES += ../googletest-master/googletest/src/gtest-all.cc

INCLUDEPATH +=  ../googletest-master                                   \
                ../googletest-master/googletest                        \
                ../googletest-master/googletest/include                \
                ../googletest-master/googletest/include/gtest

