TEMPLATE = app
CONFIG += console c++11
QT += core
QT += sql

SOURCES += main.cpp \
    db_manager.cpp \
    user_db.cpp \
    group_db.cpp \
    simulation_db.cpp\
    ../users/user.cpp\
    ../users/civilian.cpp\
    ../users/responder.cpp\
    ../users/planner.cpp\
    ../users/dbitem.cpp\
    ../users/simulation.cpp \
    ../users/emergency.cpp \
    emergency_db.cpp \
    ../users/response.cpp \
    response_db.cpp \
    notification_db.cpp \
    ../users/notification.cpp

HEADERS += \
    db_manager.h \
    user_db.h \
    group_db.h \
    simulation_db.h\
    ../users/roles.h\
    ../users/user.h \
    ../users/civilian.h\
    ../users/responder.h\
    ../users/planner.h\
    ../users/dbitem.h\
    ../users/simulation.h \
    ../users/emergency.h \
    emergency_db.h \
    ../users/response.h \
    response_db.h \
    notification_db.h \
    ../users/notification.h

SOURCES += ../googletest-master/googletest/src/gtest-all.cc

INCLUDEPATH +=  ../googletest-master                                   \
                ../googletest-master/googletest                        \
                ../googletest-master/googletest/include                \
                ../googletest-master/googletest/include/gtest

